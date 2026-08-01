CXX = g++
CXXFLAGS = -std=c++20 -Wall -Iinclude
SRC = src/main.cpp \
	src/input_buffer.cpp \
	src/console.cpp \
	src/command_dispatcher.cpp \
	src/parser.cpp\
	src/executer.cpp\
	src/world_state.cpp
TARGET = chronicle
all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)
clean:
	rm -f $(TARGET)