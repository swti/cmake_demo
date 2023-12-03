#include <iostream>

#include "config.h"

#ifdef USESUBMODULE
#include "my_fun/my_fun.h"
#endif

int main() {
  std::cout << "Hello, CMake!" << std::endl;
#ifdef USESUBMODULE
  std::cout << "my_fun(1, 2) = " << my_fun(1, 2) << std::endl;
#endif
  std::cout << "version: " << VERSION_MAJOR << "." << VERSION_MINOR << "."
            << VERSION_PATCH << std::endl;
  return 0;
}