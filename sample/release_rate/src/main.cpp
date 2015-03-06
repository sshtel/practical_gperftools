#include <iostream>


#ifdef _USE_GPERFTOOLS
#include <gperftools/tcmalloc.h>
#include <gperftools/malloc_extension.h>
#endif

#include "allocate_release.h"


int main(int argc, char *argv[]){

    std::cout << "start program" << std::endl;
    {
        std::cout << "ready..." << std::endl;
        sleep(2);
        std::cout << "go..." << std::endl;
        char buffer[1024];

        std::cout << "Current memory release rate : " << MallocExtension::instance()->GetMemoryReleaseRate() << std::endl;
        // you can use this function to set tcmalloc release rate
        MallocExtension::instance()->SetMemoryReleaseRate(10.0); 

        while(1)
        {
            MallocExtension::instance()->GetStats(buffer, 1024);
            std::cout << buffer << std::endl;
            //tc_malloc_stats();
            allocate(1024*1024*64);
            MallocExtension::instance()->GetStats(buffer, 1024);
            std::cout << buffer << std::endl;
            sleep(30);
            release();
            MallocExtension::instance()->GetStats(buffer, 1024);
            std::cout << buffer << std::endl;
            sleep(30);

        }
    }

    std::cout << "return.." << std::endl;

    return 0;
}
