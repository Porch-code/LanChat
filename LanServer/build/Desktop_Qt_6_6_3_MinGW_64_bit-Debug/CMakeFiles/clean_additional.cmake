# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\LanServer_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\LanServer_autogen.dir\\ParseCache.txt"
  "LanServer_autogen"
  )
endif()
