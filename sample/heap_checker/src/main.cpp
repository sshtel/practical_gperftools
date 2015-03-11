#include <iostream>
#include "allocate_release.h"
#include <gperftools/heap-checker.h>
#include <assert.h>


int main(int argc, char *argv[]){

    std::cout << "start program" << std::endl;
    {

        HeapLeakChecker heap_checker1("test1");
        {
            allocate(1024*1024*4);
            release();
        }

        if(!heap_checker1.NoLeaks()) assert( NULL == "heap memory leak" );


        HeapLeakChecker heap_checker2("test2");
        {
            allocate(1024*1024*4);
            sleep(3);
        }

        if(!heap_checker2.NoLeaks()) assert( NULL == "heap memory leak2" ); 
    }
    std::cout << "return.." << std::endl;
    return 0;
}
