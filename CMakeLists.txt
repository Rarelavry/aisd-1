# CMakeList.txt: проект CMake для AISD-1; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("AISD-1")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (AISD-1 "AISD-1.cpp" "AISD-1.h")

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
