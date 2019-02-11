all:
	g++ -c help.C -o .help
	g++ -c entrance.C -o .entrance
	g++ -c param_parser.C -o .param_parser
	g++ -c corelib/huffman.C -o .huffman
	g++ -c corelib/tree.C -o .tree
	g++ -c corelib/priority_queue.C -o .priority_queue
	g++ .help .entrance .param_parser .huffman .tree .priority_queue -o huff