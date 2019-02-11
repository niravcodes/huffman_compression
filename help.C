#include <iostream>
#include <string>
using namespace std;

void print_help()
{
	cout << "Usage: huff [options] input_file" << endl
		 << endl
		 << "Options:" << endl
		 << "-o output_file\tName of file to write to" << endl
		 << "-d\t\tDecode a huffman encoded file" << endl
		 << endl
		 << "Huff encodes or decodes your file with huffman algorithm" << endl
		 << endl
		 << "Written by Nirav from nirav.com.np" << endl;
}
void print_help(string help)
{
	cout << help << endl;
}