#ifndef FILE_H
#define FILE_H
//работа со строками
#include <string>

using namespace std;


//Класс, задающий файл, за состоянием которого мы будем следить
class File
{
public:
    string name;
    long size;
    bool existence;
    File(string fileName);
};


#endif // FILE_H
