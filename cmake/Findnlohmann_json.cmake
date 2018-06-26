include(FindPackageHandleStandardArgs)

find_path(
    nlohmann_json_INCLUDE_DIRS
    HINTS
				${NLOHMANN_JSON_DIR}
        ENV NLOHMANN_JSON_DIR
    NAMES
    nlohmann/json.hpp
)

find_package_handle_standard_args(
    nlohmann_json
    DEFAULT_MSG
    nlohmann_json_INCLUDE_DIRS
)
