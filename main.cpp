#include <QCoreApplication>
#include <iostream>
#include "Subject.h"

#include <chrono>
#include <thread>

using namespace std;
//Задание:На основе паттерна Наблюдателя, написать программу для слежения за состоянием выбранного файла
//Для тестирования программы, создала файл в папке поекта- "test.txt"
//все работает корректно при 3х описанных ситуациях
int main() {
    //В главной программе создаем объект для отслеживания состояния конкретного файла
    FileMonitor monitor( "test.txt" );
    //затем определяется объект наблюдатель
    FileObserver observer;
    // после чего связываем Наблюдателя с Источником
    monitor.Attach( &observer );

    while( true ) {
        monitor.checkFile();
        //использование бесконечного цикла, в котором будем обновлять состояние объекта
        //Источника каждые 100 миллисекунд
        this_thread::sleep_for( chrono::milliseconds( 100 ) );
    }

    return 0;
}
