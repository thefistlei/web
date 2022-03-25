// Copyright (c) 2022 stl test
// thefist@126.com
// 2022/3/25
// Official repository: https://github.com/thefistlei/web

#pragma once

#ifndef UNIONTEST_H
#define UNIONTEST_H


namespace unionTest
{
    union _Obj {
        union _Obj* _M_free_list_link;
        char _M_client_data[1];    /* The client sees this.   */
    };

    void test(){ 
        _Obj c;
        int n = sizeof(_Obj);
        n = sizeof(c);
        std::cout << n << std::endl;
    }
};

#endif // !UNIONTEST_H
