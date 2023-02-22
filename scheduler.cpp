#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    fstream newfile;
    newfile.open("sample.txt", ios::out); // open a file to perform write operation using file object
    if (newfile.is_open())                // checking whether the file is open {
        newfile << "Tutorials point \n";  // inserting text
    newfile.close();                      // close the file object
}