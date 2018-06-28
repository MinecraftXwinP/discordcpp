#ifndef _H_PERSISTENT_STATE_
#define _H_PERSISTENT_STATE_

#include <nlohmann/json.hpp>
#include <string>

namespace discordcpp {
    class persistent_state {
        public:
            persistent_state(const std::string path);
            void save() const;
            void load();
            nlohmann::json::reference operator[](const std::string& key);
        private:
            std::string path;
            nlohmann::json value;
    };
};
#endif