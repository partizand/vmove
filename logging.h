#ifndef LOGGING_H
#define LOGGING_H

#include <QString>

/** Создание логов.

  Логи создаются в подкаталоге log каталога программы. Имена файлов YYMMDD.log
  Вместо сообщения "-", создается "------" без даты
  */
class Logging
{
public:
    Logging();
    //! Запись сообщения в файл с добавлением файла
    void writeMessage(const QString &mess);
private:
    //! Каталог логов
    QString logDir;
};

#endif // LOGGING_H
