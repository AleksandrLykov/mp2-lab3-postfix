set(target ${MP2_TESTS})

file(GLOB hdrs "*.h*")
file(GLOB srcs "*.cpp")

add_definitions(/D_VARIADIC_MAX=10)

add_executable(${target} ${srcs} ${hdrs})
target_link_libraries(${target} gtest ${MP2_LIBRARY})
