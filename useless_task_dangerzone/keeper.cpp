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

        count = 0;

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
            if (container[i]->load(file) != 0 ) throw CorruptedFile();
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
            if (container[i]->load(file,false) != 0 ) throw CorruptedFile();
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
        file << "\nDC " << count << '\n';

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
        for (unsigned int  i = id; i < count-1; ++i) {
            delete container[i];
            container[i] = new Ship( *(container[i+1]) );
        }
        //delete container[count-1];
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
            //for (unsigned int i = 0; i < count; ++i) {
            //    remove_and_move(i);
            //}
            clean();
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

    if (count == 0) {
        std::cout << "\033[1;33mList is empty\033[0m";
    }

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
                std::cout << '[' << i;
                if (i<100) std::cout << ' '; if (i<10) std::cout << ' ';
                std::cout << ']';
                container[i]->show(true);
            }
        } else {
            for (unsigned int i = 0; i < count; ++i) {
                if (str_cmp(type,container[i]->get_type())) {
                    std::cout << '[' << i;
                    if (i<100) std::cout << ' '; if (i<10) std::cout << ' ';
                    std::cout << ']';
                    container[i]->show(true);
                    showed = false;
                }
            }

            if (showed) {
                std::cout << big_dash << " \033[1;31m0 objects found of type\033[1;33m0" << type << "\033[0m"<< std::endl;
            }
        }
    }

    free(type);
}

void Keeper::call_menu(unsigned int id, bool menu) {
    if (menu)
        container[id]->set_menu();
    else
        container[id]->get_menu();
}

