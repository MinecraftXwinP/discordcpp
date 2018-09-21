#ifndef _H_FILE_UTILS_
#define _H_FILE_UTILS_

#include <string>


namespace discordcpp {
    class file_utils {
        public:
            static bool file_exists(const std::string& path);
    };
};


#endif