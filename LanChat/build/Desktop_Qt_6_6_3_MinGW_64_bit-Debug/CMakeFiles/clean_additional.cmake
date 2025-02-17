# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\LanChat_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\LanChat_autogen.dir\\ParseCache.txt"
  "LanChat_autogen"
  )
endif()
