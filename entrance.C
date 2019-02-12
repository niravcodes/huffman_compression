#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>

#include "param_parser.h"
#include "help.h"
#include "corelib/huffman.h"

using namespace std;

int main(int argc, char *argv[])
{
	input_param options = parse_options(argc, argv);
	if (show_help_if_option_invalid(options))
	{
		// The options were stupid enough to warrant a full exit
		return 1;
	}

	huffman(options);
}
