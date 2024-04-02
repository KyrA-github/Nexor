#include <windows.h>
#include "globals.hpp"
#include "compiler.hpp"
#include "filemake.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    string currentDir;
    char buffer[MAX_PATH];

    if (GetCurrentDirectory(MAX_PATH, buffer) != 0) {
        string currentDir = buffer;
    } else {
        cerr << "Error getting current working directory\n";
        return 1;
    }

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
        cout << 1 << endl;
        compiler cmp;
        cmp.file_make_read(currentDir);
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
