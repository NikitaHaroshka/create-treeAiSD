#include <iostream>
#include <fstream>
#include <set>
#include <vector>
using namespace std;
int main()
{
    ifstream inputFile("input.txt");
    ofstream outputFile("output.txt");
    if (!inputFile) {
        cerr << "Ошибка открытия входного файла!" << endl;
        return 1;
    }
    if (!outputFile) {
        cerr << "Ошибка открытия выходного файла!" << endl;
        return 1;
    }
    


    inputFile.close();
    outputFile.close();

    return 0;
}
