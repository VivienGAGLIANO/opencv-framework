cmake_minimum_required(VERSION 3.19)
project(Recherche)
set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)


add_executable(Recherche
        main.cpp
        header/dft.h src/dft.cpp
        header/filter/filter.h src/filter/filter.cpp
        header/filter/ideal_filter.h src/filter/ideal_filter.cpp)

# Additional Include Directories
include_directories( ${OpenCV_INCLUDE_DIRS} header header/filter )

# Additional Library Directories
link_directories( ${OpenCV_LIB_DIR} )

# Additional Dependencies
target_link_libraries( Recherche ${OpenCV_LIBS} )
