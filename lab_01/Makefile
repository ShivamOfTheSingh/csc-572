CXX = g++
CXXFLAGS = -Wall -std=c++17

# include paths (add more with -I if needed)
INCLUDES = -Iinclude -Iexternal/stb

LDFLAGS = -lglfw -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

SRC = $(wildcard src/*.cpp src/*.c)
TARGET = app

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(INCLUDES) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)
