cmake_minimum_required(VERSION 3.16)
project(Phonebook LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)
find_package(Qt6 COMPONENTS Widgets Sql REQUIRED)
add_executable(phonebook
    main.cpp
    mainwindow.cpp
    contact.cpp
    phonenumber.cpp
    phonebook.cpp
    filestorage.cpp
    dbstorage.cpp
)
target_include_directories(phonebook PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(phonebook PRIVATE Qt6::Widgets Qt6::Sql)
