#ifndef SHIP_H
#define SHIP_H

#include <malloc.h>
#include <Usefulfuncs.h>
#include <fstream>

class Ship {
    public:
        Ship();
        Ship(int data_count, char ** data_names, data * Data, char * t = nullptr);
        virtual ~Ship();
        Ship(const Ship &obj);

        virtual void         show();

        virtual unsigned int size();  // could be calculated on data append, but this class is just for demonstration

        virtual data *       get_data();
        virtual void         set_data_id(int id,data d);
        virtual data         get_data_id(int id);

        virtual void         save(std::ofstream & file, bool bin = true);
        virtual void         load(std::ifstream & file, bool bin = true);

    private:
        // vars in order of saving
        int          data_count;
        unsigned int avg_data_name_len = 0;

        char *       type;

        data *       Data;
        char **      data_names;

};

#endif // SHIP_H
