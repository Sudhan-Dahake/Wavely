cmake_minimum_required(VERSION 4.3.2)

project(Wavely
	VERSION 0.1.0
	LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(Wavely
	app/main.cpp
)

target_include_directories(Wavely PRIVATE
	${CMAKE_SOURCE_DIR}
	${CMAKE_SOURCE_DIR}/include
	${CMAKE_SOURCE_DIR}/app
	${CMAKE_SOURCE_DIR}/audio
	${CMAKE_SOURCE_DIR}/'digital signal processing'
	${CMAKE_SOURCE_DIR}/matching
	${CMAKE_SOURCE_DIR}/control
)

if (MSVC)
	target_compile_options(Wavely PRIVATE /W4)

else ()
	target_compile_options(Wavely PRIVATE -Wall -Wextra -Wpedantic)

endif()
