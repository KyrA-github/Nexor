#include "filemake.h"

void filemake::file_make_read(){
    std::ifstream myfile("config.txt");
    if (myfile.is_open()) // если файл открыт
    {
        while ( getline (myfile,line) )//пока не достигнут конец файла
        {
            string str = line;
    
            // Найдем позицию символа равенства
            size_t pos = str.find('=');
            
            if (pos != string::npos) {
                // Извлечем подстроки до и после символа равенства
                left_part = str.substr(0, pos);
                right_part = str.substr(pos + 1);
                if(left_part == "compileter"){
                    cout << "compileter = " << right_part << endl;
                }
            } else {
                cout << "error" << endl;
            } 
        }
        myfile.close();
        }
    
}