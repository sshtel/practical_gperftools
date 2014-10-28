#include <iostream>

#include "allocate_release.h"


int main(int argc, char *argv[]){

    std::cout << "start program" << std::endl;
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
    std::cout << "return.." << std::endl;
    return 0;
}
