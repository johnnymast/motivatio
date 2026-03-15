#include "include/quotes.h"

#include <random>

/**
 * @brief Constructor for the Quotes class.
 *        Parses the data from a JSON file and initializes the quotes vector.
 *
 * @details This constructor reads the data from a JSON file located at "../data.json".
 *          If the file is not empty and contains a "data" field, it iterates through
 *          each entry in the "data" array and adds a new Quote object to the quotes vector.
 *
 * @note The JSON file must be in the correct format with each entry having "quote" and "author" fields.
 *       If the file is empty or does not have a "data" field, the quotes vector will remain empty.
 */
Quotes::Quotes() {
    quotes = parser.ParseFilesAtDirectory(RESOURCE_INSTALL_PATH + std::string("/quotes"));
}


/**
 * @brief Retrieve a quote from the list of quotes by its index.
 *
 * @param index The index of the quote to retrieve.
 * @return An std::optional<Quote> object containing the quote at the specified index
 *         if it exists, or std::nullopt if the index is out of range.
 */
std::optional<Quote> Quotes::getQuote(size_t index) {
    if (index <= quotes.size()) {
        return quotes[index];
    }

    return std::nullopt;
}


/**
 * @brief Retrieve a random quote from the list of quotes.
 *
 * This method generates a random index between 0 and the total number of quotes
 * (exclusive) and retrieves the quote at that index using the getQuote method.
 *
 * @return An std::optional<Quote> object containing a random quote if the list
 *         is not empty, or std::nullopt if the list is empty.
 */
std::optional<Quote> Quotes::getRandomQuote() {
    std::random_device rd;

    // Seed the generator
    std::mt19937 gen(rd());

    // Create a uniform distribution between 0 and the total number of quotes (exclusive)
    std::uniform_int_distribution<> dis(0, quotes.size() - 1);

    // Generate a random index
    size_t random_index = dis(gen);

    return getQuote(random_index);
}
