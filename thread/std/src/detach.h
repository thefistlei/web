// Copyright (c) 2022 std thread test
// thefist@126.com
// 2022/3/23 
// Official repository: https://github.com/thefistlei/web

#pragma once

#ifndef DETACH_H
#define DETACH_H

#include <iostream>
#include <thread> 
#include <stdlib.h>
 
namespace detach
{ 
    namespace test1
    { 
        void pause_thread(int n) 
        {
            std::this_thread::sleep_for (std::chrono::seconds(n));
            std::cout << "pause of " << n << " seconds ended\n";
        }
        
        int test() 
        {
            std::cout << "Spawning and detaching 3 threads...\n";
            std::thread (pause_thread,1).detach();
            std::thread (pause_thread,2).detach();
            std::thread (pause_thread,3).detach();
            std::cout << "Done spawning threads.\n";

            std::cout << "(the main thread will now pause for 5 seconds)\n";
            // give the detached threads time to finish (but not guaranteed!):
            pause_thread(5);
            return 0;
        }
    }
    
    namespace test2
    { 
        void thread1() {
            for(int i=0;i<20;++i)
                cout << "thread1... " << i << endl;
        }

        void thread2() {
            for (int i = 0; i<20; ++i)
                cout << "thread2... " << i << endl;
        }

        int test() {
            thread th1(thread1);   //实例化一个线程对象th1，该线程开始执行
            thread th2(thread2);
            th1.detach();
            th2.detach();
            cout << "main..." << endl;
            return 0;
        }
    }

    int test(void)
    {
       // test1::test();
        test2::test();

        std::cout << "detach test" << std::endl;    
        return 0;
    } 
}

#endif // !DETACH_H