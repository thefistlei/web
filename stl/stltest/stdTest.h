#pragma once

#ifndef STDTEST_H
#define STDTEST_H

// enable_if example: two ways of using enable_if
#include <iostream>
#include <type_traits>

namespace stdTest
{

    // 1. the return type (bool) is only valid if T is an integral type:
    template <class T>
    typename std::enable_if<std::is_integral<T>::value, bool>::type
        is_odd(T i) { return bool(i % 2); }

    // 2. the second template argument is only valid if T is an integral type:
    template < class T,
        class = typename std::enable_if<std::is_integral<T>::value>::type>
        bool is_even(T i) { return !bool(i % 2); }

    // 3. the second template argument is only valid if T is an float type:
    template < class T,
        class = typename std::enable_if<std::is_floating_point<T>::value>::type>
        int getInt(T f) { 
        return static_cast<int>(f); 
    }


    template <class T, T v>
    struct m_integral_constant {
        static constexpr T value = v;
        typedef T value_type;
        typedef m_integral_constant<T, v> type;
        constexpr operator T() const noexcept {
            std::cout << "T() " << std::endl;

            return v; 
        }

        constexpr T operator()() const noexcept {
            std::cout << "operator() " <<  std::endl;
            return v; 
        }
    };

    template <unsigned n>
    struct factorial : m_integral_constant<int, n* factorial<n - 1>::value>
    {
    };

    template <>
    struct factorial<0> : m_integral_constant<int, 1> {
    };



    int test() {

        short int i = 1;    // code does not compile if type of i is not integral

        std::cout << std::boolalpha;
        std::cout << "get int: " << getInt(4.5f) << std::endl;

        std::cout << "i is odd: " << is_odd(i) << std::endl;
        std::cout << "i is even: " << is_even(i) << std::endl;

        return 0;
    }

    void test_integral_constant() {
        std::true_type b;
        std::cout << b << std::endl;
        std::cout << std::true_type() << std::endl;

        int i = factorial<5>();
        i = factorial<3>()();

        std::cout << factorial<5>::value << std::endl;  // constexpr (no calculations on runtime) 
    }
}

#endif // !STDTEST_H