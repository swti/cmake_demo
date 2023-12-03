# CMake minimum version required
cmake_minimum_required(VERSION 3.15)

# 获取当前文件夹名称
get_filename_component(CURRENT_DIR_NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)

# 设置项目名称
project(${CURRENT_DIR_NAME})

# 查找当前目录下所有源文档并保存到变量
aux_source_directory(. DIR_SRCS)

# 生成链接库
add_library(${PROJECT_NAME} ${DIR_SRCS})

# 添加安装命令
install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(FILES ${PROJECT_NAME}.h DESTINATION include)