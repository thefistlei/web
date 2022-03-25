// Copyright (c) 2022 boost thread test
// thefist@126.com
// 2022/3/23 
// Official repository: https://github.com/thefistlei/web


#pragma once

#ifndef CALLONCE_H
#define CALLONCE_H
 
#include <boost/thread.hpp> 
#include <iostream> 


namespace callOnce
{
    int i = 0;
    int j = 0;
    boost::once_flag flag = BOOST_ONCE_INIT;

    void Init()
    {
        ++i;
    }

    void ThreadFunc()
    {
        boost::call_once(&Init, flag);
        ++j;
    }

    int test()
    {
        boost::thread thrd1(&ThreadFunc);
        boost::thread thrd2(&ThreadFunc);
        thrd1.join();
        thrd2.join();

        std::cout<<i<<std::endl;
        std::cout<<j<<std::endl;
        return 0;
    } 
}

#endif // !CALLONCE_H