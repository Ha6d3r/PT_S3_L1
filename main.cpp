#include <iostream>

#include <useless_task_dangerzone/keeper.h>
//using namespace std;

int main()
{

    Keeper keeps;

    Ship test;

    std::ifstream file ("C:\\Users\\Ha6Ki\\Documents\\PT_S3_L1\\test.txt",std::ios::in);

    test.load(file,false);

    file.close();

    keeps.add(test);
    keeps.add(test);
    keeps.add(test);

    keeps.show(0);

    std::cout << std::endl;

    keeps.rem(1);

    keeps.show(0);

    //keeps.load("C:\\Users\\Ha6Ki\\Documents\\PT_S3_L1\\test.txt",false);
    //keeps.show(0);
    //keeps.save("C:\\Users\\Ha6Ki\\Documents\\PT_S3_L1\\test.bin");
    //keeps.load("C:\\Users\\Ha6Ki\\Documents\\PT_S3_L1\\test.bin");
    //keeps.show(0);

    /*
    Ship test;
    Ship test2;

    std::ifstream file("C:\\Users\\Ha6Ki\\Documents\\PT_S3_L1\\test.txt");
    std::ofstream file_off("C:\\Users\\Ha6Ki\\Documents\\PT_S3_L1\\test.bin", std::ios::out | std::ios::binary);

    //test.save(file,false);

    test.load(file,false);
    test.save(file_off);

    file_off.close();

    std::ifstream file_1("C:\\Users\\Ha6Ki\\Documents\\PT_S3_L1\\test.bin", std::ios::in | std::ios::binary);

    test2.load(file_1);

    test.show();
    test2.show();

    file_1.close();
    file_off.close();
    file.close();
    */

    return 0;
}
