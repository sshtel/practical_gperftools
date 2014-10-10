#include <iostream>


#ifdef _USE_GPERFTOOLS
#include <gperftools/heap-checker.h>
#include <google/profiler.h>
#include <google/heap-profiler.h>
#include <google/heap-checker.h>
#endif

#include "allocate_release.h"


int main(int argc, char *argv[]){

//    ::ProfilerStart("test002.pprof");
//    ::HeapProfilerStart("test002.hprof");

    std::cout << "start program" << std::endl;
    //HeapLeakChecker heap_checker("test_foo");
    {
        while(1)
        {
            std::cout << "ready..." << std::endl;
            sleep(20);
            std::cout << "go..." << std::endl;

            allocate(1024*1024*128);
            sleep(3);
            release();
            sleep(3);

            for(int i=0; i<10; i++){
                allocate(1024*1024*4);
                sleep(3);
            }
            
            for(int i=0; i<10; i++){
                release();
                sleep(3);
            }
        }
    }

    /*
    if (!heap_checker.NoLeaks()) 
    { 
            std::cout << "leak!!!!!!! \n" << std::endl;
    }
    */

    std::cout << "return.." << std::endl;


//    HeapLeakChecker::NoGlobalLeaks();
//    ::HeapProfilerStop();
//    ::ProfilerFlush();
//    ::ProfilerStop();

    return 0;
}
