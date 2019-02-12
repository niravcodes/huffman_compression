.PHONY : all _build_for_test

all:
	@echo
	@echo "Building normal programs"
	g++ -c help.C -o .help
	g++ -c entrance.C -o .entrance
	g++ -c param_parser.C -o .param_parser
	g++ -c corelib/huffman.C -o .huffman
	g++ -c corelib/tree.C -o .tree
	g++ -c corelib/priority_queue.C -o .priority_queue
	g++ .help .entrance .param_parser .huffman .tree .priority_queue -o huff

test:	all _build_for_test

_build_for_test:
	@echo
	@echo
	@echo "Building test programs"
	g++ -c tests/priority_queue.C -o tests/.priority_queue
	g++ tests/.priority_queue .tree .priority_queue -o tests/priority_queue

runtestpq:
	@echo
	@echo
	@echo "Running Priority Queue Test"
	tests/priority_queue