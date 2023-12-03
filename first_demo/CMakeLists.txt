# CMake最低版本要求
cmake_minimum_required(VERSION 3.15)

# 获取当前文件夹名
get_filename_component(CURRENT_DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

# 项目名称
project(${CURRENT_DIR_NAME})

set(VERSION_MAJOR 1)
set(VERSION_MINOR 0)
set(VERSION_PATCH 0)

# 加入一个配置头文档用于处理 CMake 对源码的设置
configure_file(
    "${PROJECT_SOURCE_DIR}/config.h.in"
    "${PROJECT_SOURCE_DIR}/config.h"
)

option(USESUBMODULE "Use submodule" ON)
if (USESUBMODULE)
    set(SUBMODULE my_fun)

    # 添加子目录
    # 必须放在aux_source_directory前
    add_subdirectory(${SUBMODULE})
endif (USESUBMODULE)

# 查找当前目录下所有源文档并保存到变量
aux_source_directory(. DIR_SRCS)

# 指定生成目标
add_executable(${PROJECT_NAME} ${DIR_SRCS})

# 添加链接库
target_link_libraries(${PROJECT_NAME} ${SUBMODULE})

# 安装目标
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(FILES config.h DESTINATION include)

# 启用测试
enable_testing()

# 添加测试
add_test(NAME test COMMAND ${PROJECT_NAME})

# 验证测试结果
set_tests_properties(test PROPERTIES PASS_REGULAR_EXPRESSION "Hello, CMake!")