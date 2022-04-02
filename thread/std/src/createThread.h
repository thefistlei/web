// Copyright (c) 2022 std thread test
// thefist@126.com
// 2022/3/23 
// Official repository: https://github.com/thefistlei/web


#pragma once

#ifndef CREATETHREAD_H
#define CREATETHREAD_H
  
#include <iostream> 
#include<thread>  
#include<chrono>  

using namespace std;  

namespace createThread
{
    namespace test1
    { 
        void fun1(int n)  //初始化构造函数  
        {  
            cout << "Thread " << n << " executing\n";  
            n += 10;  
            this_thread::sleep_for(chrono::milliseconds(10));  
        }  

        void fun2(int & n) //拷贝构造函数  
        {  
            cout << "Thread " << n << " executing\n";  
            n += 20;  
            this_thread::sleep_for(chrono::milliseconds(10));  
        }  

        int test()  
        {  
            int n = 0;  
            thread t1;               //t1是一个空thread  
            thread t2(fun1, n + 1);  //按照值传递  
            t2.join();  
            cout << "n=" << n << '\n';  
            n = 10;  
            thread t3(fun2, ref(n)); //引用  
            thread t4(move(t3));     //t4执行t3，t3不是thread  
            t4.join();  
            cout << "n=" << n << '\n';  
            return 0;  
        }   
    } 
 
    namespace test2
    { 
        void show()  
        {  
            cout << "hello cplusplus!" << endl;  
        }  

        int test()  
        {  
            //栈上  
            thread t1(show);   //根据函数初始化执行  
            thread t2(show);  
            thread t3(show);  

            //线程数组  
            thread th[3]{thread(show), thread(show), thread(show)};   

            //堆上  
            thread *pt1(new thread(show));  
            thread *pt2(new thread(show));  
            thread *pt3(new thread(show));  

            //线程指针数组  
            thread *pth(new thread[3]{thread(show), thread(show), thread(show)});  
            return 0;  
        }         
    } 

    namespace lambda
    { 
        void test() 
        {  
            auto fun = [](const char *str) {cout << str << endl; };  
            thread t1(fun, "hello world!");  
            thread t2(fun, "hello beijing!");   
            t1.join();
            t2.join();
        }
    }

    namespace variableParam
    {  
        #include<cstdarg>  
        
        int show(const char *fun, ...)  
        {  
            va_list ap;//指针  
            va_start(ap, fun);//开始  
            vprintf(fun, ap);//调用  
            va_end(ap);  
            return 0;  
        }  

        int test()  
        {  
            thread t1(show, "%s    %d    %c    %f", "hello world!", 100, 'A', 3.14159); 
            t1.join(); 
            return 0;  
        }  
    } 

    void test() 
    {  
        //test1::test(); 
        //test2::test(); 
        lambda::test(); 
        variableParam::test(); 
    } 
}

#endif // !CREATETHREAD_H