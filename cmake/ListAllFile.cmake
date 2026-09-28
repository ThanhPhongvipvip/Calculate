# Function to list all source files from a directory
function(list_all_files directory output_variable)
    # Check if the directory exists
    if (IS_DIRECTORY ${directory})
        # Recursively find all .cpp and .h files
        file(GLOB_RECURSE files CONFIGURE_DEPENDS
            "${directory}/*.cpp"
            "${directory}/*.h")
        set(${output_variable} ${files} PARENT_SCOPE)
    endif()
endfunction()
