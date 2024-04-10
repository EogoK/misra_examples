cmake_minimum_required(VERSION 3.0.0)
project(misra_examples VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

#add_executable(misra_examples include/misra_examples/abstract.cpp)
#add_executable(misra_examples include/misra_examples/abstract_misra.cpp)
add_executable(misra_examples include/misra_examples/decorator.cpp)
#add_executable(misra_examples include/misra_examples/decorator_misra.cpp)
#add_executable(misra_examples include/misra_examples/strategy.cpp)
#add_executable(misra_examples include/misra_examples/strategy_misra.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
