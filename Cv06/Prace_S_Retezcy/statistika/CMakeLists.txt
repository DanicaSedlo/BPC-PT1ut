﻿# CMakeList.txt: Projekt CMake pro statistika, sem přidejte logiku zdrojového
# kódu a definic specifickou pro projekt.
#

# Přidejte zdrojový kód ke spustitelnému souboru tohoto projektu.
add_executable (statistika "statistika.cpp" "statistika.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET statistika PROPERTY CXX_STANDARD 20)
endif()

# TODO: V případě potřeby přidejte testy a cíle instalace.
