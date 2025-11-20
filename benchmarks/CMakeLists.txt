file(GLOB BENCH_SOURCES *.cpp)

add_executable(run_benchmarks ${BENCH_SOURCES})
target_link_libraries(run_benchmarks PRIVATE lfde)

