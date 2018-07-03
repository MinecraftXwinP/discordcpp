find_package(Boost REQUIRED)


set(build_boost_worklist)
mark_as_advanced(build_boost_worklist)

macro(import_boost moduleName include_dir)
    set(libraryName boost_${moduleName})
    add_library(${moduleName} UNKNOWN IMPORTED)
    target_include_directories(${moduleName} PUBLIC ${include_dir})
endmacro(import_boost)

macro(boost_header_only moduleName)
    if(BOOST_FOUND)
        # found boost, try find header.
        find_path(
            include_dir
            NAMES ${moduleName}/${moduleName}.hpp
            PATHS ${BOOST_INCLUDE_DIR}
        )
        mark_as_advanced(include_dir)

        if(include_dir)
            import_boost(${moduleName} ${BOOST_INCLUDE_DIR})
        else()
            list(APPEND build_boost_worklist ${moduleName})
        endif()
    endif()
endmacro(boost_header_only moduleName)

# macro(build_boost_module moduleName)
#     include(ExternalProject)
#     ExternalProject_Add(
#         build_boost_${moduleName}
#         GIT_REPOSITORY https://github.com/boostorg/${moduleName}.git
#         CONFIGURE_COMMAND ./bootstrap
#     )
# endmacro(build_boost_module)

macro(boost_dep_done)
    if(build_boost_worklist)
        message(Cannot find ${build_boost_worklist}, will build them)
        include(ExternalProject)
        ExternalProject
    endif
endmacro(boost_dep_done)

