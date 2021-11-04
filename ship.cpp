#include "ship.h"

Ship::Ship() {
    data_count = 0;
    data_names = static_cast<char **>(malloc(sizeof(char*)));
    data_names[0] = static_cast<char *>(malloc(sizeof(char) * 6));
    data_names[0][0] = 'E'; data_names[0][1] = 'm'; data_names[0][2] = 'p'; data_names[0][3] = 't'; data_names[0][4] = 'y'; data_names[0][5] = '\0';
    type = static_cast<char *>(malloc(sizeof(char) * 6));
    type[0] = 'E'; type[1] = 'm'; type[2] = 'p'; type[3] = 't'; type[4] = 'y'; type[5] = '\0';

    std::cout << big_dash << " \033[1;32mDeffault constructor call \033[1;33m" << type << "\033[0m" << std::endl;
}

Ship::Ship(int data_count, char ** data_names, data * Data, char * t) {
    this->data_count = data_count;
    this->data_names = static_cast<char **>(malloc(sizeof(char*) * data_count));
    for (int i = 0; i < data_count; ++i) {
        this->data_names[i] = copy_str(data_names[i]);
        avg_data_name_len  += str_size(data_names[i]);
    }

    avg_data_name_len = avg_data_name_len / data_count + avg_data_name_len % data_count;

    this->Data = copy_data(Data,data_count);

    if (t) {
        type = copy_str(t);
    } else {
        type = static_cast<char *>(malloc(sizeof(char) * 6));
        type[0] = 'E'; type[1] = 'm'; type[2] = 'p'; type[3] = 't'; type[4] = 'y'; type[5] = '\0';
    }

    std::cout << big_dash << " \033[1;32mParam constructor call \033[1;33m" << type << "\033[0m" << std::endl;
}

Ship::Ship(const Ship &obj) {
    data_count = obj.data_count;
    for (int i = 0; i < data_count; ++i) {
        data_names[i] = copy_str(obj.data_names[i]);
    }
    type = copy_str(obj.type);
    Data = copy_data(obj.Data,obj.data_count);
    std::cout << big_dash << " \033[1;32mCopy constructor call \033[1;33m" << type << "\033[0m" << std::endl;
}

Ship::~Ship() {
    std::cout << big_dash << " \033[1;32mDestructor call \033[1;33m" << type << "\033[0m" << std::endl;

    if (data_count > 0) {
        for (int i = 0; i < data_count; ++i) {
            free(data_names[i]);
            free(Data[i].data);
        }
        free(Data);
    }
    free(type);
    free(data_names);
}

void Ship::show() {

    std::cout << link_box_start << " \033[1;32mData of \033[1;33m" << type << "\033[0m" << std::endl;
    unsigned int spaces;
    if (data_count > 0) {
        for (int i = 0; i < data_count; ++i) {
            std::cout << link_box_down << " \033[1;33m" << data_names[i] << "\033[1;36m ";

            spaces = avg_data_name_len - str_size(data_names[i]);
            for(int j = 0; j < spaces; ++j) std::cout << ' ';

            switch (Data[i].type) {
                case 0: {
                    std::cout << "\033[1;35mbool \033[0m " << ( ( *( (bool*)Data[i].data ) ) ? "True" : "False" );
                    break;
                }
                case 1: {
                    std::cout << "\033[1;35mchar \033[0m " << *( (char*)Data[i].data );
                    break;
                }
                case 2: {
                    std::cout << "\033[1;35mint  \033[0m " << *( (int*)Data[i].data );
                    break;
                }
                case 3: {
                    std::cout << "\033[1;35mfloat\033[0m " << *( (float*)Data[i].data );
                    break;
                }
                case 4: {
                    std::cout << "\033[1;35mchar*\033[0m "  << (char*)Data[i].data;
                    break;
                }
            }
            std::cout << "\033[0m" << std::endl;
        }
    } else {
        std::cout << link_box_down << " \033[1;33mEmpty\033[0m" << std::endl;
    }

    std::cout << link_box_end << " \033[1;34mData count: " << data_count << " Size: " << size() << "\033[0m" << std::endl;
}

unsigned int Ship::size() {
    unsigned int calc_size = sizeof(data_count);
    calc_size += str_size(type);
    for(int i = 0; i < data_count; ++i) {
        calc_size += str_size(data_names[i]);
        calc_size += Data[i].size;
    }
    return calc_size;
}

data * Ship::get_data() {
    return Data;
}

void Ship::set_data_id(int id, data d) {
    Data[id].type = d.type;
    Data[id].size = d.size;
    Data[id].data = (void *)copy_bytes((unsigned char *)d.data,d.size);
}

data Ship::get_data_id(int id) {
    data output;
    output.type = Data[id].type;
    output.size = Data[id].size;
    output.data = (void *)copy_bytes((unsigned char *)Data[id].data,Data[id].size);
    return output;
}
