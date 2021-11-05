#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>

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

#endif // EXCEPTIONS_H
