#pragma once
#include "globals.h"

class filemake
{
private:
    size_t pos;
    size_t pos_commit;
    string file_dir_name;
    string str;
    string left_part;
    string right_part;
    string line;

    struct compiler_info {
        float compiler_version;
        string compiler_name;
        string make_dir;
        string make_file;
        string output_dir;
    };

public:
    filemake();
    void file_make_read();
    compiler_info getCompilerInfo() const;
    ~filemake();
};

