#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>

#include "param_parser.h"
#include "help.h"
#include "corelib/huffman.h"
#include "corelib/tree_printer.h"

using namespace std;

int main(int argc, char *argv[])
{
	input_param options = parse_options(argc, argv);
	if (show_help_if_option_invalid(options))
	{
		// The options were stupid enough to warrant a full exit
		return 1;
	}

	tree *huffman = make_huffman_tree(options);
	print_tree(huffman);
	delete huffman;
	return 0;
}
