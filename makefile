## Application anem
APP_NAME := what-the-hex
DESKTOP_FILE := what-the-hex.desktop


## Directories to build files into
OBJ_DIR := obj
BIN_DIR := bin

## List of all c++ files to compile
CPP_FILES := main.cpp

## List of all object files to generate
OBJ_FILES = $(addprefix $(OBJ_DIR)/,$(CPP_FILES:%.cpp=%.o))


## Compiler, compiler and linker flags and libaries to use
CXX := g++
CXXLIBS :=
LDLIBS := -lX11

CXXFLAGS := -MMD --std=c++11 $(CXXLIBS)
LDFLAGS := -std=c++11 $(LDLIBS)


## Build applications
all: $(BIN_DIR)/$(APP_NAME)

$(BIN_DIR)/$(APP_NAME): $(OBJ_FILES) | $(BIN_DIR)
	$(CXX) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: %.cpp | $(OBJ_DIR)
	$(CXX) -c -o $@ $< $(CXXFLAGS)


$(BIN_DIR):
	mkdir $(BIN_DIR)

$(OBJ_DIR):
	mkdir $(OBJ_DIR) $(SRC_DIRS:%=$(OBJ_DIR)/%)


# Install the library
install:
	cp $(BIN_DIR)/$(APP_NAME) /usr/bin/
	cp $(DESKTOP_FILE) /usr/share/applications

# Uninstall the library
uninstall:
	rm /usr/bin/$(APP_NAME)
	rm /usr/share/applications/$(DESKTOP_FILE)

## Clean up everything
clean:
	rm -rf obj
	rm -rf bin


## Include auto-generated dependencies rules
-include $(OBJ_FILES:.o=.d)
