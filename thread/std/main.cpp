// Copyright (c) 2022 std thread test
// thefist@126.com
// 2022/3/23 
// Official repository: https://github.com/thefistlei/web



#include "src/createThread.h"   
#include "src/atomic.h"  
#include "src/lockguard.h"  
#include "src/mutex.h"  
#include "src/conditionvariable.h"
#include "src/detach.h"
#include "src/getid.h"

int main() 
{  
    auto n = thread::hardware_concurrency();//获取cpu核心个数  
    cout << n << endl;
    
    //callOnce::test();
    //lockGuard::test();
    createThread::test(); 
    //mutex::test(); 
    //detach::test();
    //getid::test();
    
    //atomicTest::test(); 
}