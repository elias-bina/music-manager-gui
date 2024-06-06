include imgui/project.mk
include src/context_management/project.mk
include src/tabs_management/project.mk

MUSIC_MANAGER-EXE-NAME = $(BIN)/music-manager-gui-make-exe


MUSIC_MANAGER-EXE-SRCS = src/main.cpp	\
						 $(CONTEXT-SRC)	\
						 $(TABS-SRC)	\
						 $(IMGUI-SRCS)


MUSIC_MANAGER-EXE-OBJS:=$(MUSIC_MANAGER-EXE-SRCS:%.cpp=$(BIN)/%.o)
${MUSIC_MANAGER-EXE-NAME}: ${MUSIC_MANAGER-EXE-OBJS}

TARGETS+=${MUSIC_MANAGER-EXE-NAME}