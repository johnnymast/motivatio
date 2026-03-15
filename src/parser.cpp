#include "include/parser.h"

/**
 * @brief Parse the JSON file and return the JSON data.
 *
 * This method reads the JSON file located at the given file_path and parses it using nlohmann::json library.
 * The resulting JSON data is returned.
 *
 * @param file_path The path to the JSON file to be parsed.
 *
 * @return The nlohmann::json object containing the parsed JSON data.
 */
std::vector<Quote> Parser::ParseFile(const std::string& file_path) {
    nlohmann::json m_quotes;

    std::ifstream i(file_path);
             i >> m_quotes;

    if (!m_quotes.empty() && m_quotes.contains("data")) {
        for (auto &entry: m_quotes["data"]) {
            result.push_back(Quote(entry["quote"], entry["author"]));
        }
    }

    return result;
}

std::vector<Quote> Parser::ParseFilesAtDirectory(const std::string &path) {

    for(const auto & entry : std::filesystem::__cxx11::directory_iterator(path))
    {
        if(entry.path().extension() == ".json") {
            ParseFile((entry.path()));
        }
    }

    return result;
}

