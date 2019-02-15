.PHONY : all _build_for_test

all: help.C entrance.C param_parser.C corelib/huffman.C corelib/tree.C 
	@echo
	@echo "Building normal programs"
	g++ -c help.C -o .help
	g++ -c entrance.C -o .entrance
	g++ -c param_parser.C -o .param_parser
	g++ -c corelib/huffman.C -o .huffman
	g++ -c corelib/tree.C -o .tree
	g++ -c corelib/bitstream.C -o .bitstream
	g++ .help .entrance .param_parser .huffman .tree .bitstream -o huff

test:	all _build_for_test

_build_for_test: tests/priority_queue.C tests/queue.C
	@echo
	@echo
	@echo "Building test programs"
	g++ -c tests/priority_queue.C -o tests/.priority_queue
	g++ -c tests/queue.C -o tests/.queue
	g++ -c tests/bitstream.C -o tests/.bitstream

	g++ tests/.priority_queue .tree -o tests/priority_queue
	g++ tests/.queue .tree -o tests/queue
	g++ tests/.bitstream .bitstream -o tests/bitstream

runtestpq:
	@echo
	@echo
	@echo "Running Priority Queue Test"
	tests/priority_queue

runtestq:
	@echo
	@echo
	@echo "Running Queue Test"
	tests/queue


runtestq:
	@echo
	@echo
	@echo "Running Bitstream Test"
	tests/bistream