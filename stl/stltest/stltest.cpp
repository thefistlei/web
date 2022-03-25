// stltest.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#include "basetype.h"
#include "typecast.h"
#include "stdTest.h"
#include "operatornew.h"
#include "stdVisit.h"

#include "sortTest.h"


using namespace mystl;

using namespace myclass;

using namespace stdTest;

union _Obj {
    union _Obj* _M_free_list_link;
    char _M_client_data[1];    /* The client sees this.        */
};

int main()
{
    sortTest::test();

    stdVisitTest::test();
    //operatorNewTest::test1();
    operatorNewTest::test2();

    //stdTest::test();
    stdTest::test_integral_constant();
    AClass<int, true> tmpobj1;
    AClass<std::string, false> tmpobj2;

    //AClass<std::string, true> tmpobj3;//error 初始化”: 无法从“int”转换为“std::basic_string<char,std::char_traits<char>,std::allocator<char>>”

    typeCast::test();

    _Obj c;
    int n = sizeof(_Obj);
    n = sizeof(c);
    std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
