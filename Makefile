CXX := clang++
CXXLD := clang++
CXXFLAGS := -Wall -Wextra -Werror
CXXFLAGS += $(if $(filter 1,$(TEST)), -Weverything -Wno-poison-system-directories -save-temps=obj,)
LDFLAGS :=
SRC_DIR := .
OBJ_DIR := .
TARGET := a.out
SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))
DEPS := $(OBJS:.o=.d)
TEMPS := *.o *.d
TEMPS += *.bc *.i *.s

all: $(TARGET)
.PHONY: all clean fclean re
clean:
	rm -f $(TEMPS)
fclean: clean
	rm -f $(TARGET)
re: fclean all

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CFLAGS) -c $< -o $@ -MMD

$(TARGET): $(OBJS)
	$(CXXLD) $(LDFLAGS) $(OBJS) -o $@

-include $(DEPS)
