#ifndef _BIT_PRINTER_H
#define _BIT_PRINTER_H
#include <iostream>

template <class T>
void print_bits(T);

template <class T>
std::string print_bits(T, int);
#include "bit_printer.T"
#endif