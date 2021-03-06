.PHONY : all _build_for_test bs

all: help.C entrance.C param_parser.C corelib/huffman.C corelib/tree.C 
	@echo
	@echo "Building normal programs"
	$(CXX) -c help.C -o .help
	$(CXX) -c entrance.C -o .entrance
	$(CXX) -c param_parser.C -o .param_parser
	$(CXX) -c corelib/huffman.C -o .huffman
	$(CXX) -c corelib/huffman_output.C -o .huffman_o
	$(CXX) -c corelib/huffman_decode.C -o .huffman_d
	$(CXX) -c corelib/tree.C -o .tree
	$(CXX) -c corelib/bitstream.C -o .bitstream
	$(CXX) .help .entrance .param_parser .huffman .tree .bitstream .huffman_o .huffman_d -o huff

test:	all _build_for_test

testbs: all bs

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


bs:
	@echo
	@echo
	@echo "Running Bitstream Test"
	g++ -c tests/bitstream.C -o tests/.bitstream
	g++ tests/.bitstream .bitstream -o tests/bitstream
	./tests/bitstream

clean:
	@echo
	@echo "Cleaning up the binaries"
	rm .bitstream .help .huff .huffman* .priority_queue .param_parser .tree .tree_printer .entrance
