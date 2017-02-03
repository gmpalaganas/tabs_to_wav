CC = g++
CFLAGS = -Wall -std=c++14
INCLUDES = -Isrc/utils -I/src/wav

BUILDDIR = build/utils

MKDIR = mkdir -p

OBJS = build/main.o \
	   build/utils/binary_utils.o \
	   build/utils/sound_utils.o

all: directories bin/main
	@echo Done

bin/main: $(OBJS) 
	@echo Building $@ 
	@$(CC) -o $@ $(CFLAGS) $(INCLUDES) $^ 

build/main.o: src/main.cpp
	@echo Building $@
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

build/utils/binary_utils.o: src/utils/binary_utils.cpp
	@echo Building $@
	@$(CC) $(CFLAGS) -c $< -o $@

build/utils/sound_utils.o: src/utils/sound_utils.cpp
	@echo Building $@
	@$(CC) $(CFLAGS) -c $< -o $@

directories:
	@echo Making build directories
	@$(MKDIR) $(BUILDDIR)

cleanup:
	@echo Cleaning up...
	@rm -r build/*
	@rm bin/*
	@echo Done
