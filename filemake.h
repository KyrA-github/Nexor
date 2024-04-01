#pragma once
#include "globals.h"

class filemake
{
private:
    string str;
    string left_part;
    string right_part;
    string line;//строка для записи
public:
    filemake();
    void file_make_read();
    ~filemake();
};

