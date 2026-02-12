CC = g++

TARGET = assignment2.out

DEBUG_FLAGS = -fsanitize=address,undefined -fno-omit-frame-pointer -g3 -O0
CFLAGS = -c
LDFLAGS =
CPP_FLAGS = -Iinclude
BUILD_FOLDER = build

SRC := $(wildcard src/*.cpp)
OBJ := $(patsubst src/%.cpp,$(BUILD_FOLDER)/%.o, $(SRC))

default: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(OBJ) $(DEBUG_FLAGS) $(LDFLAGS) -o $@

$(BUILD_FOLDER)/%.o: src/%.cpp | $(BUILD_FOLDER)
	$(CC) $(CPP_FLAGS) $(CFLAGS) $(DEBUG_FLAGS) $^ -o $@

$(BUILD_FOLDER):
	mkdir -p $@

clean:
	rm -rf $(BUILD_FOLDER)
	rm -rf $(TARGET)