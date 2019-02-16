#include <iostream>
#include <fstream>
#include <string>

#include "param_parser.h"
#include "help.h"
#include "corelib/huffman.h"
#include "debughelpers/tree_printer.h"
#include "debughelpers/bit_printer.h"

using namespace std;

int main(int argc, char *argv[])
{
	input_param options = parse_options(argc, argv);
	if (show_help_if_option_invalid(options))
	{
		// The options were stupid enough to warrant a full exit
		return 1;
	}

	if (options.encode)
	{
		tree *huffman_tree = make_huffman_tree(options);
		huffman_code *huff_code = generate_code(huffman_tree);
		if (encode_file(huff_code, options) == 0)
		{
			//job done
			cout << "file compressed" << endl;
		}

		delete huffman_tree;
		delete huff_code;
	}
	else
	{
		cout << "in construction" << endl;
	}
	if (options.generate_table)
	{
		tree *huffman_tree = make_huffman_tree(options);
		huffman_code *huff_code = generate_code(huffman_tree);
		if (gen_table(huff_code, options) == 0)
		{
			//job done
			cout << "file compressed" << endl;
		}

		delete huffman_tree;
		delete huff_code;
	}
	return 0;
}
