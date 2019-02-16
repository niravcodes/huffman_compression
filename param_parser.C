#include "param_parser.h"
#include "help.h"
#include <sys/stat.h>
using namespace std;
input_param parse_options(unsigned char argc, char *argv[])
{
    if (argc == 1)
    { //invalid
        return {"", "", 0, true, 0, 0};
    }
    else
    {
        input_param options = {"", "a.out", true, false, false, false}; //default params
        for (unsigned i = 1; i <= argc; ++i)
        {
            if (argv[i] == string("-o"))
            {
                if ((i + 1) < argc) //make sure array bounds not exceeded
                    options.output_file = argv[++i];
                else //invalid
                    return {"", "", 0, true, 0};
            }
            else if (argv[i] == string("-d"))
                options.encode = false;
            else if (argv[i] == string("-t"))
                options.generate_table = true;
            else
            {
                options.input_file = argv[i];
                break;
            }
        }

        //check if input file exists
        struct stat file_info;
        if (stat(options.input_file.c_str(), &file_info) == 0)
        {
            options.input_file_size = file_info.st_size;
        }

        //return the parsed options
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
