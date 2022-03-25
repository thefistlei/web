// Copyright (c) 2022 stl test
// thefist@126.com
// 2022/3/25
// Official repository: https://github.com/thefistlei/web

#pragma once

#ifndef TYPECAST_H
#define TYPECAST_H

#include <iostream>

#include <sstream>

namespace myclass
{ 
	struct typeCast
	{
		typeCast(double f):m_real(f)
		{  
		}    
		
		//类型转换函数
		operator double() const {  
			std::cout << "double() " << std::endl; 

			return m_real; 
		}   

		//类型转换函数
		operator bool() const { 
			std::cout << "bool() " << std::endl;

			if(m_real > 0)
				return true;

			return false;
		}

		//类型转换函数
		operator int() const {
			std::cout << "int() " << std::endl;

			return static_cast<int>(m_real); 
		}

		//类型转换函数
		operator std::string() const {

			std::cout << "string() " << std::endl;

			std::stringstream ss;
			ss << m_real;
			return ss.str() + "t";
		}

	private:
		double m_real;   

	public:
		static void test()
		{
			typeCast c1(24.6f);
			double f = c1;  //相当于 double f = Complex::operator double(&c1);
			std::cout << "f = " << f << std::endl;

			//f = 12.5 + c1 + 6;  //相当于 f = 12.5 + Complex::operator double(&c1) + 6;
			//std::cout << "f = " << f << std::endl;

			int i = c1;   
			std::cout << "i = " << i << std::endl;

			bool b = c1;
			std::cout << "b = " << b << std::endl;

			std::string s = c1; 
			std::cout << "s = " << s << std::endl;
		}
	};
}

#endif // !TYPECAST_H