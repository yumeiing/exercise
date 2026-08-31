cmake_minimum_required(VERSION 3.16)

project(recursion_hanoi LANGUAGES C)

add_executable(recursion_hanoi main.c)

include(GNUInstallDirs)
install(TARGETS recursion_hanoi
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
