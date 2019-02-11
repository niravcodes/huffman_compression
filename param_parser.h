#ifndef _PARAM_PARSER_H
#define _PARAM_PARSER_H
#include <string>
struct parameter
{
    std::string input_file;
    std::string output_file;
    bool encode;
    bool invalid;
};
parameter parse_options(unsigned char argc, char *argv[]);
#endif