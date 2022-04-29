#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>
#include <iostream>

using namespace std;
//Класс- наблюдатель, следим за файлом

class IObserver
{
public:
    virtual void Update(bool existence, long size) = 0; //обновление существования и размера файла
};


class FileObserver: IObserver
{
private:
    long last_size = -1;
public:
    //Программа будет выводить на консоль уведомление о произошедших изменениях в файле
    //3 ситуации может быть
    void Update(bool existence, long size)
    {
        if (last_size == -1) last_size = size;//проверка на изменение размера файла
          if (existence) //если существует
          {
              if (last_size != size) //если размеры не равны, значит файл уже менялся
              {
                  cout << "The file exists, the file has been modified, size: " << size << endl;
                  last_size = size; //изменяем размер для дальнейшей проверки
              }
              else //файл существует но размер тот же
              {
                  cout << "The file exists, the file is not empty, size: " << last_size << endl;
              }
          }
          else //файл не существует
          {
              cout << "the file is not existing" << endl;
          }
    }
};

#endif // OBSERVER_H
