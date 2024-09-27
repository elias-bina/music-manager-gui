

$(BIN)/%.o:%.cpp
	mkdir -p $(dir $@)
	$(CC) -o $@ -c $^ $(INCLUDES) $(CFLAGS)

$(BIN)/%-make-exe:
	mkdir -p $(dir $@)
	$(CXX) -o $(patsubst %-make-exe,%,$@) $^ $(LDFLAGS) $(LIBS)

all: $(EXE)
	@echo Build complete for $(ECHO_MESSAGE)

.PHONY:clean
clean:
	rm -rf $(BIN)

