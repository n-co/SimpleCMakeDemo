function(get_git_hash output_var)
    find_package(Git QUIET)
    set(_output_var "")
    if(GIT_FOUND)
        execute_process(
            COMMAND git log -1 --pretty=format:%H
            OUTPUT_VARIABLE _output_var
            OUTPUT_STRIP_TRAILING_WHITESPACE
            ERROR_QUIET
        )
    endif()
    if(${_output_var} STREQUAL "")
        set(_output_var "unknown")
    endif()
    set("${output_var}"
        "${_output_var}"
        PARENT_SCOPE)
endfunction()
