// Copyright (c) 2022 stl test
// thefist@126.com
// 2022/3/25
// Official repository: https://github.com/thefistlei/web

#pragma once

#ifndef BASE_TYPE_H
#define BASE_TYPE_H

#include <iostream>

namespace mystl
{
	template <typename T, bool val>
	struct AClass
	{
		AClass() //构造函数
		{
			std::cout << "AClass::AClass()执行了" << std::endl;

			//if (val) 
			if constexpr (val)
			{
				T tmpa = 15;
				std::cout << "int " << tmpa << std::endl;
			}
			else
			{
				T tmpa = "abc"; //int tmpa = "abc";   
				std::cout << "string " << tmpa << std::endl;
			}
		}
	};

	void test(){
		AClass<int, true> tmpobj1;
		AClass<std::string, false> tmpobj2;
		//AClass<std::string, true> tmpobj3;//error 初始化”: 无法从“int”转换为“std::basic_string<char,std::char_traits<char>,std::allocator<char>>”
	}
}

#endif // !BASE_TYPE_H