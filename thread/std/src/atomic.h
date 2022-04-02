// Copyright (c) 2022 std thread test
// thefist@126.com
// 2022/3/23 
// Official repository: https://github.com/thefistlei/web

#pragma once

#ifndef ATOMIC_H
#define ATOMIC_H
  
#include <thread>
#include <atomic>
#include <stdio.h>
#include <iostream>
#include <list>




namespace atomicTest
{
    std::atomic<bool> bIsReady(false);
    std::atomic<int> iCount(10);

    void threadfun1()
    {
        if (!bIsReady) {
            std::this_thread::yield();
        }
        while (iCount > 0)
        {
            printf("iCount:%d\r\n", iCount--);
        }
    } 

    void test() 
    {  
        std::list<std::thread> lstThread;
        for (int i = 0; i < 10; ++i)
        {
            lstThread.push_back(std::thread(threadfun1));
        }

        for (auto& th : lstThread)
        {
            th.join();
        }
    } 
}

#endif // !ATOMIC_H