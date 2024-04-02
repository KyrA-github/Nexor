#include "compiler.hpp"

void compiler::compiler_read()
{
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    auto struct_make = FileMake.getCompilerInfo();

    ifstream file(struct_make.make_dir + struct_make.make_file);

    if (!file.is_open())
    {
        while (getline(file, line))
        {
            line_len += 1;
            if(compilation(struct_make.output_dir + struct_make.output_cpp))
            {
                cout << "Line" <<  line_len << " compiled: ok" << endl;
            }
            else
            {
                cerr << "Line" <<  line_len <<  "compiled: ";
                SetConsoleTextAttribute(hConsole, 12);
                cerr << "error" << endl;
                SetConsoleTextAttribute(hConsole, 7);
            }
        } 
        line_len = 0;
        file.close();
    }
    else
    {
        cerr << "Error: File not found" << endl;
    }      
}

bool compiler::compilation(string file_name)
{
    str = line;
    vector<string> phrases = {"!import"};

    for (const auto& phrase : phrases) {
        size_t pos = str.find(phrase);
        if (pos != string::npos) {
            cout << "String :" << phrase << "Pos:" << pos << endl;
            if (phrase == "!import") 
            {
                file(file_name, 3, codes[0]);
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
       if (!file.is_open())
       {
            cerr << "Failed close file." << endl;
       }
    }
    else if (operation == 3)
    {
        file << data;
    }
}