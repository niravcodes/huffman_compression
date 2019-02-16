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

		unsigned long file_size = 0;
		unsigned *count = count_frequency(options);

		cout << "Byte\t\t\tCode\t\t\tSize\t\t\tFrequency" << endl;
		for (int i = 0; i < 256; i++)
		{
			cout << i << "\t\t\t";
			cout << huff_code[i].get_code() << "\t\t\t";
			cout << huff_code[i].get_size() << "\t\t\t";
			cout << count[i] << endl;
			file_size += count[i] * huff_code[i].get_size(); //frequency * code size
		}
		cout << "Resulting size in bytes: " << file_size / 8 << endl;
		cout << "Resulting size in MB: " << file_size / (8 * 1024 * 1024) << "MB" << endl;

		delete[] count;
		delete huffman_tree;
		delete huff_code;
	}
	return 0;
}
