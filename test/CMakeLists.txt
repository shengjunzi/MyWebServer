file(GLOB WEB_TEST_SOURCES "${PROJECT_SOURCE_DIR}/test/*.cpp")
######################################################################################################################
# DEPENDENCIES
######################################################################################################################

######################################################################################################################
# MAKE TARGETS
######################################################################################################################

##########################################
# "make check-tests"
##########################################
add_custom_target(build-tests COMMAND ${CMAKE_CTEST_COMMAND} --show-only)
add_custom_target(check-tests COMMAND ${CMAKE_CTEST_COMMAND} --verbose)

##########################################
# "make server client ..."
##########################################
foreach (web_test_source ${WEB_TEST_SOURCES})
    # Create a human readable name.
    get_filename_component(web_test_filename ${web_test_source} NAME)
    string(REPLACE ".cpp" "" web_test_name ${web_test_filename})

    # Add the test target separately and as part of "make check-tests".
    add_executable(${web_test_name} EXCLUDE_FROM_ALL ${web_test_source})
    #依赖指定
    add_dependencies(build-tests ${web_test_name})
    add_dependencies(check-tests ${web_test_name})

    #链接动态库
    target_link_libraries(${web_test_name} web_shared)

    # Set test target properties and dependencies.
    set_target_properties(${web_test_name}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
        COMMAND ${web_test_name}
    )

endforeach(web_test_source ${WEB_TEST_SOURCES})