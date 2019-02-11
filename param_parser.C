#include "param_parser.h"
using namespace std;
parameter parse_options(unsigned char argc, char *argv[])
{
    if (argc == 1)
    { //invalid
        return {"", "", 0, true};
    }
    else
    {
        parameter options = {"", "a.out", true, false}; //default params
        for (unsigned i = 1; i <= argc; ++i)
        {
            if (argv[i] == string("-o"))
            {
                if ((i + 1) < argc) //make sure array bounds not exceeded
                    options.output_file = argv[++i];
                else //invalid
                    return {"", "", 0, true};
            }
            else if (argv[i] == string("-d"))
                options.encode = false;
            else
            {
                options.input_file = argv[i];
                break;
            }
        }
        return options;
    }
}
