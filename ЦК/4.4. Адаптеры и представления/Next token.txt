#include <string_view>

bool NextToken(std::string_view& sv, const char delimiter, std::string_view& token) {
    if (sv.empty()) {
        return false;
    }
    size_t pos = sv.find(delimiter);
    if (pos == std::string_view::npos) {
        token = sv;
        sv = "";
    } else {
        token = sv.substr(0, pos);
        sv.remove_prefix(pos + 1);
    }
    return true;
}