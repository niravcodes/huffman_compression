#ifndef _BITSTREAM_H
#define _BITSTREAM_H

#define DEFAULT_BUFFER_SIZE 128 * 1024
class bitstream
{
private:
  unsigned char *buffer;
  unsigned buffer_size; //inbytes
  unsigned bit_pos;     //inbits

  unsigned remainder;
  unsigned remainder_size;

  int micropack(unsigned char, unsigned);
  unsigned get_free_bits();

public:
  bitstream();
  bitstream(unsigned);
  ~bitstream();

  //packs data into buffer upto specified size
  //returns -1 if buffer overflow.
  //0 if okay
  int pack(unsigned, unsigned);
  //gives you a pointer to the buffer
  unsigned char *flush_buffer();
  //clears the buffer then packs remainder in
  int reset_buffer();
};
#endif