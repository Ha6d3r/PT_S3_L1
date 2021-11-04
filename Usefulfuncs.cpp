#include <Usefulfuncs.h>

void print_char_string(char * array) {
    char ch;int offset = 0;
    while ( (ch = array[offset++]) != '\0') std::cout << ch;
}

char * copy_str(char * ostr) {
    int len = 0; int output_len = 100;
    char ch;

    char * output = static_cast<char *>(malloc(sizeof(char) * output_len));
    while ( (ch = ostr[len] ) != '\0' ) {
        output[len++] = ch;
        if (len == output_len) {
            output_len <<= 1;
            output = static_cast<char *>(realloc(output, output_len));
        }
    }
    output[len++] = '\0';
    if (len < output_len) {
        output = static_cast<char *>(realloc(output, len));
    }
    return output;
}

unsigned char * copy_bytes(unsigned char * byte_array, unsigned int size) {
    unsigned char * output = static_cast<unsigned char *>(malloc(sizeof(unsigned char) * size));
    for (unsigned int i = 0; i < size; ++i) {
        output[i] = byte_array[i];
    }
    return output;
}

data * copy_data(data * Data, int data_count) {

    data * output = static_cast<data *>(malloc(sizeof(data) * data_count));

    for (int i = 0; i < data_count; ++i) {
        output[i].type = Data[i].type;
        output[i].size = Data[i].size;
        output[i].data = (void *)copy_bytes((unsigned char *)Data[i].data,Data[i].size);
    }
    return output;
}

unsigned int str_size(char * str) {
    unsigned int size = 0;
    while ( str[size++] != '\0');
    return size;
}


data convert_to_data(bool d) {
    data output;
    output.type = 0;
    output.size = 1;
    output.data = static_cast<bool *>(malloc(sizeof(bool)));
    *(bool*)output.data = d;
    return output;
}
data convert_to_data(char d) {
    data output;
    output.type = 1;
    output.size = 1;
    output.data = static_cast<char *>(malloc(sizeof(char)));
    *(char*)output.data = d;
    return output;
}
data convert_to_data(int d) {
    data output;
    output.type = 2;
    output.size = 4;
    output.data = static_cast<int *>(malloc(sizeof(int)));
    *(int*)output.data = d;
    return output;
}
data convert_to_data(float d) {
    data output;
    output.type = 3;
    output.size = 4;
    output.data = static_cast<float *>(malloc(sizeof(float)));
    *(float*)output.data = d;
    return output;
}
data convert_to_data(char * d) {
    data output;
    output.type = 4;
    output.size = str_size(d);
    output.data = copy_str(d);
    return output;
}
