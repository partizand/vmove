#include "movefile.h"

/*
MoveFileEntry::MoveFileEntry(const QString &FileName,const QString &FileDisplay=""):
        fileName(FileName)
{
    if (FileDisplay=="")
    {
        fileDisplay=FileName;
    }
    else
    {
        fileDisplay=FileDisplay;
    }
}

*/
MoveFile::MoveFile()
{
}
MoveFile::MoveFile(const QString &FileName,const QString &FileDisplay):
        fileName(FileName)
{

   if (FileDisplay=="")
   {
       fileDisplay=FileName;
   }
   else
   {
       fileDisplay=FileDisplay;
   }
}
