// Copyright (c) 2022 stl test
// thefist@126.com
// 2022/3/25
// Official repository: https://github.com/thefistlei/web

#pragma once

#ifndef JJALLOC_H
#define JJALLOC_H

#include<new>//for placement new
#include<cstdlib>//for ptrdiff_t,size_t
#include<climits>//for UINT_MAX
#include<iostream>//for cerr
#include <new>    // std::set_new_handler

#include <sstream>

#include <vector>

using namespace std;

namespace jjalloc
{  

	namespace JJ
	{ 
		template<class T>
		inline T* _allocate(ptrdiff_t size,T*){   
			//当operator new申请一个内存失败的时候.
			//如果存在客户指定的处理函数，则调用处理函数（new_handler），如果不存在则抛出一个异常
			//参数为0，则抛出异常
			std::set_new_handler(0);
			T* tmp=(T*)(::operator new((size_t)(size*sizeof(T))));
			if(tmp==0){
				cerr<<"out of memory"<<endl;
				exit(1);
			}
			return tmp;
		}

		template<class T>
		inline void _deallocate(T* buffer){
			::operator delete(buffer);
		}

		template<class T1,class T2>
		inline void _construct(T1*p,const T2& value){
			new(p) T1(value);
		}
		template<class T>
		inline void _destroy(T* ptr){
			ptr->~T();
		}
	
		template<class T>
		class allocator{
		public:
			typedef T           value_type;
			typedef T*          pointer;
			typedef const T*    const_pointer;
			typedef T&          reference;
			typedef const T&    const_reference;
			typedef size_t      size_type;
			typedef ptrdiff_t   difference_type;
		
			//rebind allocator of type U
			template<class U>
			struct rebind{
				typedef allocator<U> other;
			};
		
			pointer allocate(size_type n,const void* hint=0){
				std::cout << "allocate " << std::endl;

				return _allocate((difference_type)n,(pointer)0);
			}
		
			void deallocate(pointer p,size_type n) {_deallocate(p);}
			
			void construct(pointer p,const T& value){
				_construct(p,value);
			}
			
			void destroy(pointer p){ 
				std::cout << "destroy " << *p << std::endl;
				_destroy(p);
			}
		
			pointer address(reference x) { 
				return (pointer)&x;
			}
		
			const_pointer const_address(const_reference x) { 
				return (const_pointer)&x;
			}

			size_type max_size() const{
				return size_type(UINT_MAX/sizeof(T));
			}
		};
	
	} //end of namespace JJ 

	
	int test(){ 
		std::vector<int, JJ::allocator<int> > v = {0,1};
		return 0;
	}
}

#endif // !JJALLOC_H