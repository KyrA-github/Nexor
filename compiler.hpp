#pragma once
#include "globals.hpp"
#include "struct.hpp"

class compiler
{
public:
    void compiler_read();
    void file_make_read(string currentDir);
private:
    compiler_info cmp_inf;
    string codes[10] = 
    {
        "#include "
    };

    int line_len = 0;
    
    string line_f;
    
    size_t pos;
    string str;

    size_t pos_m;
    size_t pos_commit_m;

    string file_dir_name_m;

    string str_m;
    string right_part_m;
    string left_part_m;

    struct compiler_info {
        float compiler_version;
        string compiler_name;
        string make_dir;
        string make_file;
        string output_dir;
        string output_cpp;
    };
    
    string line_m;

    bool compilation(string file_name);
    int file(string file_name, int operation, string data);
};


