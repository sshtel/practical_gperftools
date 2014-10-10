# gperftools

APP_NAME = gperftools
APP_VERSION = 2.1
APP_DIR = $(APP_NAME)-$(APP_VERSION)
FILENAME = $(APP_DIR).tar.gz
SOURCE_URL = https://gperftools.googlecode.com/files/
#example : https://gperftools.googlecode.com/files/gperftools-2.1.tar.gz

PATCHES_LIST=""
#PATCHES_LIST = patches/PATCHES

INSTALL_DIR = $(shell pwd)/target





#### Toolchain ####
CXX = g++
CC = gcc


.PHONY: all clean unpack apply-patches build

all: build 
clean:
	@rm -rf $(APP_DIR)
	@rm -rf $(INSTALL_DIR)
	@rm -rf target

######################################################################

build: apply-patches
	@cd $(APP_DIR) && ./configure \
		CC=$(CC) CXX=$(CXX) \
	    --build=i386-linux \
	    --host=i386-linux  \
		--enable-frame-pointers \
		--disable-shared \
		--enable-static \
		--disable-dependency-tracking \
		--prefix=$(INSTALL_DIR) \
		ac_cv_func_mmap_fixed_mapped=yes \
		&& make && make install

######################################################################

apply-patches: unpack
	@for P in `cat $(PATCHES_LIST)`; do \
	  if [ -f patches/$$P ]; then \
	    echo "*** applying $$P..."; \
	    (cd $(APP_DIR); patch -p1 < ../patches/$$P) || exit 1; \
	  else \
	    echo "*** $$P not found, skipping..."; \
	  fi \
	done

######################################################################

unpack: download
	@-rm -rf $(APP_DIR)
	@(gzip -dcf $(FILENAME) | tar xvf -) || (rm -rf $(APP_DIR); false)

download:
	wget -v -O $(FILENAME) $(SOURCE_URL)/$(FILENAME)

######################################################################

