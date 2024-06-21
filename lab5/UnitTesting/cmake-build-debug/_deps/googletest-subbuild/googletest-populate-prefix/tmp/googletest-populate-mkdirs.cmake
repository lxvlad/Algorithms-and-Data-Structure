# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.5)

file(MAKE_DIRECTORY
  "/Users/vlish21/University/Algorithms-and-Data-Structure/lab5/UnitTesting/cmake-build-debug/_deps/googletest-src"
  "/Users/vlish21/University/Algorithms-and-Data-Structure/lab5/UnitTesting/cmake-build-debug/_deps/googletest-build"
  "/Users/vlish21/University/Algorithms-and-Data-Structure/lab5/UnitTesting/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix"
  "/Users/vlish21/University/Algorithms-and-Data-Structure/lab5/UnitTesting/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/tmp"
  "/Users/vlish21/University/Algorithms-and-Data-Structure/lab5/UnitTesting/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
  "/Users/vlish21/University/Algorithms-and-Data-Structure/lab5/UnitTesting/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src"
  "/Users/vlish21/University/Algorithms-and-Data-Structure/lab5/UnitTesting/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp"
)

set(configSubDirs )
foreach(subDir IN LISTS configSubDirs)
    file(MAKE_DIRECTORY "/Users/vlish21/University/Algorithms-and-Data-Structure/lab5/UnitTesting/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp/${subDir}")
endforeach()
if(cfgdir)
  file(MAKE_DIRECTORY "/Users/vlish21/University/Algorithms-and-Data-Structure/lab5/UnitTesting/cmake-build-debug/_deps/googletest-subbuild/googletest-populate-prefix/src/googletest-populate-stamp${cfgdir}") # cfgdir has leading slash
endif()
