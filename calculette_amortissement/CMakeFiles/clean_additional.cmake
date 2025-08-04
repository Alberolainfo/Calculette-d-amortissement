# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Release")
  file(REMOVE_RECURSE
  "CMakeFiles\\CalculetteAmortissement_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\CalculetteAmortissement_autogen.dir\\ParseCache.txt"
  "CalculetteAmortissement_autogen"
  )
endif()
