#include "filemake.hpp"

void filemake::file_make_read(){
    ifstream myfile(file_dir_name);

    compiler_info cmp_inf;

    if (myfile.is_open())
    {
        while (getline(myfile,line))
        {
            str = line;
            pos = str.find('=');
            pos_commit = str.find('#');
            if (pos_commit == string::npos) {
                if (pos != string::npos) 
                {
                    left_part = str.substr(0, pos);
                    right_part = str.substr(pos + 1);

                    if(left_part == "version")
                    {
                        cmp_inf.compiler_version = stof(right_part);
                    }
                    else if (left_part == "compiler")
                    {
                        cmp_inf.compiler_name = right_part;
                    }
                    else if(left_part == "make_dir"){
                        cmp_inf.make_dir = right_part;
                    }
                    else if (left_part == "make_file")
                    {
                        cmp_inf.make_file = right_part;
                    }
                    else if (left_part == "output_dir")
                    {
                        cmp_inf.output_dir = right_part;
                    }
                    else if (left_part == "output_cpp")
                    {
                        cmp_inf.output_cpp = right_part;
                    }
                }
            }
            
        }
        myfile.close();
    }
    
}
filemake::compiler_info filemake::getCompilerInfo() const{
    compiler_info compiler_info;
    return compiler_info;
}
