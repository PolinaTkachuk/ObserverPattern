#include "Subject.h"
#include <sys/stat.h>
//Определяем классы


void Subject::Attach(FileObserver *observer){
    //Добавление в конец
    //работа с вектором subj
    subj.push_back(observer);
}

void Subject::Detach(FileObserver *observer){
    //удаление
    subj.erase(remove(subj.begin(), subj.end(), observer),subj.end());
}

//Функция обновления вызывается операцией notify() объекта.
//Наблюдатели обновляются независимо,с учетом их текущего состояния.
void Subject::Notify(bool existence, long size){
    for(vector<FileObserver*>::const_iterator iter = subj.begin(); iter != subj.end(); iter++) {
        if (*iter != 0) {
            (*iter)->Update(existence, size);
        }
    }
}



FileMonitor::FileMonitor(string _name) : prev_state(_name) { }

void FileMonitor::checkFile() {
    File newFileState(prev_state.name);
//проверка файла на изменения
    Change(newFileState.existence, newFileState.size);
    prev_state = newFileState;
}

void FileMonitor::Change(bool existence, long size) {
    Notify(existence, size);
}
