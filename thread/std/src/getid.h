// Copyright (c) 2022 std thread test
// thefist@126.com
// 2022/3/23 
// Official repository: https://github.com/thefistlei/web

#pragma once

#ifndef GETID_H
#define GETID_H

#include <iostream>
#include <thread>
#include <mutex>
#include <stdlib.h>
 
 
using namespace std;  

namespace getid
{ 
    std::mutex m;
    int cnt = 10;

    void thread1() {
        while (cnt > 5){
            lock_guard<std::mutex> lockGuard(m);
            if (cnt > 0) {
                --cnt;
                cout << cnt << endl;
            }
        }
    }

    void thread2() {
        while (cnt > 0) {
            lock_guard<std::mutex> lockGuard(m);
            if (cnt > 0) {
                cnt -= 10;
                cout << cnt << endl;
            }
        }
    }
 
    
    int test(void)
    {
        thread th1(thread1);   //实例化一个线程对象th1，该线程开始执行
        thread th2(thread2);
        //thread th3(th1);       //拷贝构造函数被删除

        cout << "******" << "th1 id: " << th1.get_id() << "******" << endl;
        cout << "******" << "th2 id: " << th2.get_id() << "******" << endl;
        th1.swap(th2);
        cout << "******" << "th1 id: " << th1.get_id() << "******" << endl;
        cout << "******" << "th2 id: " << th2.get_id() << "******" << endl;
        th1.join();
        th2.join();
 
        return 0;
    } 
    
}

#endif // !GETID_H