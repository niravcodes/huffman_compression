# Huffman Compression Program

[![Build Status](https://travis-ci.org/niravcodes/huffman_compression.svg?branch=master)](https://travis-ci.org/niravcodes/huffman_compression)

The implementation of the Huffman algorithm as a command line utility. Huffman coding is an entropy compression algorithm which essentially formalizes and presents an implementation for the basic idea that higher probability alphabets should be encoded with shorter codes. Huffman codes are variable length prefix code i.e. no two codes start with the same bit pattern. {10, 101, 10110} would be an invalid set of codes while {0, 10, 110, 1110} would be valid.

Read detailed blog post at [**the corresponding post**](https://nirav.com.np/2019/02/14/writing-huffman-compression-in-cpp.html) on my blog.

## Usage
Usage: huff [options] input_file  

Options:  

    --output output_file
    -o output_file          : Set output file name. By default a.huff  

    --decompress
    -d                      : Decompress already compressed file  

    --table
    -t                      : Output a table with details on compression

    --verbose
    -v                      : Print progress bar and other information

    --code_table
    -c                      : When encoding, prints out huffman code table 
                                to stdout instead of in file
                            : When decoding, accepts huffman code table from 
                                stdin and decodes a headerless binary

## Examples

### Compression:

        ./huff filename.mkv                      (Compressed file stored as a.huff)        
        ./huff -o compressed.huff filename.pdf   (compressed file stored as compressed.huff)
        ./huff -v -o compressed.huff file.pdf    (Compresses with progress report)
        ./huff -t -o comp.huff a.flv             (Outputs huffman table and other info after compression)
        ./huff -c somefile.tar > table.txt       (Compresses but doesn't prepend header to compressed file.
                                                    Outputs header file separately to table.txt)

### Decompression:

        ./huff -d a.huff                         (Decodes a.huff to a.dhuff)
        ./huff -d -c a.huff < table.txt          (Decodes tableless a.huff to a.dhuff based on table.txt)
        ./huff -v -d a.huff                      (Displays progress bar. You might to turn it on because
                                                    it takes very long to decompress currently.)

## Source Directory Structure
The main directory contains code for the command line interface. The important ones are:

1. entrance.C       :   The entrance to the program
2. param_parser.C   :   Code to parse the command line options. Could have used
                        a POSIX/GNU compliant parser but didn't.
3. help.C           :   The code for outputing help and usage deatils. Kept separate
                        to avoid clutter

The libraries are kept in `corelib` folder. It contains the implementations 
of data structures and algorithms reuired for huffman. The libraries are:

    1. huffman*         :   Implementation of Huffman's algorithm.
    2. priority_queue   :   Naive implementation of priority queue, and
                            of queue as a specialization of priority queue.
    3. bitstream        :   A class that accepts arbitrarily sized bits and packs them
                            together.
    4. tree             :   A very specific implementation of binary tree.

The `debughelpers` folder contains code I wrote to help me debug the program. It
contains simple functions to present data in memory in a way I can understand.

Finally the `tests` folder contains some code I wrote to unit test the implementations of
data structures and algorithms.

You might notice that a lot of the code in `corelib` is already implemented in the STL. 
I rewrote them anyway because I wanted to try my hand at memory management, implementing
classes, designing abstractions and so on. 

## Building
Download the codebase with the git clone command.
> git clone https://github.com/niravcodes/huffman_compression.git 

Build with the make command.

> cd huffman_compression

> make

The program "huff" should appear in the main directory. Try
> ./huff 

It should output usage details.

To compile test programs for the core libraries, you can 

    make test

The test programs should compile to `tests/` directory

To clean the source directory, type 
    
    make clean

## File format 
1. The first 12 bytes of the output file are the file signature/magic number. By default it's the character sequence "nirav.com.np" (because, why not? :3).
2. Next a huffman table is placed in the format [`alphabet(1 byte)`|`huffman code length(1 byte)`|`huffman code(4 byte)`] sorted in accending order with respect to `alphabet`. Alphabets with zero frequency are not stored in the table. The table ends with the occurence `0x00` in column `alphabet`.
3. The `0x00` is followed by 4 bytes of the decompressed file size in bits. (This should be increased to support more than 512MB of data)
4. Finally, everything succeding the data from entry 1, 2, 3 is the compressed data. The final byte is padded with zero bits.

## Caveats
**EXTREMELY SLOW DECOMPRESSION** - I intend to address this issue soon. But for now, the decompression is very slow (because a linear search with worst case 256 items has to be performed for **every bit in the file**). I call this naive decompression. My next attempt will be to reconstruct huffman tree from the table in file header and traverse the tree for every bit. Then, I might look into other methods. I've skimmed through some papers on huffman decoding and they are pretty interesting.

**Not optimised for anything** - This implementation is neither fast, nor memory efficient or better in any than other implementations. It likes to repeat to itself "if only the best birds sang how silent the woods would be" when it can't sleep at night.

**Not ready for serious use** - Of course, given how the huffman compression utility `pack` has been deprecated for years, there is hardly any reason to use bare huffman over other compression methods (which also heavily rely on huffman but process data in different stages with predictive compression techniques).

**The codebase could use some refactoring** - As it currently stands, the codebase could has some over-engineered parts and some lousily written portions. There are minor issues code duplication, some redundancies, some architectural issues, some lazily written code and some algorithms that could be subtituted for better ones without any loss in readability.

## <s>Vague plans</s>
1. <s>Compress folders.</s> (tar before or after compression, no biggie)
2. Try to mix with some other simple compression algorithms like RLE and compare efficiency.
3. Try various approaches to decoding Huffman

## Progess
<s>Released version 1.0.0 with basic compression and decompression. Plans to optimise, refactor and benchmark.</s> All plans are cancelled. As it stands, the program will do basic huffman encoding and decoding for you. But that's about it.

More  on [nirav.com.np](https://nirav.com.np)
