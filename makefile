all:
	g++ -c help.C -o .help
	g++ -c entrance.C -o .entrance
	g++ -c param_parser.C -o .param_parser
	g++ -c huffman.C -o .huffman
	g++ .help .entrance .param_parser .huffman -o huff