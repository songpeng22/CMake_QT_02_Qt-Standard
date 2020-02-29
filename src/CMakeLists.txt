cmake_minimum_required(VERSION 3.1.0)
# Solution Start
message( "---------------------------Solution part----------------------------------" )
project(Solution)

# set(<variable> <value>
#    [[CACHE <type> <docstring> [FORCE]] | PARENT_SCOPE])
set( project_name Qt_Standard )
message( "Project name is: " ${project_name} )

# CMake Qt
message( "---------------------------Qt part----------------------------------" )
# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

# Find the QtWidgets library
find_package( Qt5 REQUIRED 
    COMPONENTS Widgets Qml 
)

include_directories(
    ${Qt5Widgets_INCLUDE_DIRS}
    Qt5::Qml
)

# Populate a CMake variable with the sources
FILE(GLOB project_sources
    mainwindow.cpp
    main.cpp
)

FILE(GLOB project_headers
    *.h
)

SET(project_resources 
    mainwindow.ui
)

# mark as startup project
IF(WIN32 AND MSVC)
	set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT ${project_name})
ENDIF()

# Tell CMake to create the ${project_name} executable
add_executable(${project_name} WIN32 ${project_sources} ${project_headers} ${project_resources})
# Must After add_executable
target_link_libraries( ${project_name}
	${Qt5Widgets_LIBRARIES}
	${Qt5Qml_LIBRARIES}
)

#Message Sln Path
MESSAGE(STATUS "This is BINARY dir " ${Solution_BINARY_DIR})
MESSAGE(STATUS "This is SOURCE dir " ${Solution_SOURCE_DIR})
#Message Qt Path
MESSAGE(STATUS "This is Qt5Widgets_INCLUDE_DIRS " ${Qt5Widgets_INCLUDE_DIRS})
MESSAGE(STATUS "This is Qt5Widgets_LIBRARIES " ${Qt5Widgets_LIBRARIES})
MESSAGE(STATUS "This is Qt5Qml_INCLUDE_DIRS " ${Qt5Qml_INCLUDE_DIRS})
