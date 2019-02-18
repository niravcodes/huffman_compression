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
		 << "-t\t\tOutput table while encoding" << endl
		 << "-v\t\tDisplay progressbar" << endl
		 << "-c\t\tOutput header to STDOUT or read header from STDIN" << endl
		 << endl
		 << "Huff encodes or decodes your file with huffman algorithm" << endl
		 << endl
		 << "Written by Nirav (nirav.com.np)" << endl;
}
void print_help(string help)
{
	cout << help << endl;
}