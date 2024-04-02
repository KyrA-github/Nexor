#pragma once
#include "globals.hpp"
#include "filemake.hpp"
#include <Windows.h>

class compiler
{
private:
    string codes[10] = 
    {
        "#include "
    };

    HANDLE hConsole;
    
    filemake FileMake;

    string line;

    size_t pos;
    string str;

    int line_len;
    bool compilation(string file_name);
    int file(string file_name, int operation, string data);
public:
    void compiler_read();
    
};


