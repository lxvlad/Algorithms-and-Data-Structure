if(EXISTS "/Users/vlish21/University/Algorithms-and-Data-Structure/lab8/UnitTesting/cmake-build-debug/UnitTesting[1]_tests.cmake")
  include("/Users/vlish21/University/Algorithms-and-Data-Structure/lab8/UnitTesting/cmake-build-debug/UnitTesting[1]_tests.cmake")
else()
  add_test(UnitTesting_NOT_BUILT UnitTesting_NOT_BUILT)
endif()