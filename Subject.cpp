#include "Subject.h"
#include <sys/stat.h>
//Определяем классы


void Subject::Attach(FileObserver *observer)//метод подписки объекта для оповещения
{
    //Запоминаем запрос на добавление Наблюдателя
    subj.push_back(observer);
}

void Subject::Detach(FileObserver *observer)//метод исключения подписки объекта от оповещения
{
    //удаление
    subj.erase(remove(subj.begin(), subj.end(), observer),subj.end());
}

//Функция обновления вызывается операцией notify() объекта.
//Наблюдатели обновляются независимо,с учетом их текущего состояния.
void Subject::Notify(bool existence, long size)//метод оповещения
{
    for(vector<FileObserver*>::const_iterator iter = subj.begin(); iter != subj.end(); iter++) {
        if (*iter != 0) {
            (*iter)->Update(existence, size);
        }
    }
}



FileConcreteSubject::FileConcreteSubject(string _name) : prev_state(_name) { }

void FileConcreteSubject::checkFile() {
    File newFileState(prev_state.name);
//проверка файла на изменения, вызов через функцию метод отслеживающий обновления
    Change(newFileState.existence, newFileState.size);
    prev_state = newFileState;
}

void FileConcreteSubject::Change(bool existence, long size) {
    Notify(existence, size);
}
