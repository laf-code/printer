cmake_minimum_required(VERSION 3.10.0)
project(printer VERSION 0.1.0 LANGUAGES C CXX)

find_package(fmt CONFIG REQUIRED)

add_library(printer src/printer.cpp)

target_include_directories(printer PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

target_link_libraries(printer PRIVATE fmt::fmt)

install(TARGETS printer
    EXPORT PrinterConfig
    ARCHIVE DESTINATION lib
    LIBRARY DESTINATION lib
    RUNTIME DESTINATION bin
)

install(DIRECTORY include/ DESTINATION include)

install(EXPORT PrinterConfig
    NAMESPACE printer::
    DESTINATION lib/cmake/printer
)

include(CTest)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
