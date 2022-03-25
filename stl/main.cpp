// Copyright (c) 2022 stl test
// thefist@126.com
// 2022/3/25
// Official repository: https://github.com/thefistlei/web


#include <iostream>

#include "jjalloc.h"
#include "basetype.h"
#include "typecast.h"
#include "stdTest.h"
//#include "operatornew.h"
//#include "stdvisit.h"
#include "uniontest.h"


int main()
{ 
    jjalloc::test();
    mystl::test();
    //stdVisitTest::test();    
    //operatorNewTest::test();

    //stdTest::test();
    stdTest::test_integral_constant();

    myclass::typeCast::test();
    unionTest::test();

    std::cout << "Hello World!\n";
} 