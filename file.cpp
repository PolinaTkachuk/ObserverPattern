// Функция stat  берет  информацию  о файле или каталоге,определенном параметром path,
//и помещает ее в структуру, на которую указывает buf
#include <sys/stat.h>
#include"file.h"

File::File(string fileName)
{
    name = fileName; //задаем имя файла
    struct stat buf; //помещаем информацию о файле в структуру

    //stat возвращает 0,  если информация о состоянии файла восстановлена
    //При ошибке функция возвращает -1 и устанавливает errno в ENOENT, что указывает на плохой маршрут
    existence = stat(fileName.c_str(), &buf) == 0;

    //определяем размер
    size = buf.st_size;
}
