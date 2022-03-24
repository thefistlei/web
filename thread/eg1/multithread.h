// Copyright (c) 2022 boost thread test
// thefist@126.com
// 2022/3/23 
// Official repository: https://github.com/thefistlei/algorithm 


#pragma once

#ifndef MULTITHREAD_H
#define MULTITHREAD_H
 
#include <boost/thread.hpp> 
#include <iostream>  
#include <unistd.h>

namespace multithread
{
    void helloA() 
    { 
        std::cout << "I'm thread A !  --- Start " << std::endl; 
        sleep(5);
        std::cout << "I'm thread A !  --- OVER " << std::endl; 
    } 
 
    void helloB() 
    { 
        std::cout << "I'm thread B !  --- Start " << std::endl; 
        sleep(10);
        std::cout << "I'm thread B !  --- OVER " << std::endl; 
    } 
  
    int test()
    {
        boost::thread thrdA(&helloA);
        boost::thread thrdB(&helloB);  
        thrdA.join();
        thrdB.join(); 
        // join() 的作用是让主进程等待子线程执行完毕后再继续执行。
        // 否则会不检查子线程执行状况，直接退出了。
        return 0;  
    } 
}

#endif // !MULTITHREAD_H