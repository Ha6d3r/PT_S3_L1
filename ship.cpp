#include "ship.h"

Ship::Ship() {
    data_count = 0;
    data_names = static_cast<char **>(malloc(sizeof(char*)));
    data_names[0] = static_cast<char *>(malloc(sizeof(char) * 6));
    Data = static_cast<data*>(malloc(1));
    data_names[0][0] = 'E'; data_names[0][1] = 'm'; data_names[0][2] = 'p'; data_names[0][3] = 't'; data_names[0][4] = 'y'; data_names[0][5] = '\0';
    type = static_cast<char *>(malloc(sizeof(char) * 6));
    type[0] = 'E'; type[1] = 'm'; type[2] = 'p'; type[3] = 't'; type[4] = 'y'; type[5] = '\0';
    avg_data_name_len = 5;

    std::cout << big_dash << " \033[1;32mDeffault constructor call \033[1;33m" << type << "\033[0m" << std::endl;
}

Ship::Ship(int data_count, char ** data_names, data * Data, char * t) {
    this->data_count = data_count;
    this->data_names = static_cast<char **>(malloc(sizeof(char*) * data_count));
    for (int i = 0; i < data_count; ++i) {
        this->data_names[i] = copy_str(data_names[i]);

        if (str_size(data_names[i]) > avg_data_name_len)
            avg_data_name_len = str_size(data_names[i]);
    }

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
    data_names = static_cast<char **>(malloc(sizeof(char*) * data_count));
    for (int i = 0; i < data_count; ++i) {
        data_names[i] = copy_str(obj.data_names[i]);
    }
    type = copy_str(obj.type);
    Data = copy_data(obj.Data,obj.data_count);
    avg_data_name_len = obj.avg_data_name_len;
    std::cout << big_dash << " \033[1;32mCopy constructor call \033[1;33m" << type << "\033[0m" << std::endl;
}

Ship::~Ship() {
    std::cout << big_dash << " \033[1;32mDestructor call \033[1;33m" << type << "\033[0m" << std::endl;

    if (data_count > 0) {
        for (int i = 0; i < data_count; ++i) {
            free(data_names[i]);
            free(Data[i].data);
        }
    }
    free(type);
    free(data_names);
    free(Data);
}

