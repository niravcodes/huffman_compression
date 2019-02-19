#ifndef _BITQUEUE_H
#define _BITQUEUE_H

typedef unsigned char byte;
class bitqueue
{
  private:
    byte *buffer;
    unsigned backup;
    unsigned buffer_size;
    unsigned long top;
    unsigned long bottom;
    inline unsigned long get_bit_offset();
    inline unsigned long get_byte_pos();
    inline unsigned long get_end_byte();
    unsigned get_four_or_less_bytes();

  public:
    bitqueue(unsigned size, byte *data);
    ~bitqueue();

    unsigned peek(unsigned length);
    int forward(unsigned length);

    void refill(byte *data, unsigned size);
};

#endif