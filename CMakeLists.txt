cmake_minimum_required (VERSION 2.6)
project (powerline-zsh)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")

find_package( Readline )
if(NOT READLINE_FOUND)
	message(FATAL_ERROR "Readline package can't be found.")
endif()


include_directories(${Readline_INCLUDE_DIR})
add_executable(esh esh.c builtins.c format.c gc.c hash.c list.c)
target_link_libraries(esh ${Readline_LIBRARY})

set( CMAKE_CC_FLAGS "-02 -g -Wall")