void Keeper::draw_menu() {
    int run = true;
    int pos = 0;

    std::string command;
    std::size_t next_char;

    int command_num;
    float command_float;

    int command_char;

    std::string path;

    while (run) {
        std::cout << save_pos;

        for (int i = 0; i < 7; ++i) {
            if (i == pos)
                std::cout << "\033[30m\033[47m ";
            else
                std::cout << "\033[37m\033[40m ";

            std::cout << menu[i] << " \033[0m   ";
        }
        switch(getch()) {
            case 77: {
                if (pos!=6) pos++;
                break;
            }
            case 75: {
                if (pos!=0) pos--;
                break;
            }
            case 72: {
                break;
            }
            case 80: {

                std::cout << "\033[2J\033[H";

                switch(pos) {
                    case 0: {
                        command_num = -1;
                        while (command_num == -1) {

                            std::cout << "\033[30m\033[47m ID \033[0m (0 for all or typed) -> ";
                            std::cin  >> command;

                            try {
                                command_num = std::stoi(command,&next_char);
                            }  catch (std::invalid_argument) {
                                std::cout << "\033[31mInvalid argument\033[0m\n";
                            }
                        }

                        if (command_num == 0) {
                            std::cout << "\033[30m\033[47m Type \033[0m (-1 if all) -> ";
                            std::cin  >> command;
                        }

                        if (command == "-1") {
                            show(command_num);
                        } else {
                            show(command_num,std_string_to_char(command));
                        }
                        while(getch() != 72);
                        break;
                    }

                    case 1: {

                        command = ""; path = ""; command_num = -1; command_float = -1;

                        if (count == 0) {
                            std::cout << "\033[1;33mList is empty\033[0m";
                            break;
                        }

                        command_num = -1;
                        while (command_num == -1) {

                            std::cout << "\033[30m\033[47m ID \033[0m (starts from 0) -> ";
                            std::cin  >> command;

                            try {
                                command_num = std::stoi(command,&next_char);
                            }  catch (std::invalid_argument) {
                                std::cout << "\033[31mInvalid argument\033[0m\n";
                            }

                            if (command_num >= count || command_num < 0) {
                                command_num = -1;
                                std::cout << "\033[31mIndex out of range\033[0m\n";
                            }
                        }

                        std::cout << " <- Left arrrow GET   |   Right arrow SET -> \n";
                        while ((command_char = getch()) != 72) {
                            switch (command_char) {
                                case 75: {
                                    container[command_num]->get_menu();
                                    break;
                                }
                                case 77: {
                                    container[command_num]->set_menu();
                                }
                            }
                        }

                        break;

                    }

                    case 2: {

                        command = ""; path = ""; command_num = -1; command_float = -1;

                        command = " ";
                        while(command!="Sailboat" && command !="Submarine" && command!="Boat") {
                            std::cout << "Class template name (Submarine/Sailboat/Boat): ";
                            std::cin >> command;
                            std::cout << "\033[H\033[2K";
                        }
                        Ship tmp_obj;
                        if (command == "Submarine") {

                            tmp_obj.set_type(std_string_to_char("Submarine"));

                            command_num = -1;
                            while (command_num == -1) {

                                std::cout << "\033[30m\033[47m Lenght          \033[0m -> ";
                                std::cin  >> command;

                                try {
                                    command_num = std::stoi(command,&next_char);
                                }  catch (std::invalid_argument) {
                                    std::cout << "\033[31mInvalid argument\033[0m\n";
                                }
                            }
                            tmp_obj.add_param(std_string_to_char("Lenght"),convert_to_data(command_num));

                            command_num = -1;
                            while (command_num == -1) {

                                std::cout << "\033[30m\033[47m Width           \033[0m -> ";
                                std::cin  >> command;

                                try {
                                    command_num = std::stoi(command,&next_char);
                                }  catch (std::invalid_argument) {
                                    std::cout << "\033[31mInvalid argument\033[0m\n";
                                }
                            }
                            tmp_obj.add_param(std_string_to_char("Width"),convert_to_data(command_num));

                            command_num = -1;
                            while (command_num == -1) {

                                std::cout << "\033[30m\033[47m Personel        \033[0m -> ";
                                std::cin  >> command;

                                try {
                                    command_num = std::stoi(command,&next_char);
                                }  catch (std::invalid_argument) {
                                    std::cout << "\033[31mInvalid argument\033[0m\n";
                                }
                            }
                            tmp_obj.add_param(std_string_to_char("Personel"),convert_to_data(command_num));

                            command_float = -1;
                            while (command_float < 0) {

                                std::cout << "\033[30m\033[47m Underwater time \033[0m -> ";
                                std::cin  >> command;

                                try {
                                    command_float = std::stof(command,&next_char);
                                }  catch (std::invalid_argument) {
                                    std::cout << "\033[31mInvalid argument\033[0m\n";
                                }
                            }
                            tmp_obj.add_param(std_string_to_char("Underwater time"),convert_to_data(command_float));

                            command_float = -1;
                            while (command_float < 0) {

                                std::cout << "\033[30m\033[47m Max speed       \033[0m -> ";
                                std::cin  >> command;

                                try {
                                    command_float = std::stoi(command,&next_char);
                                }  catch (std::invalid_argument) {
                                    std::cout << "\033[31mInvalid argument\033[0m\n";
                                }
                            }
                            tmp_obj.add_param(std_string_to_char("Max speed"),convert_to_data(command_float));

                            std::cout << "\033[30m\033[47m Weapons         \033[0m -> ";
                            std::cin  >> command;

                            tmp_obj.add_param(std_string_to_char("Weapons"),convert_to_data(std_string_to_char(command)));

                        }

                        if (command == "Sailboat") {

                            tmp_obj.set_type(std_string_to_char("Sailboat"));

                            std::cout << "\033[30m\033[47m Type     \033[0m -> ";
                            std::cin  >> command;

                            tmp_obj.add_param(std_string_to_char("Type"),convert_to_data(std_string_to_char(command)));

                            std::cout << "\033[30m\033[47m Name     \033[0m -> ";
                            std::cin  >> command;

                            tmp_obj.add_param(std_string_to_char("Name"),convert_to_data(std_string_to_char(command)));

                            command_num = -1;
                            while (command_num == -1) {

                                std::cout << "\033[30m\033[47m Military \033[0m -> ";
                                std::cin  >> command;

                                try {
                                    command_num = std::stoi(command,&next_char);
                                }  catch (std::invalid_argument) {
                                    std::cout << "\033[31mInvalid argument\033[0m\n";
                                }
                            }
                            tmp_obj.add_param(std_string_to_char("Military"),convert_to_data((bool)command_num));

                            command_num = -1;
                            while (command_num == -1) {

                                std::cout << "\033[30m\033[47m Lenght   \033[0m -> ";
                                std::cin  >> command;

                                try {
                                    command_num = std::stoi(command,&next_char);
                                }  catch (std::invalid_argument) {
                                    std::cout << "\033[31mInvalid argument\033[0m\n";
                                }
                            }
                            tmp_obj.add_param(std_string_to_char("Lenght"),convert_to_data(command_num));

                            command_float = -1;
                            while (command_float < 0) {

                                std::cout << "\033[30m\033[47m Speed    \033[0m -> ";
                                std::cin  >> command;

                                try {
                                    command_float = std::stoi(command,&next_char);
                                }  catch (std::invalid_argument) {
                                    std::cout << "\033[31mInvalid argument\033[0m\n";
                                }
                            }
                            tmp_obj.add_param(std_string_to_char("Speed"),convert_to_data(command_float));

                            command_num = -1;
                            while (command_num == -1) {

                                std::cout << "\033[30m\033[47m Crew     \033[0m -> ";
                                std::cin  >> command;

                                try {
                                    command_num = std::stoi(command,&next_char);
                                }  catch (std::invalid_argument) {
                                    std::cout << "\033[31mInvalid argument\033[0m\n";
                                }
                            }
                            tmp_obj.add_param(std_string_to_char("Crew"),convert_to_data(command_num));

                        }

                        if (command == "Boat") {

                            tmp_obj.set_type(std_string_to_char("Boat"));

                            std::cout << "\033[30m\033[47m Destination \033[0m -> ";
                            std::cin  >> command;

                            tmp_obj.add_param(std_string_to_char("Destination"),convert_to_data(std_string_to_char(command)));

                            std::cout << "\033[30m\033[47m Material    \033[0m -> ";
                            std::cin  >> command;

                            tmp_obj.add_param(std_string_to_char("Material"),convert_to_data(std_string_to_char(command)));

                            std::cout << "\033[30m\033[47m Performance \033[0m -> ";
                            std::cin  >> command;

                            tmp_obj.add_param(std_string_to_char("Performance"),convert_to_data(std_string_to_char(command)));

                            command_float = -1;
                            while (command_float < 0) {

                                std::cout << "\033[30m\033[47m Speed       \033[0m -> ";
                                std::cin  >> command;

                                try {
                                    command_float = std::stoi(command,&next_char);
                                }  catch (std::invalid_argument) {
                                    std::cout << "\033[31mInvalid argument\033[0m\n";
                                }
                            }
                            tmp_obj.add_param(std_string_to_char("Speed"),convert_to_data(command_float));

                            command_num = -1;
                            while (command_num == -1) {

                                std::cout << "\033[30m\033[47m Crew        \033[0m -> ";
                                std::cin  >> command;

                                try {
                                    command_num = std::stoi(command,&next_char);
                                }  catch (std::invalid_argument) {
                                    std::cout << "\033[31mInvalid argument\033[0m\n";
                                }
                            }
                            tmp_obj.add_param(std_string_to_char("Crew"),convert_to_data(command_num));

                        }

                        add(tmp_obj);

                        while(getch()!=72);

                        break;
                    }

                    case 3: {

                        command = ""; path = ""; command_num = -1; command_float = -1;

                        if (count == 0) {
                            std::cout << "\033[1;33mList is empty\033[0m";
                            break;
                        }

                        command_num = -1;
                        while (command_num == -1) {

                            std::cout << "\033[30m\033[47m ID \033[0m (starts from 1) -> ";
                            std::cin  >> command;

                            try {
                                command_num = std::stoi(command,&next_char);
                            }  catch (std::invalid_argument) {
                                std::cout << "\033[31mInvalid argument\033[0m\n";
                            }
                        }


                        if (command_num == 0) {
                            std::cout << "\033[30m\033[47m Type \033[0m (-1 if all) -> ";
                            std::cin  >> command;
                        }

                        rem(command_num,std_string_to_char(command));

                        while(getch()!=72);
                        break;

                    }

                    case 4: {

                        command = ""; path = ""; command_num = -1; command_float = -1;

                        if (count == 0) {
                            std::cout << "\033[1;33mList is empty\033[0m";
                            break;
                        }

                        std::cout << "\033[30m\033[47m Save path \033[0m (ABS) -> ";
                        std::cin  >> path;

                        while(command!="txt" && command !="bin") {
                            std::cout << "\033[30m\033[47m Text / Binary \033[0m (txt/bin) -> ";
                            std::cin >> command;
                            std::cout << "\033[H\033[2K";
                        }

                        if (command == "txt") {
                            save(path,false);
                        }

                        if (command == "bin") {
                            save(path);
                        }

                        std::cout << "\033[32m Saved to " << path << " in " << command << " format \033[0m\n\033[2K";

                        while(getch()!=72);
                        break;
                    }

                    case 5: {

                        command = ""; path = ""; command_num = -1; command_float = -1;

                        std::cout << "\033[30m\033[47m Load path \033[0m (ABS) -> ";
                        std::cin  >> path;

                        while(command!="txt" && command !="bin") {
                            std::cout << "\033[30m\033[47m Text / Binary \033[0m (txt/bin) -> ";
                            std::cin >> command;
                            std::cout << "\033[H\033[2K";
                        }

                        if (command == "txt") {
                            load(path,false);
                        }

                        if (command == "bin") {
                            load(path);
                        }

                        std::cout << "\033[32m Loaded from " << path << " in " << command << " format \033[0m";

                        while(getch()!=72);
                        break;
                    }

                    case 6: {
                        run = false;
                        break;
                    }
                }

                std::cout << "\033[H\033[2J";

                break;
            }
        }

        std::cout << load_pos;

    }

}
