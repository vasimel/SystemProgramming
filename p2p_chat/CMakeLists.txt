cmake_minimum_required(VERSION 3.14)
project(P2PChat)

# Установка C++ стандарта
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Находим пакеты Qt
find_package(Qt5 COMPONENTS Core Network REQUIRED)

# Указываем, что main.cpp должен быть обработан MOC
set(CMAKE_AUTOMOC ON)

# Добавляем исходные файлы
add_executable(P2PChat main.cpp)

# Линкуем с Qt библиотеками
target_link_libraries(P2PChat Qt5::Core Qt5::Network)
