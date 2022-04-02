// Copyright (c) 2022 std thread test
// thefist@126.com
// 2022/3/23 
// Official repository: https://github.com/thefistlei/web

#pragma once

#ifndef MUTEX_H
#define MUTEX_H

#include <iostream>
#include <thread>
#include <mutex>
#include <stdlib.h>
 
namespace mutex
{ 
    int cnt = 20;
    std::mutex m;
    void t1()
    {
        while (cnt > 0)
        {     
            m.lock();
            if (cnt > 0)
            {
                //sleep(1);
                --cnt;
                std::cout << "t1 " << cnt << std::endl;
            }
            m.unlock();            
        }
    }
    void t2()
    {
        while (cnt > 0)
        {
            m.lock();
            if (cnt > 0)
            {
                --cnt;
                std::cout << "t2 " << cnt << std::endl;
            }
            m.unlock();
        }
    }
    
    int test(void)
    {
        std::thread th1(t1);
        std::thread th2(t2);
    
        th1.join();    //等待t1退出
        th2.join();    //等待t2退出
    
        std::cout << "mutex test" << std::endl;
    
        return 0;
    } 
    
}

#endif // !MUTEX_H