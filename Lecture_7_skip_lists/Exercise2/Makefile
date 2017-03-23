#Write source and Executables here
MODULES=main
EXECUTABLES=main


CXXFLAGS=-I. -Wall -pedantic -ansi -std=c++11 -pthread
INCLUDES=-L./lib -lpthread
BUILD_DIR=build
BIN_DIR=bin


#For building on host with C++
ifeq (${ARCH},host++)
CXX=g++
BUILD_DIR=build/host
BIN_DIR=bin/host
endif

#For building for host with C
ifeq (${ARCH},host)
CXX=gcc
BUILD_DIR=build/host
BIN_DIR=bin/host
endif

#for building for DEVKIT8000 with C
ifeq (${ARCH},target)
CXX=arm-devkit-gcc
BUILD_DIR=build/target
BIN_DIR=bin/target
endif

#for building for DEVKIT8000 with C++
ifeq (${ARCH},target++)
CXX=arm-devkit-g++
BUILD_DIR=build/target
BIN_DIR=bin/target
endif

SOURCE=$(MODULES:=.cpp)
OBJECTS=$(MODULES:=.o)
DEPS=$(MODULES:=.d)

#adds the dir location to all .d and .o files
CONTROL_OBJECTS=$(addprefix ${BUILD_DIR}/,$(OBJECTS))
DEPDIR=$(addprefix ${BUILD_DIR}/,$(DEPS))

all:${BIN_DIR}/$(EXECUTABLES)

#puts the executeable file in the bin dir, and is depended on objects and deps
${BIN_DIR}/$(EXECUTABLES): $(DEPDIR) ${CONTROL_OBJECTS}
	@mkdir -p ${BIN_DIR} 
	$(CXX) $(CONTROL_OBJECTS) -o $@ $(INCLUDES)


#builder for the .o files
${BUILD_DIR}/%.o: %.cpp
	@mkdir -p ${BUILD_DIR} 
	$(CXX) -c $(CXXFLAGS) $< -o $@

#builder for the .d files
${BUILD_DIR}/%.d: %.cpp
	@mkdir -p ${BUILD_DIR} 
	$(CXX) -MT${BUILD_DIR}/$(@:.d=.o) -MM $(CXXFLAGS) $^ > $@


ifneq ($(MAKECMDGOALS),clean)
-include $(DEPDIR)
endif

.PHONY:clean help
clean:
	@rm -rf build bin
help:
	@echo make Runs Standers make.
	@echo make ARCH=host Saves files in a host directory.
	@echo make ARCH=target Compiles the program for the DEVKIT8000.
	@echo make ARCH=host++ Save file in a host directory in C++
	@echo make ARCH=target++ Save file in a host directory in C++
