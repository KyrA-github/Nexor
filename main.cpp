#include "globals.h"
#include "compiler.h"
#include "filemake.h"

using namespace std;

int main(int argc, char *argv[]) {

    string for_argv;
    string list_argv[3] = {"_","_","_"};;

    for(int i = 0; i < argc; i++) {
        for_argv = argv[i];
        list_argv[i] = for_argv;
    }

    if (list_argv[1] == "--version")
    {
        cout << "Nexor version 0.01" << endl;
        return 0;
    }
    else if (list_argv[1] == "help")
    {
        cout << "commands:\n[Nexore --version, Nexor make, Nexor make -e, Nexor help]" << endl;
    }
    else if (list_argv[1] == "make")
    {
        filemake file;
        file.file_make_read();
    }
    else if (list_argv[1] == "make" && list_argv[2] == "-e")
    {
        /* code */
    }
    else
    {
        cout << "<Nexor help>" << endl;
    }

    return 0;
}
