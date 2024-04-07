CC = g++

HEADER_DIR = include
CFLAGS = -Wall -Werror -std=c++11 -w -I $(HEADER_DIR)

OUTPUT_DIR = bin
SRC_DIR = src
SRC_HPP_DIR = include/tubesoop1

MAIN = main
SRC_MAIN = src/cli/$(MAIN).cpp
OBJ_MAIN = $(SRC_MAIN:.cpp=.o)

DEPFLAGS = -MMD -MP  # flags to generate dependency files

# Dependency files
DEPS = $(OBJS:.o=.d)

-include $(DEPS)


$(OUTPUT_DIR)/%.o: %.cpp 
	@echo -n ">> "
	mkdir -p $(@D)
	@echo -n ">> "
	$(CC) $(CFLAGS) $(DEPFLAGS) -c -o  $@ $<

$(OUTPUT_DIR)/%.o: %.hpp
	@echo -n ">> "
	mkdir -p $(@D)
	@echo -n ">> "
	$(CC) $(CFLAGS) $(DEPFLAGS) -x c++ -c -o $@ $<

SRC_CLI = $(wildcard $(SRC_DIR)/cli/*.cpp) $(wildcard $(SRC_DIR)/cli/*/*.cpp)

SRC = $(SRC_MAIN) $(filter-out $(wildcard $(SRC_DIR)/*/*_test.cpp) $(wildcard $(SRC_DIR)/gui/*), $(wildcard $(SRC_DIR)/*/*.cpp)) $(SRC_CLI)
OBJS = $(patsubst %.cpp,$(OUTPUT_DIR)/%.o,$(filter-out $(SRC_MAIN), $(SRC))) $(patsubst %.hpp,$(OUTPUT_DIR)/%.o,$(wildcard $(SRC_HPP_DIR)/*/*.hpp))


.PHONY: all clean runcli test debug test

all: buildcli runcli

# rm -f $(OUTPUT_DIR)/$(OBJ_MAIN) $(OUTPUT_DIR)/$(MAIN) $(OBJS)
clean:
	$(info )
	$(info [Clean Program])
	@echo -n ">> "
	rm -rf $(OUTPUT_DIR)/include $(OUTPUT_DIR)/src


buildcli: $(OUTPUT_DIR)/$(OBJ_MAIN) $(OBJS)
	$(info )
	$(info [Build Program])
	@echo -n ">> "
	$(CC) $(CFLAGS) -o $(OUTPUT_DIR)/$(MAIN) $^

runcli:
	$(info )
	$(info [Run Program])
	@echo -n ">> "
	./$(OUTPUT_DIR)/$(MAIN)


# Initialie CMake
BUILD_DIR = build
initbuild:
	$(info )
	$(info [Initialize Unit Test])
	@echo -n ">> "
	cmake -S . -B $(BUILD_DIR)




# Unit Test
UNIT_TEST_TARGET = unit_test
buildtest: $(OUTPUT_DIR)/$(OBJ_MAIN) $(OBJS)
	$(info )
	$(info [Build Unit Test])
	@echo -n ">> "
	cmake --build $(BUILD_DIR) --target $(UNIT_TEST_TARGET)
	
runtest:
	$(info )
	$(info [Run Unit Test])
	@echo -n ">> "
	./$(BUILD_DIR)/$(UNIT_TEST_TARGET)



# GUI
GUI_TARGET = gui
buildgui: $(OUTPUT_DIR)/$(OBJ_MAIN) $(OBJS)
	$(info )
	$(info [Build GUI])
	@echo -n ">> "
	cmake --build $(BUILD_DIR) --target $(GUI_TARGET)

rungui:
	$(info )
	$(info [Run GUI])
	@echo -n ">> "
	./$(BUILD_DIR)/$(GUI_TARGET)


# Include the dependency files
-include $(OBJS:.o=.d)