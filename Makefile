
.PHONY:all,true-all
.DEFAULT:all

all:true-all

BIN?=bin
TARGETS=
CFLAGS+=-fpermissive -Wall -Wextra -Wpedantic -Wfloat-equal -Wformat-nonliteral -Wformat-security -Wformat-y2k -Wformat=2 -Wimport -Winvalid-pch -Wmissing-declarations -Wmissing-field-initializers -Wmissing-format-attribute -Wmissing-include-dirs -Wmissing-noreturn -Wpacked -Wpointer-arith -Wredundant-decls -Wstack-protector -Wundef -Wwrite-strings
CFLAGS+=-Wshadow -Wconversion -Werror 
CFLAGS+=-O0 -g3
CFLAGS+=-std=c++17
INCLUDES=-I./include -I./dependancies
LDFLAGS+=-fsanitize=undefined,address
CFLAGS+=-fsanitize=undefined,address
UNAME_S := $(shell uname -s)
LINUX_GL_LIBS = -lGL

CXXFLAGS = -std=c++11 
CXXFLAGS += -g -Wall -Wformat
LIBS =

##---------------------------------------------------------------------
## OPENGL ES
##---------------------------------------------------------------------

## This assumes a GL ES library available in the system, e.g. libGLESv2.so
# CXXFLAGS += -DIMGUI_IMPL_OPENGL_ES2
# LINUX_GL_LIBS = -lGLESv2

##---------------------------------------------------------------------
## BUILD FLAGS PER PLATFORM
##---------------------------------------------------------------------

ifeq ($(UNAME_S), Linux) #LINUX
	ECHO_MESSAGE = "Linux"
	LIBS += $(LINUX_GL_LIBS) `pkg-config --static --libs glfw3`

	CXXFLAGS += `pkg-config --cflags glfw3`
	CFLAGS = $(CXXFLAGS)
endif

ifeq ($(OS), Windows_NT)
	ECHO_MESSAGE = "MinGW"
	LIBS += -lglfw3 -lgdi32 -lopengl32 -limm32

	CXXFLAGS += `pkg-config --cflags glfw3`
	CFLAGS = $(CXXFLAGS)
endif



include base.mk

include src/project.mk

# LDFLAGS+=-lcriterion
# include tests/project.mk

true-all: ${TARGETS}
