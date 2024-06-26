#include "compiler.hpp"

void compiler::compiler_read()
{   
    ifstream file_sourse(cmp_inf.make_dir + cmp_inf.make_file);

    if (file_sourse.is_open())
    {
        cout << "Start compilation" << endl;
        file(cmp_inf.output_dir + cmp_inf.output_cpp, 1, "");
        while (getline(file_sourse, line_f))
        {
            line_len += 1;
            if(compilation(cmp_inf.output_dir + cmp_inf.output_cpp))
            {
                cout << "Line " <<  line_len << " compiled: ok" << endl;
            }
            else
            {
                cerr << "Line " <<  line_len <<  "compiled: error"<< endl;
            }
        }
        line_len = 0;
        file_sourse.close();
        file(cmp_inf.output_dir + cmp_inf.output_cpp, 2, "");
    }
    else
    {
        cerr << "Error: File not found" << endl;
    }      
}

bool compiler::compilation(string file_name)
{
    str = line_f;
    str_c = line_f;

    for (const auto& phrase : phrases) {
        size_t pos = str.find(phrase);
        if (pos != string::npos) {
            if (phrase == "import") 
            {
                file(file_name, 3, codes[0]);
                file(file_name, 3, codes[1]);
                pos_commit_c = str_c.find(' ');
                if (pos_commit_c == string::npos) {
                    left_part_c = str_c.substr(0, pos_commit_c);
                    right_part_c = str_c.substr(pos_commit_c + 1);
                    if (right_part_c == "base")
                    {
                        file(file_name, 3, codes[2]);
                    }
                    
                }
                
            }
        } else {
            
        }
    }
    return true;
}

int compiler::file(string file_name, int operation, string data)
{
    fstream file(file_name, ios::in | ios::app);

    if (operation == 1){
        if (!file.is_open()) 
        { 
            cout << "File not found. Creating a new file..."<< endl;

            file.open("example.txt", ios::in | ios::app); 

            if (file.is_open()) { 
                cout << "New file created." << endl;
            } else { 
                cerr << "Failed to create new file." << endl;
                return 1;
            }
        }
         else { 
            cout << "File opened successfully."<< endl;
        }
    }
    else if (operation == 2)
    {
       file.close();
       if (file.is_open())
       {
            cerr << "Failed close file." << endl;
       }
    }
    else if (operation == 3)
    {
        cout << "writing line: " << line_len << endl;
        file << data;
    }
    else
    {
        return 0;
    }
    
}

void compiler::file_make_read(string currentDir)
{
    ifstream file(currentDir + "NexorMake.txt");

    if (file.is_open())
    {
        cout << "File make is open" << endl;
        while (getline(file,line_m))
        {
            str_m = line_m;
            pos_m = str_m.find('=');
            pos_commit_m = str_m.find('#');
            if (pos_commit_m == string::npos) {
                if (pos_m != string::npos) 
                {
                    left_part_m = str_m.substr(0, pos_m);
                    right_part_m = str_m.substr(pos_m + 1);
                    if(left_part_m == "version")
                    {
                        cmp_inf.compiler_version = stof(right_part_m);
                    }
                    else if (left_part_m == "compiler")
                    {
                        cmp_inf.compiler_name = right_part_m;
                    }
                    else if(left_part_m == "make_dir"){
                        cmp_inf.make_dir = right_part_m;
                    }
                    else if (left_part_m == "make_files")
                    {
                        cmp_inf.make_file = right_part_m;
                    }
                    else if (left_part_m == "output_dir")
                    {
                        cmp_inf.output_dir = right_part_m;
                    }
                    else if (left_part_m == "output_cpp")
                    {
                        cmp_inf.output_cpp = right_part_m;
                    }
                    
                }
            }
            
        }
        file.close();
        compiler_read();
    }
    else
    {
        cerr << "Error open make file" << endl;
    }
}
