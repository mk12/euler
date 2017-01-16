# Compiler
CXX := clang++
OFLAGS := -O3
CFLAGS := -std=c++14 -pedantic -Wno-c++98-compat -Wno-missing-prototypes \
	-Wno-padded -isystem /usr/local/include
LDFLAGS := -L /usr/local/lib -lgmpxx -lgmp

# Project
NAME := test
SRC_DIR := src
OBJ_DIR := build
BIN_DIR := bin

# Files
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
DEPS := $(OBJS:.o=.d)
EXEC := $(BIN_DIR)/$(NAME)

# Dependencies
DEPFLAGS = -MT $@ -MMD -MP -MF $(OBJ_DIR)/$*.d

# Targets
.PHONY: all release debug prep clean

all: release

release: CFLAGS += $(OFLAGS) -DNDEBUG
release: LDFLAGS += $(OFLAGS)
release: prep $(EXEC)
release:
	@echo "Target release is up to date"

debug: CFLAGS += -g
debug: prep $(EXEC)
debug:
	@echo "Target debug is up to date"

prep:
	@mkdir -p $(OBJ_DIR) $(BIN_DIR)

clean:
	rm -f $(OBJS) $(DEPS) $(EXEC)

$(EXEC): $(OBJS)
	@echo "\033[0;31mLinking executable $(NAME)\033[0m"
	@$(CXX) $^ -o $@ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	@echo "\033[0;32mCXX\033[0m $<"
	@$(CXX) -c $< -o $@ $(CFLAGS) $(DEPFLAGS)

-include $(DEPS)
