#pragma once

#ifndef OPERATORNEW_H
#define OPERATORNEW_H

void* ::operator new(size_t size)
{
   // std::cout << "call global operator new" << std::endl;
    return malloc(size);
}


namespace operatorNewTest
{
    class A
    {
    public:
        A()
        {
            std::cout << "call A constructor" << std::endl;
        }

        ~A()
        {
            std::cout << "call A destructor" << std::endl;
        }
        void* operator new(size_t size)
        {
            std::cout << "call A::operator new" << std::endl;
            return malloc(size);
        }

        void* operator new(size_t size, const std::nothrow_t& nothrow_value)
        {
            std::cout << "call A::operator new nothrow" << std::endl;
            return malloc(size);
        }
    };

    void test1()
    {
        A* p1 = new A;
        delete p1;

        A* p2 = new(std::nothrow) A;
        delete p2; 
    }

    class B
    {
    public:
        B()
        {
            std::cout << "call B constructor" << std::endl;
        }

        ~B()
        {
            std::cout << "call B destructor" << std::endl;
        } 
    };


    void test2()
    {
        B* p1 = new B;
        delete p1; 
    }
};

#endif // !OPERATORNEW_H