#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"
#include "file.h"
#include <vector>

//Этот класс отслеживает всех наблюдателей и предоставляет возможность добавлять или удалять наблюдателей.
//Кроме того, именно класс отвечает за обновление наблюдателей при любых изменениях

class Subject
{
private:
    vector<FileObserver*> subj;
public:
    void Attach(FileObserver *observer);
    void Detach(FileObserver *observer);
    void Notify(bool existence, long size);
};

//наследуем методы из класса Subject
class FileMonitor: public Subject {
private:
    File prev_state;
public:
    FileMonitor(string _name);
    void checkFile();
    void Change(bool existence, long size);
};


#endif // SUBJECT_H
