.PHONY : all _build_for_test bs

all: help.C entrance.C param_parser.C corelib/huffman.C corelib/tree.C 
	@echo
	@echo "Building normal programs"
	g++ -g -c help.C -o .help
	g++ -g -c entrance.C -o .entrance
	g++ -g -c param_parser.C -o .param_parser
	g++ -g -c corelib/huffman.C -o .huffman
	g++ -g -c corelib/huffman_output.C -o .huffman_o
	g++ -g -c corelib/huffman_decode.C -o .huffman_d
	g++ -g -c corelib/tree.C -o .tree
	g++ -g -c corelib/bitstream.C -o .bitstream
	g++ -g -c corelib/bitqueue.C -o .bitqueue
	g++ .help .entrance .param_parser .huffman .tree .bitstream .bitqueue .huffman_o .huffman_d -o huff

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

testbitq:
	@echo
	@echo
	@echo "Testing Bitqueue"
	g++ -g -c corelib/bitqueue.C -o .bitqueue
	g++ -g -c tests/bitqueue.C -o tests/.bitqueue
	g++ tests/.bitqueue .bitqueue -o tests/bitqueue
	tests/bitqueue

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
	rm .bitstream .help .huff .huffman* .priority_queue .param_parser .tree .bitqueue .tree_printer .entrance