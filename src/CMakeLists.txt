configure_file(avpp_global.h.in "${CMAKE_CURRENT_BINARY_DIR}/avpp_global.h")

file(GLOB HEADERS "${CMAKE_SOURCE_DIR}/include/avpp/*.h")
set(HEADERS "${HEADERS}" "${CMAKE_CURRENT_BINARY_DIR}/avpp_global.h")

set(SRC
    context.cpp
)

add_library(avpp SHARED ${SRC})

set_target_properties(avpp PROPERTIES
    CXX_STANDARD 11
    CXX_STANDARD_REQUIRED ON
    DEFINE_SYMBOL AVPP_LIBRARY
    PUBLIC_HEADER "${HEADERS}"
    VERSION ${VERSION}
    SOVERSION ${VERSION_MAJOR}
)

target_include_directories(avpp PUBLIC
    "$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>"
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_BINARY_DIR}>"
    "$<INSTALL_INTERFACE:include}>"
)

target_link_libraries(avpp
    ${FFMPEG_LIBRARIES}
)

install(TARGETS avpp
    RUNTIME DESTINATION bin
    LIBRARY DESTINATION lib
    ARCHIVE DESTINATION lib
    PUBLIC_HEADER DESTINATION include/avpp
)
