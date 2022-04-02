// Copyright (c) 2022 std thread test
// thefist@126.com
// 2022/3/23 
// Official repository: https://github.com/thefistlei/web

#pragma once

#ifndef LOCKGUARD_H
#define LOCKGUARD_H

#include <iostream>
#include <thread>
#include <mutex>
#include <stdlib.h>
 
namespace lockGuard
{ 
    int cnt = 20;
    std::mutex m;
    void t1()
    {
        while (cnt > 0)
        {    
            std::lock_guard<std::mutex> lockGuard(m);
        // std::m.lock();
            if (cnt > 0)
            {
                //sleep(1);
                --cnt;
                std::cout << "t1 " << cnt << std::endl;
            }
        // std::m.unlock();
            
        }
    }
    void t2()
    {
        while (cnt > 0)
        {
            std::lock_guard<std::mutex> lockGuard(m);
            // std::m.lock();
            if (cnt > 0)
            {
                --cnt;
                std::cout << "t2 " << cnt << std::endl;
            }
            // std::m.unlock();
        }
    }
    
    int test(void)
    {
        std::thread th1(t1);
        std::thread th2(t2);
    
        th1.join();    //等待t1退出
        th2.join();    //等待t2退出
    
        std::cout << "test" << std::endl;
    
        return 0;
    } 
    
}

#endif // !LOCKGUARD_H