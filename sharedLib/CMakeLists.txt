cmake_minimum_required(VERSION 2.8.9)
project(paulProj)
set(CMAKE_BUILD_TYPE Release)

set (OS_SW_DIR /home/tdao0751/man7/sw/)
#Bring the headers, such as Student.h into the project
include_directories( ${OS_SW_DIR}/h)

#However, the file(GLOB...) allows for wildcard additions:
file(GLOB SOURCES "src/errorfunc/*.c", "src/getnum/*.c")

#Generate the shared library from the sources
add_library(man7ref SHARED ${SOURCES})

#Set the location for library installation -- i.e., /usr/lib in this case
# not really necessary in this example. Use "sudo make install" to apply
install(TARGETS man7ref DESTINATION /usr/lib)