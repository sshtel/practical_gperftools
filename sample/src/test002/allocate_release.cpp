#include <iostream>
#include <string.h>
#include "allocate_release.h"



void allocateAndRelease(int size){
    char *p = new char[size];
    
    delete []p;

}


#define SIZE 20

char *g_p[SIZE];
int tail_idx = -1;

void allocate(int size){
    if(tail_idx >= SIZE) {
        std::cout << "array full" << tail_idx << std::endl;
        return;
    }
    tail_idx++;
    std::cout << "allocate idx:" << tail_idx << std::endl;
    g_p[tail_idx] = new char[size];
    if(g_p[tail_idx]) {
        std::cout << "allocate OK" << std::endl;
    }
    memset(g_p[tail_idx], 0, size);
}

void release(){
    if(tail_idx < 0) {
        std::cout << "array empty" << tail_idx << std::endl;
        return;
    }
    std::cout << "release idx:" << tail_idx << std::endl;
    if(g_p[tail_idx]) {
        std::cout << "release OK" << std::endl;
        delete []g_p[tail_idx];
    }
    tail_idx--;
}
