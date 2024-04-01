#include "globals.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc > 1) {
        string arg1 = argv[1];
        if (arg1 == "--version") {
            cout << "Nexor version 0.01" << endl;
            // Возвращаемся, так как уже вывели версию
            return 0;
        }
    }
    return 0;
}
