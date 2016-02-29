set(target "gtest")

#add_definitions(/D_GTEST_HAS_TR1_TUPLE=0)
#add_definitions(/D_GTEST_USE_OWN_TR1_TUPLE=1)
add_definitions(/D_VARIADIC_MAX=10)

add_library(${target} STATIC gtest-all.cc)

if((${CMAKE_CXX_COMPILER_ID} MATCHES "GNU" OR
    ${CMAKE_CXX_COMPILER_ID} MATCHES "Clang") AND
    (${CMAKE_SYSTEM_NAME} MATCHES "Linux"))
    set(pthread "-pthread")
endif()

target_link_libraries(${target} ${pthread})
