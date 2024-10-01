# CMakeList.txt: Projekt CMake pro Project2, sem přidejte logiku zdrojového
# kódu a definic specifickou pro projekt.
#

# Přidejte zdrojový kód ke spustitelnému souboru tohoto projektu.
add_executable (Project2 "Project2.cpp" "Project2.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Project2 PROPERTY CXX_STANDARD 20)
endif()

# TODO: V případě potřeby přidejte testy a cíle instalace.
