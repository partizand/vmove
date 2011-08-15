#ifndef LOGGING_H
#define LOGGING_H

#include <QString>

/** �������� �����.

  ���� ��������� � ����������� log �������� ���������. ����� ������ YYMMDD.log
  ������ ��������� "-", ��������� "------" ��� ����
  */
class Logging
{
public:
    Logging();
    //! ������ ��������� � ���� � ����������� �����
    void writeMessage(const QString &mess);
private:
    //! ������� �����
    QString logDir;
};

#endif // LOGGING_H
