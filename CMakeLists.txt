# CMakeList.txt: CMake-Projekt für "Orbits". Schließen Sie die Quelle ein, und definieren Sie
# projektspezifische Logik hier.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Orbits")

# Fügen Sie der ausführbaren Datei dieses Projekts eine Quelle hinzu.
add_executable (Orbits "src/main.cpp")
include_directories(Orbits "include/")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Orbits PROPERTY CXX_STANDARD 20)
endif()

# TODO: Fügen Sie bei Bedarf Tests hinzu, und installieren Sie Ziele.
