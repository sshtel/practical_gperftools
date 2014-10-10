
USE_GPERFTOOLS = yes

USE_GPERF_PROFILING = yes

CXX=g++
#CXX=arm-none-linux-gnueabi-g++


#### Objects ####

SRC_DIR = ./src
BIN_DIR = ./bin

TEST001_DIR = $(SRC_DIR)/test001
TEST001_OUTPUT = $(BIN_DIR)/test001
TEST001_OBJ += $(TEST001_DIR)/main.cpp
TEST001_OBJ += $(TEST001_DIR)/test1.cpp

TEST002_DIR = $(SRC_DIR)/test002
TEST002_OUTPUT = $(BIN_DIR)/test002
TEST002_OBJ += $(TEST002_DIR)/main.cpp



ifeq ($(USE_GPERFTOOLS), yes)
    
DEFINES += -D_USE_GPERFTOOLS
GPERF_DIR = $(PWD)/../gperftools
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


test001:
	$(CXX) $(CFLAGS) $(LFLAGS) $(TEST001_OBJ) $(GPERF_STATIC_LIB) $(DEFINES) -o $(TEST001_OUTPUT)

test002:
	$(CXX) $(CFLAGS) $(LFLAGS) $(TEST002_OBJ) $(GPERF_STATIC_LIB) $(DEFINES) -o $(TEST002_OUTPUT)


all: test001 test002


clean:
	rm -rf $(TEST001_OUTPUT)
	rm -rf $(TEST002_OUTPUT)
