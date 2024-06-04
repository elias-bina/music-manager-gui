

$(BIN)/%.o:%.cpp
	mkdir -p $(dir $@)
	gcc -o $@ -c $^ $(INCLUDES) $(CFLAGS)

$(BIN)/%-make-exe:
	mkdir -p $(dir $@)
	g++ -o $(patsubst %-make-exe,%,$@) $^ $(LDFLAGS) $(LIBS)

all: $(EXE)
	@echo Build complete for $(ECHO_MESSAGE)

.PHONY:clean
clean:
	rm -rf $(BIN)

