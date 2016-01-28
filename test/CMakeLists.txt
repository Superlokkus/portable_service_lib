add_executable(general_tests general_tests.cpp ${PORTABLE_SERVICE_LIBRARY_FILES} ${Boost_LIBRARIES})
set_property(TARGET general_tests PROPERTY CXX_STANDARD 11)
target_link_libraries(general_tests portable_service_lib ${Boost_LIBRARIES})

add_test(general_tests general_tests)