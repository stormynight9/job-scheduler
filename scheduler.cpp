#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    fstream newfile;
    int number_of_jobs, number_of_molds;
    int *jobs[2];
    newfile.open("sample.txt", ios::in); // open a file to perform write operation using file object
    if (newfile.is_open())               // checking whether the file is open
    {
        newfile >> number_of_jobs >> number_of_molds;
        cout << number_of_jobs << " " << number_of_molds; // file opened successfully so we are here
        jobs[0] = new int[number_of_jobs];
        jobs[1] = new int[number_of_jobs];
        for (int i = 0; i < number_of_jobs; i++)
        {
            newfile >> jobs[0][i];
            cout << jobs[0][i] << " ";
        }
        for (int i = 0; i < number_of_jobs; i++)
        {
            newfile >> jobs[1][i];
            cout << jobs[1][i] << " ";
        }

        newfile.close(); // close the file object.
    }
}