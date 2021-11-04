#include <iostream>

#include <ship.h>
//using namespace std;

int main()
{

    data Data[3];

    char ** Names = static_cast<char **>(malloc(sizeof(char*) * 3));
    Names[0] = static_cast<char *>(malloc(sizeof(char) * 3));
    Names[0][0] = 'a'; Names[0][1] = 'b'; Names[0][2] = 0;

    Names[1] = static_cast<char *>(malloc(sizeof(char) * 3));
    Names[1][0] = 'c'; Names[1][1] = 'd'; Names[1][2] = 0;

    Names[2] = static_cast<char *>(malloc(sizeof(char) * 5));
    Names[2][0] = 'e'; Names[2][1] = 'f'; Names[2][2] = 'h'; Names[2][3] = 'g'; Names[2][4] = 0;

    char test_string[3] = {'t','s',0};

    Data[0] = convert_to_data(5);
    Data[1] = convert_to_data(1.245f);
    Data[2] = convert_to_data(test_string);

    Ship test(3,Names,Data);

    for (int i = 0; i < 3; ++i) {
        free(Names[i]);
    }
    free(Names);

    test.show();

    //cout << "Hello World!" << endl;
    return 0;
}
