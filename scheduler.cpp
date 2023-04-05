#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

# define DEBUG 1

// enum TypeHe { Shortest, Longest };

// # define TYPE_HE Longest

// # if TYPE_HE == Shortest
// #  define COMPARE(a, b) (a.temps_execution < b.temps_execution)
// # elif TYPE_HE == Longest
// #  define COMPARE(a, b) (a.temps_execution > b.temps_execution)
// # endif

struct Job {
    int temps_execution, moule;
};

void print(Job *jobs, int number_of_jobs);

void read_instance(fstream& newfile, Job *jobs, int& number_of_jobs, int& number_of_molds, int& instance_of_job) {
    int class_of_job;
    newfile >> number_of_jobs >> number_of_molds >> class_of_job >> instance_of_job;
    jobs = new Job[number_of_jobs];

    if(DEBUG)
        cout << number_of_jobs << " " << number_of_molds << " " << class_of_job << " " << instance_of_job << endl; // file opened successfully so we are here

    for (int i = 0; i < number_of_jobs; i++)
    {
        newfile >> jobs[i].temps_execution;
    }

    for (int i = 0; i < number_of_jobs; i++)
    {
        newfile >> jobs[i].moule;
    }

    if(DEBUG)
        print(jobs, number_of_jobs);

    // sort(jobs, jobs+number_of_jobs, [](Job& a, Job& b) { return COMPARE(a, b); });
    sort(jobs, jobs+number_of_jobs, [](Job& a, Job& b) { return a.temps_execution < b.temps_execution; });

    if(DEBUG)
        print(jobs, number_of_jobs);
}

void print(Job *jobs, int number_of_jobs) {
    for (int i = 0; i < number_of_jobs; i++)
    {
        cout << jobs[i].temps_execution << " ";
    }
    cout << endl;
    for (int i = 0; i < number_of_jobs; i++)
    {
        cout << jobs[i].moule << " ";
    }
    cout << endl;
}

void assign_jobs(Job *jobs, int number_of_jobs, int number_of_molds) {
    // TODO
}

int main()
{
    fstream newfile;
    
    Job *jobs;
    int number_of_jobs, number_of_molds, instance_of_job;

    queue<Job> m1, m2;

    newfile.open("sample.txt", ios::in); // open a file to perform write operation using file object
    if (newfile.is_open())               // checking whether the file is open
    {
        read_instance(newfile, jobs, number_of_jobs, number_of_molds, instance_of_job);
        // cout << number_of_jobs << " " << number_of_molds << " " << class_of_job << " " << instance_of_job << endl; // file opened successfully so we are here
        
        

        newfile.close(); // close the file object.
    }
}