cmake_minimum_required (VERSION 3.2.3)

###############################################################################

function(create_executable BINARY_NAME SOURCE_FILE)
    add_executable(${BINARY_NAME} ${SOURCE_FILE})
    target_link_libraries(${BINARY_NAME}
    )
endfunction(create_executable)

###############################################################################

create_executable(generate_random
    ./generate_random.cpp
)
