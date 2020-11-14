project(test)

find_package(PkgConfig)

pkg_check_modules(GTKMM gtkmm-3.0) # look into FindPkgConfig.cmake, 

link_directories(
    ${GTKMM_LIBRARY_DIRS} 
    )
link_libraries(
	"/usr/lib/x86_64-linux-gnu/libmysqlpp.so"
)
include_directories(
    ${GTKMM_INCLUDE_DIRS}  
    "${PROJECT_SOURCE_DIR}/include"
    "/usr/include/mysql++/"
    "/usr/include/mariadb/server/"
    )
    
file(GLOB SOURCES
    "${PROJECT_SOURCE_DIR}/main.cpp"
    "${PROJECT_SOURCE_DIR}/src/*.cpp"            
)

add_executable(test ${SOURCES})
target_link_libraries(test ${GTKMM_LIBRARIES})
