CXX = g++
CXXFLAGS = -std=c++20 -Wall -Iinclude
SRC = src/main.cpp \
	src/input_buffer.cpp \
	src/console.cpp \
	src/command_dispatcher.cpp
TARGET = chronicle
all:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)
clean:
	rm -f $(TARGET)