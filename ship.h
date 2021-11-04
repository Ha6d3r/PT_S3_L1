#ifndef SHIP_H
#define SHIP_H

#include <malloc.h>
#include <Usefulfuncs.h>

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

    private:
        int      data_count;
        data *   Data;
        char **  data_names;
        unsigned int avg_data_name_len = 0;

        char *   type;
};

#endif // SHIP_H
