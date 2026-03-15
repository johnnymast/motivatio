#include "include/cli.h"

#include <cxxopts.hpp>
#include <iostream>

#include "include/styles.h"


/**
 * @brief Handles the user input and returns the selected style.
 *
 * The handle method parses the command line arguments provided by the user
 * using the cxxopts library. It looks for the "style" argument and retrieves
 * its value if it is specified. If the "help" argument is present, it prints
 * the usage information and returns 0. Otherwise, it returns the default style
 * or the style specified by the user.
 *
 * @return The selected style.
 */
int Cli::handle(int argc, char *argv[]) {
    int style = Style::DEFAULT;

    cxxopts::Options opts(argv[0], "Motivatio, display a random quote.");


    opts.add_options()
           ("s,style", "Style to use [0-3]", cxxopts::value<int>())
           ("h,help", "Print usage");

    try {
        //char** argv_tmp = argv.data();
        auto result = opts.parse(argc, argv);

        if (result.count("help")) {
            std::cout << opts.help() << std::endl;
            return 0;
        }

        if (result.count("style")) {
            style = result["style"].as<int>();
        }
    } catch (const cxxopts::exceptions::no_such_option& e) {
        std::cerr << "Error: unknown option: " << e.what() << "\n\n";
        std::cerr << opts.help() << "\n";
        return CLI_ERROR;

    } catch (const cxxopts::exceptions::exception& e) {
        std::cerr << "Error while parsing options: " << e.what() << "\n\n";
        std::cerr << opts.help() << "\n";
        return CLI_ERROR;
    }

    return style;
}
