add_test([=[KeyValueTableTest.AddKeyValue]=]  /Users/vlish21/University/Algorithms-and-Data-Structure/lab3/UnitTesting/cmake-build-debug/UnitTesting [==[--gtest_filter=KeyValueTableTest.AddKeyValue]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[KeyValueTableTest.AddKeyValue]=]  PROPERTIES WORKING_DIRECTORY /Users/vlish21/University/Algorithms-and-Data-Structure/lab3/UnitTesting/cmake-build-debug SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[KeyValueTableTest.RemoveKey]=]  /Users/vlish21/University/Algorithms-and-Data-Structure/lab3/UnitTesting/cmake-build-debug/UnitTesting [==[--gtest_filter=KeyValueTableTest.RemoveKey]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[KeyValueTableTest.RemoveKey]=]  PROPERTIES WORKING_DIRECTORY /Users/vlish21/University/Algorithms-and-Data-Structure/lab3/UnitTesting/cmake-build-debug SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
add_test([=[KeyValueTableTest.GetValue]=]  /Users/vlish21/University/Algorithms-and-Data-Structure/lab3/UnitTesting/cmake-build-debug/UnitTesting [==[--gtest_filter=KeyValueTableTest.GetValue]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[KeyValueTableTest.GetValue]=]  PROPERTIES WORKING_DIRECTORY /Users/vlish21/University/Algorithms-and-Data-Structure/lab3/UnitTesting/cmake-build-debug SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  UnitTesting_TESTS KeyValueTableTest.AddKeyValue KeyValueTableTest.RemoveKey KeyValueTableTest.GetValue)