#include <algorithm>
#include <iostream>
#include <fstream>
#include <string>
#include <queue>
#include "job.h"

using namespace std;

# define DEBUG 1

Job::Job() {};
Job::Job(int temps_execution, int moule) : temps_execution(temps_execution), moule(moule) {};
Job* Job::clone() {
    return new Job(temps_execution, moule);
}
void Job::print() {
    cout << "temps: " << temps_execution << ", moule: " << moule << endl;
}


Job *read_instance(fstream& newfile, int& number_of_jobs, int& number_of_molds, int& class_of_job, int& instance_of_job) {
    newfile >> number_of_jobs >> number_of_molds >> class_of_job >> instance_of_job;
    Job *jobs = new Job[number_of_jobs];

    if(DEBUG)
        cout << "Jobs: " << number_of_jobs << ", Molds: " << number_of_molds << " , Class: " << class_of_job << ", Instance: " << instance_of_job << endl; // file opened successfully so we are here

    for (int i = 0; i < number_of_jobs; i++)
    {
        newfile >> jobs[i].temps_execution;
    }

    for (int i = 0; i < number_of_jobs; i++)
    {
        newfile >> jobs[i].moule;
    }

    /*if(DEBUG)
        print(jobs, number_of_jobs);*/

    sort(jobs, jobs+number_of_jobs, [](Job& a, Job& b) { return a.temps_execution < b.temps_execution; });

    /*if(DEBUG)
        print(jobs, number_of_jobs);*/

    return jobs;
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
