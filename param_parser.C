//TODO: make the input_param struct a class so that I don't have to change 20 places just to add a new option
#include "param_parser.h"
#include "help.h"
#include <sys/stat.h>
using namespace std;
input_param parse_options(unsigned char argc, char *argv[])
{
    input_param options;
    if (argc == 1)
    { //invalid
        return options;
    }
    else
    {
        for (unsigned i = 1; i <= argc; ++i)
        {
            if (argv[i] == string("-o") || argv[i] == string("--output"))
            {
                if ((i + 1) < argc) //make sure array bounds not exceeded
                    options.output_file = argv[++i];
                else //invalid
                    return options;
            }
            else if (argv[i] == string("-d") || argv[i] == string("--decode"))
                options.encode = false;
            else if (argv[i] == string("-t") | argv[i] == string("--table")) //debug use
                options.generate_table = true;
            else if (argv[i] == string("-v") || argv[i] == string("--verbose"))
                options.verbose = true;
            else if (argv[i] == string("-c") || argv[i] == string("--code_only"))
            {
                options.verbose = false;
                options.generate_code = true;
            }
            else
            {
                options.input_file = argv[i];
                break;
            }
        }

        //check if input file exists
        if (options.input_file == "")
            return options;

        struct stat file_info;
        if (stat(options.input_file.c_str(), &file_info) == 0)
        {
            options.input_file_size = file_info.st_size;
        }
        else
            return options;

        //return the parsed options
        options.invalid = false;
        return options;
    }
}

bool show_help_if_option_invalid(input_param options)
{
    if (options.invalid)
    {
        print_help();
        return true;
    }
    if (options.input_file_size == 0)
    {
        print_help("Input file doesn't exist.");
        print_help();
        return true;
    }
    return false;
}
