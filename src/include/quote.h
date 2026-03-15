#pragma once 

#include <string>

class Quote {
public:
    Quote(std::string quote, std::string author): quote(std::move(quote)), author(std::move(author)) {};

    std::string GetQuote() { return quote; }
    std::string GetAuthor() { return author; }
private:
    std::string quote;
    std::string author;
};

