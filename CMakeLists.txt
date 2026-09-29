# 隐藏功能：把这个版本号对应的 CMake 策略（Policies）行为固定下来。
cmake_minimum_required(VERSION 3.15)

# 手动控制“行为切换开关”
# CMP0167：这个策略是 CMake 3.24 引入的，管的场景是查找 Python 解释器。
cmake_policy(SET CMP0167 NEW)

# 项目配置
# project() 命令一执行，CMake 在背后会自动做不少事情：
# 1. 设置了一堆有用变量：PROJECT_NAME、PROJECT_VERSION、PROJECT_SOURCE_DIR、PROJECT_BINARY_DIR、PROJECT_IS_TOP_LEVEL等。
# 2. 启用并测试编译器
# 3. 重置与语言关联的内部状态
project(
    lqc-prac-algo
    VERSION 1.0
    LANGUAGES C CXX
)

# C++标准配置
# 使用 C++17 这个标准版本。
set(CMAKE_CXX_STANDARD 17)
# 强制要求编译器支持 C++17，如果它不支持，立马报错，不准偷偷摸摸降级到 C++14。
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# 关掉编译器的特有（方言）扩展，只用标准 C++，别加那些只有自家才认的特殊语法。
set(CMAKE_CXX_EXTENSIONS OFF)

# C标准配置
# 请用 C17 标准来编译 C 代码
set(CMAKE_C_STANDARD 17)
# 强制要求编译器支持 C17，如果不支持就直接报错，别给我偷偷缩水成 C11 或 C99。
set(CMAKE_C_STANDARD_REQUIRED ON)
# 关掉编译器自己的方言扩展（比如 GCC 的某些特有语法），只用纯粹的标准 C。
set(CMAKE_C_EXTENSIONS OFF)

# ---------- SRC_DIR 处理（增强鲁棒性） ----------
# 若未通过 -D 传入，则回退到项目根目录，但会给出警告（可能包含多个 main）
if(NOT DEFINED SRC_DIR)
    set(SRC_DIR "${CMAKE_SOURCE_DIR}" CACHE PATH "源文件所在目录")
    message(WARNING "SRC_DIR not specified, defaulting to ${SRC_DIR} (may cause multiple main errors)")
else()
    set(SRC_DIR "${SRC_DIR}" CACHE PATH "源文件所在目录")
endif()

# 检查 SRC_DIR 是否存在且包含至少一个 .cpp/.c 文件
# GLOB：源自 Unix 术语“glob”，是“global”的简写，意思是用通配符模式匹配文件名（比如 *.cpp）。
file(GLOB_RECURSE SOURCES
    "${SRC_DIR}/*.cpp"
    "${SRC_DIR}/*.c"
)

if(NOT SOURCES)
    message(FATAL_ERROR "No .cpp/.c files found in SRC_DIR='${SRC_DIR}'. "
                        "Please pass -DSRC_DIR=path/to/code when running cmake.")
endif()

# 输出信息
message(STATUS "Source directory: ${SRC_DIR}")
message(STATUS "Sources found: ${SOURCES}")

# 目标名称与输出目录
set(TARGET_NAME "test")
# RUNTIME：运行时，这里特指可执行文件（.exe，Linux 可执行程序等）。
# 别把最终生成的可执行文件放在默认的 build 目录里了，直接放到 ${SRC_DIR} 下面去。
# 此配置用于源码的学习&练习，在真实的生产环境一般不采用。
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${SRC_DIR}")

# 默认构建类型
# 如果用户没有明确指定构建类型（比如 Debug 还是 Release），那我就强制把它设成 Debug，并记住这个选择。
# FORCE：强制覆盖。
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug" CACHE STRING "Build type (Debug/Release)" FORCE)
endif()

# ---------- 编译器编码配置 ----------
if (CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fexec-charset=UTF-8 -finput-charset=UTF-8")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fexec-charset=UTF-8 -finput-charset=UTF-8")
elseif (CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /utf-8")
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /utf-8")
endif()

# 生成可执行文件
# 请把这些源文件（${SOURCES}）编译、链接，生成一个名叫 test（${TARGET_NAME}）的可执行程序。
add_executable(${TARGET_NAME} ${SOURCES})

# 头文件路径（包含源文件目录本身）
# 编译 test 这个程序的时候，让编译器去 ${SRC_DIR} 这个目录（及其子目录）里找头文件（.h / .hpp）。
# 这些头文件路径只给 test 自己用，别传给其他依赖它的目标。
target_include_directories(${TARGET_NAME} PRIVATE ${SRC_DIR})