cmake_minimum_required(VERSION 3.14)
project(tubesoop1)

# GoogleTest requires at least C++14, 17 to support inline
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

include_directories(include)
set(SOURCES
  src/animal/animal.cpp
  src/plant/plant.cpp
  src/animal/animal_test.cpp
  src/plant/plant_test.cpp
)

add_executable(unit_test ${SOURCES})
target_link_libraries(unit_test GTest::gtest_main)
include(GoogleTest)
gtest_discover_tests(unit_test)


find_package(Qt5Widgets REQUIRED)
include_directories(${Qt5Widgets_INCLUDE_DIRS})
set(GUISOURCES 
  src/gui/main.cpp
  src/gui/components/nicebutton.cpp
  src/gui/components/gridbutton.cpp
  include/tubesoop1/gui/components/gridbutton.hpp
  src/gui/components/locationlabel.cpp

  src/resource/resource.cpp
  src/icosihexastring/icosihexastring.cpp
  src/grid/location.cpp
  src/grid/location_exception.cpp
  src/grid/grid.cpp
  include/tubesoop1/grid/grid.hpp
)
add_executable(gui ${GUISOURCES})
target_link_libraries(gui Qt5::Widgets)
