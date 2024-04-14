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
  src/animal/animal_test.cpp
  src/plant/plant_test.cpp
  src/animal/animal_exception.cpp 
  src/animal/carnivore.cpp 
  src/animal/herbivore.cpp 
  src/animal/omnivore.cpp 
  src/building/building.cpp 
  src/grid/grid.cpp 
  src/grid/griddrawer.cpp 
  src/grid/location.cpp 
  src/grid/location_exception.cpp 
  src/icosihexastring/icosihexastring.cpp 
  src/plant/plant.cpp 
  src/player/petani.cpp 
  src/player/peternak.cpp 
  src/player/player.cpp 
  src/player/player_partial.cpp 
  src/player/taxreport.cpp 
  src/player/walikota.cpp 
  src/product/product.cpp 
  src/quantifiable/quantifiable.cpp 
  src/resource/creature.cpp 
  src/resource/creature_exception.cpp 
  src/resource/resource.cpp 
  src/resource/resourcefactory.cpp 
  src/resource/resourcefactory_exception.cpp 
  src/resourcevisitorpattern/resource_exception.cpp 
  src/resourcevisitorpattern/resourcevisitorpattern.cpp 
  src/resourcevisitorpattern/taker.cpp 
  src/shop/shop.cpp 
  src/state/state.cpp 
  src/state/state_exception.cpp 
  src/temp/temp.cpp src/txtparser/txtparser.cpp include/tubesoop1/grid/grid.hpp include/tubesoop1/grid/griddrawer.hpp include/tubesoop1/grid/location_exception.h include/tubesoop1/player/player_partial.hpp include/tubesoop1/quantifiable/quantifiable.hpp include/tubesoop1/resourcevisitorpattern/taker.hpp include/tubesoop1/txtparser/txtparser.hpp
  src/building/building_test.cpp
  src/building/bangunan_exception.cpp
  src/plant/plant_test.cpp
  src/player/petani_test.cpp
  src/player/peternak_test.cpp
  src/player/walikota_test.cpp
  src/product/product_test.cpp
  src/shop/shop_test.cpp
  src/quantifiable/quantifiable_test.cpp
  src/grid/grid_test.cpp
  src/grid/location_test.cpp
  src/grid/location_exception.cpp
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
  src/gui/components/mainwindow.cpp
  src/gui/components/gridview.cpp
  src/gui/components/initdialog.cpp
  src/gui/components/statusbar.cpp
  src/gui/components/messagebox.cpp
  include/tubesoop1/gui/components/gridview.hpp
  src/gui/components/locationlabel.cpp
  src/gui/components/choicedialog.cpp
  src/gui/components/moc_choicedialog.cpp
  src/gui/components/inputdialog.cpp
  src/gui/components/dialog.cpp
  src/gui/components/moc_gridsignal.cpp
  src/gui/components/application.cpp

  
  src/gui/game.cpp
  src/gui/command/command.cpp
  src/gui/command/help.cpp
  src/gui/command/next.cpp
  src/gui/command/cetakpenyimpanan.cpp
  src/gui/command/cetakpeternakan.cpp
  src/gui/command/cetakladang.cpp
  src/gui/command/pungutpajak.cpp
  src/gui/command/bangun.cpp
  src/gui/command/command_exception.cpp
  src/gui/command/tambahpemain.cpp
  src/gui/command/tanam.cpp
  src/gui/command/ternak.cpp
  src/gui/command/makan.cpp
  
  src/animal/animal.cpp src/animal/animal_exception.cpp src/animal/carnivore.cpp src/animal/herbivore.cpp src/animal/omnivore.cpp src/building/building.cpp src/grid/grid.cpp src/grid/griddrawer.cpp src/grid/location.cpp src/grid/location_exception.cpp src/icosihexastring/icosihexastring.cpp src/plant/plant.cpp src/player/petani.cpp src/player/peternak.cpp src/player/player.cpp src/player/player_partial.cpp src/player/taxreport.cpp src/player/walikota.cpp src/product/product.cpp src/quantifiable/quantifiable.cpp src/resource/creature.cpp src/resource/creature_exception.cpp src/resource/resource.cpp src/resource/resourcefactory.cpp src/resource/resourcefactory_exception.cpp src/resourcevisitorpattern/resource_exception.cpp src/resourcevisitorpattern/resourcevisitorpattern.cpp src/resourcevisitorpattern/taker.cpp src/shop/shop.cpp src/state/state.cpp src/state/state_exception.cpp src/temp/temp.cpp src/txtparser/txtparser.cpp include/tubesoop1/grid/grid.hpp include/tubesoop1/grid/griddrawer.hpp include/tubesoop1/grid/location_exception.h include/tubesoop1/player/player_partial.hpp include/tubesoop1/quantifiable/quantifiable.hpp include/tubesoop1/resourcevisitorpattern/taker.hpp include/tubesoop1/txtparser/txtparser.hpp
)
add_executable(gui ${GUISOURCES})
target_link_libraries(gui Qt5::Widgets)
