#ifndef KEEPER_H
#define KEEPER_H

#include <ship.h>
#include <fstream>

// used only for file path
#include <string>

class Keeper {
    public:
        Keeper();
        Keeper(std::string load_path, bool bin = true);
        Keeper(const Keeper & obj);
        ~Keeper();

        void    show(unsigned int id, char * type = nullptr);
        void    load(std::string path, bool bin = true);
        void    save(std::string path, bool bin = true);

        void    add(Ship & obj);
        void    rem(unsigned int id, char * type = nullptr);

        void    call_menu(unsigned int id, bool menu);
        void    draw_menu();

    private:

        void    clean();
        void    remove_and_move(unsigned int id);

        Ship ** container = nullptr;
        unsigned int count = 0;

        std::string menu[7] = {
            "Show",
            "Select/Edit",
            "Add",
            "Remove",
            "Save",
            "Load",
            "Exit"
        };

};

#endif // KEEPER_H
