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
}

#endif // !BASE_TYPE_H