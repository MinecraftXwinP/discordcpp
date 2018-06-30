#include "persistent_state.hpp"
#include <fstream>
#include <exception>

namespace discordcpp {
    persistent_state::persistent_state(const std::string path): path(path){}

    void persistent_state::save() const {
        std::ofstream f(path, std::ios::out | std::ios::binary);
        if (f.good()) {
            std::vector<char> out;
            nlohmann::json::to_cbor(value, out);
            f.write(out.data(), out.size());
        } else {
            throw std::runtime_error("persistent_state: save error");
        }
    }

    void persistent_state::load() {

        if (!file_utils::file_exists(path)) {
            return;
        }

        std::ifstream f(path, std::ios::binary);

        if (f.good()) {
            std::vector<uint8_t> buf(
                (std::istreambuf_iterator<char>(f)),
                std::istreambuf_iterator<char>()
            );
            value = nlohmann::json::from_cbor(buf);
        } else {
            throw std::runtime_error("persistent_state: read error");
        }
    }

    nlohmann::json::reference persistent_state::operator[](const std::string& key) {
        return value[key];
    }
};