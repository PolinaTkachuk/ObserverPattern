#include <QCoreApplication>
#include <iostream>
#include "Subject.h"

#include <chrono>
#include <thread>

using namespace std;
//Задание:На основе паттерна Наблюдателя, написать программу для слежения за состоянием выбранного файла
//Для тестирования программы, создала файлы в папке проекта
//все работает корректно при 3х описанных ситуациях
int main() {
    //В главной программе создаем объект для отслеживания состояния конкретного файла
    FileConcreteSubject monitor1( "test.txt" );//файл с данными
    FileConcreteSubject monitor( "test1.txt" );//файл с данными
    FileConcreteSubject monitor3( "test_empty.txt" );//файл существует, но пуст
    FileConcreteSubject monitor2( "test2.txt" );//файл не существует
    //затем определяется объект наблюдатель
    FileObserver observer;
    // после чего связываем Наблюдателя с Источником. Один наблюдатель может следить за несколькими файлами
    monitor.Attach( &observer );
    monitor1.Attach( &observer );


    while( true ) {
        //следим за 2мя файлами
        monitor.checkFile();
        monitor1.checkFile();
        //использование бесконечного цикла, в котором будем обновлять состояние объекта
        //Источника каждые 100 миллисекунд
        this_thread::sleep_for( chrono::milliseconds( 100 ) );
        {
            monitor1.Detach(&observer);//после 1го шага цикла -убираем наблюдатель(слежку для файла test)
            monitor.Notify(true, 18);//обновление файла test1-файл модифицирую (аргументы- файл существует, размер18)
        }


    }

    return 0;
}
