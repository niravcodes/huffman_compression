#ifndef _BITQUEUE_H
#define _BITQUEUE_H

typedef byte unsigned char;
class bitqueue
{
  private:
    byte *buffer;
    unsigned pointer;
    unsigned end_bit;
    unsigned buffer_size; // inbytes

    inline unsigned get_byte_pos();
    inline unsigned get_bit_offset();
    inline bool is_empty();

  public:
    bitqueue();
    ~bitqueue();
    int pop();
    void fill_buffer(byte *data_ptr);
}

#endif