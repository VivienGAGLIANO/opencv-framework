cmake_minimum_required(VERSION 3.19)
project(Recherche)
set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)


add_executable(Recherche
        main.cpp
        header/dft.h src/dft.cpp
        header/filter/filter.h src/filter/filter.cpp
        header/filter/low_pass_filter.h src/filter/low_pass_filter.cpp
        header/filter/high_pass_filter.h src/filter/high_pass_filter.cpp
        header/filter/bandpass_filter.h src/filter/bandpass_filter.cpp
        header/filter/bandcut_filter.h src/filter/bandcut_filter.cpp
        header/filter/log_gabor_filter.h src/filter/log_gabor_filter.cpp
        )

# Additional Include Directories
include_directories( ${OpenCV_INCLUDE_DIRS} header header/filter )

# Additional Library Directories
link_directories( ${OpenCV_LIB_DIR} )

# Additional Dependencies
target_link_libraries( Recherche ${OpenCV_LIBS} )
