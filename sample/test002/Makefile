
USE_GPERFTOOLS = yes

USE_GPERF_PROFILING = yes

CXX=g++
#CXX=arm-none-linux-gnueabi-g++


#### Objects ####

SRC_DIR = ./src
BIN_DIR = ./bin

OUTPUT = $(BIN_DIR)/test002
OBJS += $(SRC_DIR)/main.cpp
OBJS += $(SRC_DIR)/allocate_release.cpp


ifeq ($(USE_GPERFTOOLS), yes)
    
DEFINES += -D_USE_GPERFTOOLS
GPERF_DIR = $(PWD)/../../gperftools
CFLAGS += -I$(GPERF_DIR)/target/include
LFLAGS += -L$(PWD)/gperftools/target/lib

ifeq ($(USE_GPERF_PROFILING), yes)
GPERF_STATIC_LIB = $(GPERF_DIR)/target/lib/libtcmalloc_and_profiler.a
else
GPERF_STATIC_LIB = $(GPERF_DIR)/target/lib/libtcmalloc.a
endif

else  ####NO GPERFTOOLS
GPERF_DIR = 
GPERF_STATIC_LIB = 
CFLAGS += 
endif

CFLAGS += -pthread
#LFLAGS += -lrt


#CFLAGS += -fno-builtin-malloc -fno-builtin-calloc -fno-builtin-realloc -fno-builtin-free 

all:
	$(CXX) $(CFLAGS) $(LFLAGS) $(OBJS) $(GPERF_STATIC_LIB) $(DEFINES) -o $(OUTPUT)



clean:
	rm -rf $(OUTPUT)
