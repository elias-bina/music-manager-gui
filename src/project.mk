include dependancies/imgui/project.mk
include src/context_management/project.mk
include src/ressources_loading/project.mk
include src/ui/project.mk

MUSIC_MANAGER-EXE-NAME = $(BIN)/music-manager-gui-make-exe


MUSIC_MANAGER-EXE-SRCS = src/main.cpp			\
						 $(CONTEXT-SRC)			\
						 $(RESSOURCE-LOAD-SRC)	\
						 $(UI-SRC)				\
						 $(IMGUI-SRCS)

MUSIC_MANAGER-EXE-OBJS:=$(MUSIC_MANAGER-EXE-SRCS:%.cpp=$(BIN)/%.o)
${MUSIC_MANAGER-EXE-NAME}: ${MUSIC_MANAGER-EXE-OBJS}

TARGETS+=${MUSIC_MANAGER-EXE-NAME}