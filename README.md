# cmake_demo
CMake 学习

## Learning summary
### add_subdirectory
`add_subdirectory(source_dir [binary_dir])`是添加子模块目录, `source_dir`指定子模块源文件路径, 即CMakeLists.txt所在的路径.`binary_dir`可不填, 这样子模块构建输出将会输出到当前模块的输出路径下.
执行这条命令会立即执行子模块的CMakeLists.txt, 然后在此命令之后继续对当前输入文档进行处理.
> `set`命令设置的变量在在整个 CMake 项目中可见，包括任何使用 `add_subdirectory` 添加的子目录, 但是 Cmake 是按顺序执行每个命令, 所以想要在子模块中共享变量的话, 必须在`add_subdirectory`之前`set`.