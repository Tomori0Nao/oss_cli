SHELL := /bin/sh

SOURCEDIR := src

TARGETDIR := obj

TARGET := test

SOURCE := $(shell find $(SOURCEDIR) -name '*.cpp' -or -name '*.c' -or -name '*.s')

OBJ := ${patsubst %.cpp, %.o, ${SOURCE}}

CFLAGS := -std=c++14 -fno-rtti -lalibabacloud-oss-cpp-sdk -lcurl -lcrypto -lpthread -march=haswell
CC = g++

INCLUDES = ${addprefix -I,${shell find ${SOURCEDIR} -type d}}

LIBS = -lm 

${TARGET}: ${OBJ}
	echo ${OBJ}
	echo ${SOURCE}
	echo ${SOURCEDIR}
	${CC} -O src/main/main.o -o ${TARGETDIR}/${TARGET} 
	
.PHONY: clean
clean:
	-rm -f ${TARGETDIR}/* ${OBJ}
	
%.o: %.cpp
	${CC} $< ${CFLAGS} ${INCLUDES} -c -o $@
