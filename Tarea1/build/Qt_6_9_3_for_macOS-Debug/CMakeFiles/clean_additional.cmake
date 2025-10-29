# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/Tarea1_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/Tarea1_autogen.dir/ParseCache.txt"
  "Tarea1_autogen"
  )
endif()
