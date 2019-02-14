#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>

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

	//debug
	ifstream in_file;
	in_file.open(options.input_file, ios::binary | ios::in);
	unsigned *ct = count_frequency(in_file, options.input_file_size);
	//enddebug
	tree *huffman_tree = make_huffman_tree(options);
	huffman_code *huff_code = generate_code(huffman_tree);

	for (int i = 0; i < 256; i++)
	{
		cout << i << "\t\t";
		cout << setw(16) << print_bits<unsigned>(huff_code[i].get_code(), huff_code[i].get_size());
		cout << "       ";
		cout << huff_code[i];
		cout << "\t\t\t\t";
		cout << ct[i] << endl;
	}

	delete ct;
	delete huffman_tree;
	delete huff_code;
	return 0;
}
