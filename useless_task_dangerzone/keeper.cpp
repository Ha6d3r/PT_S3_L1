#include "keeper.h"

Keeper::Keeper() {
    count = 0;
}

Keeper::Keeper(std::string load_path, bool bin) {
    load(load_path,bin);
}

Keeper::Keeper(const Keeper & obj) {
    clean();
    count = obj.count;
    container = static_cast<Ship**>(malloc(sizeof(Ship*) * count));

    for (unsigned int i = 0; i < count; ++i) {
        container[i] = new Ship();
        *container[i] = *obj.container[i];
    }
}

Keeper::~Keeper() {
    clean();
}


void Keeper::clean() {
    if (count > 0) {
        for (unsigned int i = 0; i < count; ++i) {
            delete container[i];
        }

        free(container);

    }
}

/*
 * save / load works as folows
 * 1 - type flag, always 1, but for binary it will be read as ' 1 ' and for text '49' - 1 in text form
 * Data count - can be separated with any amount of spaces
 *      Binary  Text
 *        N     DC N\n
 * Data 1
 * ....
 * Data N
 */
void Keeper::load(std::string path, bool bin) {
    char test_byte;

    char * line_buffer = static_cast<char *>(malloc(sizeof(char) * 512));

    clean();

    if (bin) {
        std::ifstream file(path, std::ios::in | std::ios::binary);
        if (!file.is_open()) {
            throw NoSuchFileOrDirectory();
        }
        file.read(&test_byte,1);
        if (test_byte != 1) {
            file.close();
            throw WrongFileFormat();
        }
        file.read((char*)&count,4);
        if (count <= 0) throw IncorrectDataParam();

        container = static_cast<Ship**>(malloc(sizeof(Ship*) * count));

        for (unsigned int i = 0; i < count; ++i) {
            container[i] = new Ship();
            container[i]->load(file);
        }

        file.close();

    } else {
        std::ifstream file(path, std::ios::in);
        if (!file.is_open()) {
            throw NoSuchFileOrDirectory();
        }
        file.read(&test_byte,1);
        if (test_byte != '1') {
            file.close();
            throw WrongFileFormat();
        }
        // skips \n
        file.read(&test_byte,1);


        read_file_line_to_buffer(file,line_buffer,512);

        if (line_buffer[0] == 'D') {
            if (line_buffer[1] == 'C') {
                count = std::stoi(line_buffer+2);
                if (count <= 0) throw IncorrectDataParam();
            }
        }

        container = static_cast<Ship**>(malloc(sizeof(Ship*) * count));

        for (unsigned int i = 0; i < count; ++i) {
            container[i] = new Ship();
            container[i]->load(file,false);
        }

        file.close();
    }

    free(line_buffer);

}

void Keeper::save(std::string path, bool bin) {
    if (bin) {
        std::ofstream file (path, std::ios::out | std::ios::binary);
        char typeflag = 1;
        file.write(&typeflag,1);
        file.write((char*)&count,4);

        for (unsigned int i = 0; i < count; ++i) {
            container[i]->save(file);
        }

    } else {
        std::ofstream file (path, std::ios::out);
        char typeflag = '1';
        file.write(&typeflag,1);
        file << "DC " << count << '\n';

        for (unsigned int i = 0; i < count; ++i) {
            container[i]->save(file,false);
        }
    }
}

void Keeper::add(Ship &obj) {
    if (container) {
        container = static_cast<Ship **>(realloc(container, (count+1) * sizeof(Ship*)));
    } else {
        container = static_cast<Ship **>(malloc(sizeof(Ship*)));
    }
    container[count++] = new Ship(obj);
}

void Keeper::remove_and_move(unsigned int id) {
    if (count > 1) {
        for (unsigned int  i = id; i < count-2; ++i) {
            delete container[i];
            container[i] = new Ship( *(container[i+1]) );
        }
        delete container[count-1];
    } else {
        delete container[0];
    }
    count--;
}

void Keeper::rem(unsigned int id, char * type) {
    if (id > 0) {
        id--;
        if (id >= count) {
            std::cout << big_dash << " \033[1;31mID is out of range\033[0m" << std::endl;
        } else {
            remove_and_move(id);
        }
    } else {
        if (type == nullptr) {
            for (unsigned int i = 0; i < count; ++i) {
                remove_and_move(i);
            }
        } else {
            for (unsigned int i = 0; i < count; ++i) {
                if (str_cmp(type,container[i]->get_type())) {
                    remove_and_move(i);
                }
            }
        }
    }
}

void Keeper::show(unsigned int id, char * type) {

    bool showed = true;

    if (id > 0) {
        id--;
        if (id >= count) {
            std::cout << big_dash << " \033[1;31mID is out of range\033[0m" << std::endl;
        } else {
            container[id]->show();
        }
    } else {
        if (type == nullptr) {
            for (unsigned int i = 0; i < count; ++i) {
                container[i]->show();
            }
        } else {
            for (unsigned int i = 0; i < count; ++i) {
                if (str_cmp(type,container[i]->get_type())) {
                    container[i]->show();
                    showed = false;
                }
            }

            if (showed) {
                std::cout << big_dash << " \033[1;31m0 objects found of type\033[1;33m0" << type << "\033[0m"<< std::endl;
            }
        }
    }
}

