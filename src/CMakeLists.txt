cmake_minimum_required(VERSION 3.16)
add_executable(console-sample
  main.cpp
)

target_link_libraries(
    console-sample
    Qt${QT_VERSION_MAJOR}::Core
    KF${QT_MAJOR_VERSION}::ThreadWeaver
    spdlog::spdlog $<$<BOOL:${MINGW}>:ws2_32>
)


include(GNUInstallDirs)
install(TARGETS console-sample
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)
