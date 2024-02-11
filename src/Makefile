CC := g++
CFLAGS := -Wall -Wextra -std=c++17
LIB := s21_matrix_oop.a
TEST := test
TESTOUT := Matrix_test

SRC_DIR := MyClassMatrix
INCLUDE_DIR := include
BUILD_DIR := build
TEST_DIR := tests
LIB_DIR := lib

SRCS := $(wildcard $(SRC_DIR)/*.cpp)
OBJS := $(patsubst $(SRC_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(SRCS))

TEST_SRCS := $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS := $(patsubst $(TEST_DIR)/%.cpp,$(BUILD_DIR)/%.o,$(TEST_SRCS))

.PHONY: all clean test

all: $(LIB) $(TEST) 


$(LIB): $(OBJS)
	ar -rcs $(LIB_DIR)/$@ $^
	ranlib $(LIB_DIR)/$(LIB)


$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(INCLUDE_DIR) $(BUILD_DIR) $(LIB_DIR)
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

$(TEST): $(TEST_OBJS) $(LIB)
	$(CC) $(CFLAGS) $(TEST_SRCS) $(LIB_DIR)/$(LIB) -o $(TEST_DIR)/$(TESTOUT) -lgtest
	 ./$(TEST_DIR)/$(TESTOUT)
	

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp
	$(CC) $(CFLAGS) -I$(INCLUDE_DIR) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)/*.o $(LIB_DIR)/*.a 
	rm -rf $(TEST_DIR)/$(TESTOUT)
	rm -rf $(INCLUDE_DIR) $(BUILD_DIR) $(LIB_DIR)
	rm -rf report

style:
	clang-format -style=Google -n $(TEST_SRCS) $(SRCS)
	cppcheck --enable=all --suppress=missingIncludeSystem ${SRCS} 

leaks:
	CK_FORK=no leaks --atExit -- ./$(TEST_DIR)/$(TESTOUT)

gcove_report: clean 
	gcc  --coverage $(TEST_SRCS) $(SRCS) -o gcov_report -lgtest -lstdc++
	./gcov_report
	rm -rf test.gcda test.gcno 
	lcov -t "stest" -o s21_test.info -c -d .
	genhtml -o report s21_test.info
	open ./report/index.html
	rm -rf s21_* gcov_report