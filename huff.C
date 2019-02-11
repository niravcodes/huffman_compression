#include <iostream>
#include <fstream>
#include <string>
#include <sys/stat.h>

#include "param_parser.h"
#include "help.h"

using namespace std;

int main(int argc, char *argv[])
{
	parameter options = parse_options(argc, argv);
	unsigned size;
	if (options.invalid)
	{
		print_help();
		return 0;
	}

	struct stat file_info;
	if (stat(options.input_file.c_str(), &file_info) == 0)
	{
		size = file_info.st_size;
	}
	else
	{
		print_help("Please enter a valid file");
		print_help();
		return 1;
	}

	ifstream in_file;
	in_file.open(options.input_file, ios::binary | ios::in);

	char byte;

	unsigned count[256];
	for (int i = 0; i < 256; i++)
		count[i] = 0;

	for (int i = 0; i < size; ++i)
	{
		in_file >> byte;
		count[(unsigned char)byte]++;
	}

	unsigned total = 0;
	for (int i = 0; i < 256; i++)
	{
		total += count[i];
		cout << i << " : " << count[i] << endl;
	}
	for (int i = 0; i < 256; i++)
		cout << i << " : " << ((double)count[i] / total) << endl;
}
