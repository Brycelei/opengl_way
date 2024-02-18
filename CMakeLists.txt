cmake_minimum_required(VERSION 3.20)

# 设置 c++ 标准为 c++17 如果想用20就写20
set(CMAKE_CXX_STANDARD 17)
# 检测到编译器如果不支持 c++17 标准就会报错
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# 设置ON表示开启 GCC 特有特性，如果需要跨平台开发就选择OFF
set(CMAKE_CXX_EXTENSIONS OFF)

project(Aircraft)

# 设置静态
#set(CMAKE_CXX_FLAGS "-static")
# set(CMAKE_CXX_FLAGS "-libgcc")

file(GLOB_RECURSE HEADER_FILES 
 ${PROJECT_SOURCE_DIR}/include/*.hpp 
 ${PROJECT_SOURCE_DIR}/include/*.h)

# Windows编译配置
include_directories(
    ${PROJECT_SOURCE_DIR}/libs
    ${PROJECT_SOURCE_DIR}/libs/glad/include
    ${PROJECT_SOURCE_DIR}/libs/WindowsSystem/glfw-3.3.8.bin.WIN64/include
    ${PROJECT_SOURCE_DIR}/libs/assimp/include
    ${PROJECT_SOURCE_DIR}/include)

file(GLOB SRC_FILES CONFIGURE_ DEPENDS
    ${PROJECT_SOURCE_DIR}/libs/glad/src/*.c
    ${PROJECT_SOURCE_DIR}/src/*.cpp)

#Windows依赖复制
# 拷贝依赖文件到build目录Debug文件夹下
file(COPY ${PROJECT_SOURCE_DIR}/shaders DESTINATION ${PROJECT_BINARY_DIR}/)
file(COPY ${PROJECT_SOURCE_DIR}/asset DESTINATION ${PROJECT_BINARY_DIR}/)

file(GLOB SHADER_FILES CONFIGURE_ DEPENDS
   ${PROJECT_SOURCE_DIR}/shaders/6/*.fs
   ${PROJECT_SOURCE_DIR}/shaders/6/*.vs)

# copy dll to /build/file
file(COPY ${PROJECT_SOURCE_DIR}/dlls/ DESTINATION ${PROJECT_BINARY_DIR}/)

set_property(SOURCE ${SHADER_FILES} PROPERTY VS_TOOL_OVERRIDE "shader") 

add_executable(${CMAKE_PROJECT_NAME} ${SRC_FILES} ${HEADER_FILES} ${SHADER_FILES})

#target_link_libraries(${CMAKE_PROJECT_NAME} ${PROJECT_SOURCE_DIR}/libs/WindowsSystem/glfw-3.3.8.bin.WIN64/lib-mingw-w64/libglfw3.a)

if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    # 使用微软编译器
    target_link_libraries(${CMAKE_PROJECT_NAME} ${PROJECT_SOURCE_DIR}/libs/WindowsSystem/glfw-3.3.8.bin.WIN64/lib-vc2022/glfw3.lib)
    target_link_libraries(${CMAKE_PROJECT_NAME} ${PROJECT_SOURCE_DIR}/libs/assimp-vc142-mtd.lib) 
else()
    # 使用 Mingw 编译器
    target_link_libraries(${CMAKE_PROJECT_NAME} ${PROJECT_SOURCE_DIR}/libs/WindowsSystem/glfw-3.3.8.bin.WIN64/lib-mingw-w64/libglfw3.a)
endif()
