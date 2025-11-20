add_subdirectory(googletest)

file(GLOB TEST_SOURCES *.cpp)

add_executable(run_tests ${TEST_SOURCES})
target_link_libraries(run_tests PRIVATE gtest gtest_main lfde)

add_test(NAME run_tests COMMAND run_tests)

