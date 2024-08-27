cmake_minimum_required(VERSION 3.10)
project(FaceCropper)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD_REQUIRED True)

# Find OpenCV
find_package(OpenCV REQUIRED)

# Include OpenCV directories
include_directories(${OpenCV_INCLUDE_DIRS})

# Define the executable
add_executable(face_cropper src/face_cropper.cpp)

# Link the executable to OpenCV libraries
target_link_libraries(face_cropper ${OpenCV_LIBS})

