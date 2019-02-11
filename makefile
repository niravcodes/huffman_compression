all:
	g++ -c help.C -o .help
	g++ -c huff.C -o .huff
	g++ -c param_parser.C -o .param_parser
	g++ .help .huff .param_parser -o huff