#include "file_utils.hpp"
#include <sys/stat.h>


namespace discordcpp {
    bool file_utils::file_exists(const std::string& path) {
        struct stat buffer;
        return (stat(path.c_str(), &buffer) == 0);
    }
}
