# huffman_compression
The implementation of the Huffman algorithm as a command line utility.

## Usage
Usage: huff [options] input_file  

Options:  
    -o output_file      : Mention the output file. By default a.out  
    -d                  : Decompress instead of compressing the file  

## Source Directory Structure
The main directory contains all the "fluff" code. It's the interface that the end user
interacts with. The main libraries are found in `corelib` folder. It contains all the data 
structures and algorithms needed to implement Huffman. 

You might notice that the data structures I implemented were already there in the STL. 
I rewrote them anyway because this is supposed to be somewhat educational for me and 
of course, the the whole reason I code is to be able to say stuff like "Yeah, I implemented the 
priority queue but didn't use heap because I don't like writing tree traversal algorithms."


## Building
Build with

    make

The program "huff" should appear.

To compile test programs for the core libraries, you can 

    make test

The test programs should compile to `tests/` directory

## File structure
The first 12 bytes of the output file are the file signature. 
By default it's the character sequence "nirav.com.np" (because, why not? :3). After that 4 bytes
store the length of huffman table in little endian. After that everything that follows is the 
compressed data.

## Caveats
Not ready to be used in anything remotely serious so far. At some point I intend to 
make it robust and dependable. But as of now, it is just an experiment.

## Vague plans
1. Compress folders
2. Try to mix with some other simple compression algorithm like RLE and compare efficiency.
3. Try various approaches to decoding Huffman

## Progess
This project is (as of Feb 12, 2019) not complete. I intend to finish it by the end of this month.

More on [nirav.com.np](https://nirav.com.np)