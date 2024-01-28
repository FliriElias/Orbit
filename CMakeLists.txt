# CMakeList.txt: CMake-Projekt für "Orbits". Schließen Sie die Quelle ein, und definieren Sie
# projektspezifische Logik hier.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD_REQUIRED 20)

project ("Orbits")


add_executable (Orbits "src/main.cpp")
include_directories(Orbits "include/")


# TODO: Fügen Sie bei Bedarf Tests hinzu, und installieren Sie Ziele.