void Ship::show(bool add_spaces) {

    std::cout << link_box_start << " \033[1;32mData of \033[1;33m" << type << "\033[0m" << std::endl;
    unsigned int spaces;
    if (data_count > 0) {
        for (int i = 0; i < data_count; ++i) {
            if (add_spaces) std::cout << "     ";
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
        if (add_spaces) std::cout << "     ";
        std::cout << link_box_down << " \033[1;33mEmpty\033[0m" << std::endl;
    }
    if (add_spaces) std::cout << "     ";
    std::cout << link_box_end << " \033[1;34mData count: " << data_count << " Size: " << size() << "\033[0m" << std::endl;
}

unsigned int Ship::size() {
    unsigned int calc_size = sizeof(data_count) + sizeof(avg_data_name_len);
    calc_size += str_size(type);
    for(int i = 0; i < data_count; ++i) {
        calc_size += str_size(data_names[i]);
        calc_size += Data[i].size;
        calc_size += 8;
    }
    return calc_size;
}

data * Ship::get_data() {
    return Data;
}

char * Ship::get_type() {
    return type;
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

void Ship::save(std::ofstream & file, bool bin) {
    if (bin) {
        unsigned int cur_size = size();
        unsigned int s_size = str_size(type);
        unsigned int write_offset = 0;
        char * byte_array = static_cast<char *>(malloc(sizeof(char) * cur_size));
        memcpy(byte_array+write_offset,&cur_size,4);                    write_offset += 4;
        memcpy(byte_array+write_offset,&data_count,4);                  write_offset += 4;
        memcpy(byte_array+write_offset,type,s_size);                    write_offset += s_size;
        for(int i = 0; i < data_count; ++i) {
            memcpy(byte_array+write_offset,&Data[i].type,4);            write_offset += 4;
            memcpy(byte_array+write_offset,&Data[i].size,4);            write_offset += 4;
            memcpy(byte_array+write_offset,Data[i].data,Data[i].size);  write_offset += Data[i].size;
            s_size = str_size(data_names[i]);
            memcpy(byte_array+write_offset,data_names[i],s_size);       write_offset += s_size;
        }

        file.write(byte_array,cur_size);

        free(byte_array);
    } else {
        file << size() << '\n';
        file << data_count << '\n';
        // cancel '\0' write
        file.write(type,str_size(type) - 1);
        file << '\n';
        for(int i = 0; i < data_count; ++i) {
            file << Data[i].type << '\n';
            file << Data[i].size << '\n';
            switch (Data[i].type) {
                case 0: {
                    file << *( (bool*)Data[i].data ) << '\n';
                    break;
                }
                case 1: {
                    file << *( (char*)Data[i].data ) << '\n';
                    break;
                }
                case 2: {
                    file << *( (int*)Data[i].data ) << '\n';
                    break;
                }
                case 3: {
                    file << *( (float*)Data[i].data ) << '\n';
                    break;
                }
                case 4: {
                    // cancel '\0' write
                    file.write((char*)Data[i].data,Data[i].size - 1);    file << '\n';
                    break;
                }
            }
            // cancel '\0' write
            file.write(data_names[i],str_size(data_names[i]) - 1); file << '\n';
        }
    }
}

int Ship::load(std::ifstream & file, bool bin) {

    unsigned int data_count_new;
    char * line_buffer = static_cast<char *>(malloc(sizeof(char) * 512));
    unsigned int line_size;
    std::size_t next_char;

    int size_to_be_read;

    bool bool_data;
    char char_data;
    int  int_data;
    float float_data;

    free(type);

    if (bin) {
        file.read((char*)&size_to_be_read,4);                                   size_to_be_read -= 4;

        size_to_be_read -= file.readsome((char*)&data_count_new,4);

        read_file_line_to_buffer(file,line_buffer,512,'\0');
        type = copy_str(line_buffer);                                           size_to_be_read -= str_size(type);
    } else {
        if (!read_file_line_to_buffer(file, line_buffer,512)) throw CorruptedFile();
        size_to_be_read = std::stoi(line_buffer,&next_char);                    size_to_be_read -= 4;

        if (!read_file_line_to_buffer(file, line_buffer,512)) throw CorruptedFile();
        data_count_new = std::stoi(line_buffer,&next_char);                     size_to_be_read -= 4;

        line_size = read_file_line_to_buffer(file,line_buffer,512);

        if (line_buffer[line_size-2] != '\0') line_buffer[line_size-1] = '\0';
        type = copy_str(line_buffer);                                           size_to_be_read -= str_size(type);
    }

    if (data_count != 0) {

        for (int i = 0; i < data_count; ++i) {
            free(data_names[i]);
            free(Data[i].data);
        }
        free(data_names);
        free(Data);
    }
    Data = static_cast<data *>(malloc(sizeof(data) * data_count_new));
    data_names = static_cast<char **>(malloc(sizeof(char*) * data_count_new));

    data_count = data_count_new;

    avg_data_name_len = 0;

    for (int i = 0; i < data_count_new; ++i) {
        if (bin) {
            size_to_be_read -= file.readsome((char*)&Data[i].type,4);
            size_to_be_read -= file.readsome((char*)&Data[i].size,4);
            Data[i].data = malloc(Data[i].size);
            size_to_be_read -= file.readsome((char*)Data[i].data,Data[i].size);
            read_file_line_to_buffer(file,line_buffer,512,'\0');
            data_names[i] = copy_str(line_buffer);
            if (str_size(data_names[i]) > avg_data_name_len)
                avg_data_name_len = str_size(data_names[i]);

            size_to_be_read-= str_size(data_names[i]);

        } else {
            read_file_line_to_buffer(file, line_buffer,512);

            // ------ real baaaad ------------
            // why would any body need this

            try {

                Data[i].type = std::stoi(line_buffer,&next_char);                           size_to_be_read -= 4;

                read_file_line_to_buffer(file, line_buffer,512);

                Data[i].size = std::stoi(line_buffer,&next_char);                           size_to_be_read -= 4;

                line_size = read_file_line_to_buffer(file,line_buffer,512);

                switch (Data[i].type) {
                    case 0: {
                        bool_data = (std::stoi(line_buffer,&next_char)) ? true : false;
                        Data[i].data = malloc(1);
                        memcpy(Data[i].data,&bool_data,1);
                        break;
                    }
                    case 1: {
                        char_data = line_buffer[0];
                        Data[i].data = malloc(1);
                        memcpy(Data[i].data,&char_data,1);
                        break;
                    }
                    case 2: {
                        int_data = std::stoi(line_buffer,&next_char);
                        Data[i].data = malloc(4);
                        memcpy(Data[i].data,&int_data,4);
                        break;
                    }
                    case 3: {
                        float_data = std::stof(line_buffer,&next_char);
                        Data[i].data = malloc(4);
                        memcpy(Data[i].data,&float_data,4);
                        break;
                    }
                    case 4: {
                        line_buffer[line_size-1] = '\0';
                        Data[i].data = (void*)copy_str(line_buffer);
                        break;
                    }
                }

            }  catch (std::invalid_argument) {
                throw CorruptedFile();
            }

            size_to_be_read -= Data[i].size;

            line_size = read_file_line_to_buffer(file,line_buffer,512);
            //if (line_buffer[line_size-2] != '\0') line_buffer[line_size-1] = '\0';
            // line size missmatch is not an issue
            data_names[i] = copy_str(line_buffer);
            if (str_size(data_names[i]) > avg_data_name_len)
                avg_data_name_len = str_size(data_names[i]);

            size_to_be_read-= str_size(data_names[i]);
        }
    }

    return size_to_be_read;

}

void Ship::set_type(char * t) {
    type = copy_str(t);
    free(t);
}

void Ship::add_param(char *name, data new_data) {

    data_names = static_cast<char**>(realloc(data_names, (data_count+1) * sizeof(char*) ) );
    Data       = static_cast<data* >(realloc(Data      , (data_count+1) * sizeof(data ) ) );

    data_names[data_count] = copy_str(name);
    free(name);

    if (str_size(data_names[data_count]) > avg_data_name_len) avg_data_name_len = str_size(data_names[data_count]);

    Data[data_count].size = new_data.size;
    Data[data_count].type = new_data.type;
    Data[data_count].data = new_data.data; // dangerous


    data_count++;
}

void Ship::set_menu() {
    int run = true;
    int pos = 0;

    std::string data_string;
    std::size_t next_char;

    bool bool_data;
    char char_data;
    int  int_data;
    float float_data;

    while (run) {
        std::cout << save_pos;

        for (int i = 0; i < data_count; ++i) {
            if (i == pos)
                std::cout << "\033[30m\033[47m ";
            else
                std::cout << "\033[37m\033[40m ";

            std::cout << data_names[i] << " \033[0m   ";
        }
        switch(getch()) {
            case 77: {
                if (pos!=data_count-1) pos++;
                break;
            }
            case 75: {
                if (pos!=0) pos--;
                break;
            }
            case 72: {
                run = false;
                break;
            }
            case 80: {
                std::cout << "\n New data: \033[0K";
                std::cin >> data_string;

                try {
                    switch (Data[pos].type) {
                        case 0: {
                            bool_data = (std::stoi(data_string,&next_char)) ? true : false;
                            memcpy(Data[pos].data,&bool_data,1);
                            break;
                        }
                        case 1: {
                            char_data = data_string[0];
                            memcpy(Data[pos].data,&char_data,1);
                            break;
                        }
                        case 2: {
                            int_data = std::stoi(data_string,&next_char);
                            memcpy(Data[pos].data,&int_data,4);
                            break;
                        }
                        case 3: {
                            float_data = std::stof(data_string,&next_char);
                            memcpy(Data[pos].data,&float_data,4);
                            break;
                        }
                        case 4: {
                            free (Data[pos].data);
                            Data[pos].data = (void*)std_string_to_char(data_string);
                            break;
                        }
                    }

                    std::cout << "  \033[1;32mSuccess\033[0m\033[0K";

                }  catch (std::invalid_argument) {
                    std::cout << "  \033[1;31mInvalid argument\033[0m\033[0K";
                }

                break;
            }
        }

        std::cout << load_pos;

    }

    std::cout << "\033[0K\n\033[0K\n\033[0K";

    std::cout << load_pos;

}

data Ship::get_menu() {
    int run = true;
    int pos = 0;

    while (run) {
        std::cout << save_pos;

        for (int i = 0; i < data_count; ++i) {
            if (i == pos)
                std::cout << "\033[30m\033[47m ";
            else
                std::cout << "\033[37m\033[40m ";

            std::cout << data_names[i] << " \033[0m   ";
        }
        switch(getch()) {
            case 77: {
                if (pos!=data_count-1) pos++;
                break;
            }
            case 75: {
                if (pos!=0) pos--;
                break;
            }
            case 72: {
                run = false;
                break;
            }
            case 80: {
                std::cout << "\nDisplaying param: \033[0K";
                std::cout << "\033[33m" <<data_names[pos] << "\033[0m\n";
                std::cout << "Type:             \033[0K";
                switch (Data[pos].type) {
                    case 0: {
                        std::cout << "\033[1;35mbool\033[0m\nData:             \033[0K" << ( ( *( (bool*)Data[pos].data ) ) ? "True" : "False" );
                        break;
                    }
                    case 1: {
                        std::cout << "\033[1;35mchar\033[0m\nData:             \033[0K" << *( (char*)Data[pos].data );
                        break;
                    }
                    case 2: {
                        std::cout << "\033[1;35mint\033[0m\nData:             \033[0K" << *( (int*)Data[pos].data );
                        break;
                    }
                    case 3: {
                        std::cout << "\033[1;35mfloat\033[0m\nData:             \033[0K" << *( (float*)Data[pos].data );
                        break;
                    }
                    case 4: {
                        std::cout << "\033[1;35mchar*\033[0m\nData:             \033[0K"  << (char*)Data[pos].data;
                        break;
                    }
                }

                std::cout << "\nPointer:          " << Data[pos].data;

                break;
            }
        }

        std::cout << load_pos;

    }

    std::cout << "\033[0K\n\033[0K\n\033[0K\033[0K\n\033[0K\n\033[0K";

    std::cout << load_pos;
}

