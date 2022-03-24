// Copyright (c) 2022 boost thread test
// thefist@126.com
// 2022/3/23 
// Official repository: https://github.com/thefistlei/algorithm 


#pragma once

#ifndef KTH_H
#define KTH_H
 
#include <boost/thread.hpp> 
#include <iostream> 


namespace createThread
{
    namespace test1
    {
        void wait(int seconds) 
        { 
            boost::this_thread::sleep(boost::posix_time::seconds(seconds)); 
        } 

        void callable() 
        { 
            for (int i = 0; i < 5; ++i) 
            { 
                wait(1); 
                std::cout << i << std::endl; 
            } 
        } 

        void test(){
            boost::thread t(&callable); 
            t.join(); 
        }
    }

    namespace test2
    {
        void wait(int seconds) 
        { 
            boost::this_thread::sleep(boost::posix_time::seconds(seconds)); 
        } 

        struct callable
        {
            void operator()() {  
                for (int i = 0; i < 5; ++i) 
                { 
                    wait(1); 
                    std::cout << i << std::endl; 
                } 
            }
        };

        boost::thread copies_are_safe()
        {
            callable x;
            return boost::thread(x);
        } // x is destroyed, but the newly-created thread has a copy, so this is OK

        void test(){
            boost::thread t = copies_are_safe(); 
            t.join(); 
        }
    }

    namespace test3
    {
        void wait(int seconds) 
        { 
            boost::this_thread::sleep(boost::posix_time::seconds(seconds)); 
        } 

        struct callable
        {
            void operator()(int n) {  
                for (int i = 0; i < n; ++i) 
                { 
                    wait(1); 
                    std::cout << i << std::endl; 
                } 
            }
        };

        boost::thread copies_are_safe()
        {
            callable x;
            return boost::thread(x, 10);
        } // x is destroyed, but the newly-created thread has a copy, so this is OK

        void test(){
            boost::thread t = copies_are_safe(); 
            t.join(); 
        }
    }

#include <boost/bind.hpp>

    namespace bindtest
    {
        class bind{ 
        public: 
            void testFunc(int i) 
            {
                std::cout << "i=" << i <<std::endl; 
            }
        }; 
  
        class _bind
        {
        public:
            void testFunc(int i) 
            {
                std::cout << "i=" << i <<std::endl; 
            }
            void test()
            {
                boost::function0< void> f =  boost::bind(&_bind::testFunc, this, 5);
                //或boost::function<void()> f = boost::bind(&_bind::testFunc, this, 5);
                boost::thread thrd(f);
                thrd.join();
            } 
        }; 

        void test(){ 
            bind tb; 
            boost::thread t(boost::bind(&bind::testFunc, &tb, 100));
            t.join(); 

            _bind _tb; 
             _tb.test(); 
        } 
    } 

    namespace classIn
    {
        class HelloWorld
        {
        public:
            static void hello()
            {
                std::cout << "Hello world, I''m a thread!" << std::endl;
            }
            static void start()
            { 
                boost::thread thrd( hello );
                thrd.join();
            } 
        }; 
  
        void test() 
        { 
            HelloWorld::start(); 
        }
    }
 
    namespace classSingleon
    {
        class HelloWorld
        {
        public:
            void hello()
            {
                std::cout << "Hello world, I''m a thread!" << std::endl;
            }
            static void start()
            {
                boost::thread thrd( boost::bind(&HelloWorld::hello,&HelloWorld::getInstance() ) ) ;
                thrd.join();
            }
            static HelloWorld& getInstance()
            {
                if ( !instance )
                    instance = new HelloWorld;
                return *instance;
            }
        private: 
            HelloWorld(){}
            static HelloWorld* instance; 
        }; 

        HelloWorld* HelloWorld::instance = nullptr; 
        int test()
        {
            HelloWorld::start();
            return 0; 
        }
    }

    void test() 
    { 
        //test1::test();
        //test2::test();
        //test3::test();
        bindtest::test();
        classSingleon::test();
        //classIn::test();
    } 
}

#endif // !KTH_H