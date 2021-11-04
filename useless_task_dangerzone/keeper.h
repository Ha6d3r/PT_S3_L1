#ifndef KEEPER_H
#define KEEPER_H

#include <ship.h>
#include <fstream>

// used only for file path
#include <string>

struct WrongFileFormat : public std::exception {
    const char * what () const throw () {
        return "\033[1;31mWrong file format\033[0m";
    }
};

struct NoSuchFileOrDirectory : public std::exception {
    const char * what () const throw () {
        return "\033[1;31mNo such file or directory\033[0m";
    }
};

struct IncorrectDataParam : public std::exception {
    const char * what () const throw () {
        return "\033[1;31mFile data param is wrong (0 objects etc...)\033[0m";
    }
};

struct CorruptedFile : public std::exception {
    const char * what () const throw () {
        return "\033[1;31mFile is broken, too short or some data is missing\033[0m";
    }
};

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

    private:

        void    clean();
        void    remove_and_move(unsigned int id);

        Ship ** container = nullptr;
        unsigned int count = 0;

};

#endif // KEEPER_H
