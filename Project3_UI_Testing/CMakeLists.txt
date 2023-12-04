cmake_minimum_required(VERSION 3.26)
project(Project3_UI_Testing)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Project3_UI_Testing
        DataComparison.cpp
        DataComparison.h
        HelperFunctions.cpp
        HelperFunctions.h
        IncludeStatements.h
        main.cpp
        Movie.h
        Trie.cpp
        Trie.h
        Main_page.h
        Results_Page.h)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(c:/SFML/include/SFML)
target_link_libraries(Project3_UI_Testing sfml-system sfml-window sfml-graphics sfml-audio)