CXX = g++
GLFW_PREFIX = /usr/local/opt/glfw
CXXFLAGS = -Wall -std=c++17 -Isrc -Iexternal -Iexternal/glad -Iexternal/KHR -I$(GLFW_PREFIX)/include
LDFLAGS = -L$(GLFW_PREFIX)/lib -lglfw \
          -framework OpenGL -framework Cocoa -framework IOKit -framework CoreVideo

SRC = src/main.cpp \
      src/shader.cpp \
      external/glad.c

TARGET = app

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)