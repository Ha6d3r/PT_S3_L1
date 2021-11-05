#ifndef SHIP_H
#define SHIP_H

#include <malloc.h>
#include <Usefulfuncs.h>
#include <fstream>
#include <useless_task_dangerzone/exceptions.h>
#include <conio.h>

class Ship {
    public:

        Ship();
        Ship(int data_count, char ** data_names, data * Data, char * t = nullptr);
        virtual ~Ship();
        Ship(const Ship &obj);

        void         show(bool add_spaces = false);

        unsigned int size();  // could be calculated on data append, but this class is just for demonstration

        data *       get_data();

        void         save(std::ofstream & file, bool bin = true);
        int          load(std::ifstream & file, bool bin = true);

        void         set_data_id(int id,data d);
        data         get_data_id(int id);

        void         add_param(char * name, data new_data);
        char*        get_type();
        void         set_type(char * t);

        data         get_menu();
        void         set_menu();

    private:
        // vars in order of saving
        // size
        int          data_count;

        //not beign writen
        unsigned int avg_data_name_len = 0;

        char *       type;

        data *       Data;
        char **      data_names;

};

#endif // SHIP_H
