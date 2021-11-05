#ifndef USEFULFUNCS_H
#define USEFULFUNCS_H

#include <iostream>
#include <malloc.h>
#include <cstdio>
#include <fstream>

/*  data sepcification
 *
 *  type        size        desc
 *   0           1          bool
 *   1           1          char
 *   2           4          int
 *   3           4          float
 *   4           ?          char * / null terminated str
 *
 */

const unsigned char big_dash      [12]  =  {196,196,196,196,196,196,196,196,196,196,196,0}; // ────────────
const unsigned char link_box_start[4]   =  {196,196,194,0};                                 // ──┬
const unsigned char link_box_down [4]   =  {32,32,179,0};                                   //   │
const unsigned char link_box_end  [4]   =  {32,32,192,0};                                   //   └
const unsigned char save_pos      []   =  "\0337\0";
const unsigned char load_pos      []   =  "\0338\0";

typedef struct data_container {
    //unsigned char type;
    unsigned int  type;
    unsigned int  size;
    void *        data;
} data;

/*
std::ostream& print_char_string(std::ostream& os, char * array) {
    char ch;
    int offset = 0;
    while ( (ch = array[offset++]) != '\0') os << ch;
    return os;
}
*/

void print_char_string(char * array);

char * copy_str(char * ostr);

unsigned char * copy_bytes(unsigned char * byte_array, unsigned int size);

data * copy_data(data * Data, int data_count);

unsigned int str_size(char * str);

unsigned int read_file_line_to_buffer(std::ifstream & ifile, char * line, unsigned int buffer_size,char sep = '\n');

bool str_cmp(char * s1, char * s2);

char * std_string_to_char(std::string str);

// could use templates
data convert_to_data(bool d);
data convert_to_data(char d);
data convert_to_data(int d);
data convert_to_data(float d);
data convert_to_data(char * d);


struct UnexpectedFileEnd : public std::exception {
    const char * what () const throw () {
        return "\033[1;31mReached file end but not supposed to, file may be Corrupted\033[0m";
    }
};

#endif // USEFULFUNCS_H
