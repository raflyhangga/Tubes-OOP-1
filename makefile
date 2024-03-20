CC = g++

HEADER_DIR = include
CFLAGS = -Wall -Werror -std=c11 -w -I $(HEADER_DIR)

OUTPUT_DIR = bin
SRC_DIR = src

MAIN = main
SRC_MAIN = src/$(MAIN).cpp
OBJ_MAIN = $(SRC_MAIN:.cpp=.o)


$(OUTPUT_DIR)/%.o: %.cpp 
	@echo -n ">> "
	mkdir -p $(@D)
	@echo -n ">> "
	$(CC) $(CFLAGS) -c -o $@ $<

SRC = $(SRC_MAIN) $(filter-out $(wildcard $(SRC_DIR)/*/*_test.cpp), $(wildcard $(SRC_DIR)/*/*.cpp))
OBJS = $(patsubst %,$(OUTPUT_DIR)/%,$(SRC:.cpp=.o))

.PHONY: all clean run test debug test

all: build run

build: $(OUTPUT_DIR)/$(OBJ_MAIN) $(OBJS)
	$(info )
	$(info [Build Program])
	@echo -n ">> "
	$(CC) $(CFLAGS) -o $(OUTPUT_DIR)/$(MAIN) $^

clean:
	$(info )
	$(info [Clean Program])
	@echo -n ">> "
	rm -f $(OUTPUT_DIR)/$(OBJ_MAIN) $(OUTPUT_DIR)/$(MAIN) $(OBJS)

run:
	$(info )
	$(info [Run Program])
	@echo -n ">> "
	./$(OUTPUT_DIR)/$(MAIN)
	
inittest:
	$(info )
	$(info [Initialize Test])
	cmake -S . -B test

buildtest: $(OUTPUT_DIR)/$(OBJ_MAIN) $(OBJS)
	$(info )
	$(info [Build Test])
	@echo -n ">> "
	cmake --build test
	
test:
	$(info )
	$(info [Run Unit Test])
	@echo -n ">> "
	cd test && ctest

