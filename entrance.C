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
		if (options.verbose)
			cout << "Generating Huffman Tree" << endl;
		tree *huffman_tree = make_huffman_tree(options);

		if (options.verbose)
			cout << "Generating Huffman Code" << endl;
		huffman_code *huff_code = generate_code(huffman_tree);

		if (options.verbose)
			cout << "Encoding file" << endl;
		if (encode_file(huff_code, options) == 0)
		{
			//job done
		}

		delete huffman_tree;
		delete huff_code;

		if (options.generate_code)
			output_code(options);
		if (options.generate_table)
			output_table(options);
	}
	else
	{
		if (options.generate_code)
		{
			huffman_code *huff_code = reconstruct_code_from_ascii();
			if (options.verbose)
				cout << "Decoding with naive_decode implementation." << endl;
			naive_decode(huff_code, options);
		}
		else
		{
			naive_decode_with_header(options);
		}
	}

	return 0;
}
