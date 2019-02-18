#ifndef _PARAM_PARSER_H
#define _PARAM_PARSER_H
#include <string>
struct input_param
{
    std::string input_file;
    std::string output_file;
    bool encode;
    bool invalid;
    unsigned input_file_size;
    bool generate_table;
    bool generate_code;
    bool verbose;

    input_param() : input_file(""), output_file("a.huff"),
                    encode(true), invalid(true),
                    input_file_size(0), generate_table(false),
                    generate_code(false), verbose(false) {}
};
input_param parse_options(unsigned char argc, char *argv[]);
bool show_help_if_option_invalid(input_param);

#endif