#include <iostream>
#include <chrono>
#include "job.h"
#include "machine.h"
#include "optimizer.h"
#include "csv.h"

using namespace std;

using namespace std;

int main()
{
    fstream newfile;
    CSV csv("preformances.csv");

    Job *jobs;
    int number_of_jobs, number_of_molds, number_of_instances, class_of_job, instance_of_job;

    newfile.open("instances-A.txt", ios::in); // open a file to perform write operation using file object
    if (newfile.is_open())               // checking whether the file is open
    {
        newfile >> number_of_instances;
        cout << "Instances: " << number_of_instances << "\n\n===========================================================================================================\n\n\n\n";
        for(int i=0; i<number_of_instances; i++) {
            jobs = read_instance(newfile, number_of_jobs, number_of_molds, class_of_job, instance_of_job);
            Machine m1, m2;
            auto start = std::chrono::steady_clock::now();
            assign_jobs(m1, m2, jobs, number_of_jobs);
            auto end = std::chrono::steady_clock::now();
            std::chrono::duration<double> elapsed_seconds = end-start;
            csv.write(number_of_jobs, number_of_molds, class_of_job, i+1, elapsed_seconds.count());
            cout << "\nFitness : " << fitness(m1, m2) << ",\tElapsed time: " << elapsed_seconds.count() << "\n\n============================================================================================================\n\n";
            delete[] jobs;
        }
        newfile.close(); // close the file object.
    }
}
