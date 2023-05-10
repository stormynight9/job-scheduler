#ifndef JOB_H_INCLUDED
#define JOB_H_INCLUDED

#include <queue>
#include <fstream>

class Job {
public:
    int temps_execution, moule;
    Job();
    Job(int temps_execution, int moule);
    Job* clone();
    void print();
};

/*
 * prints the list of jobs
 * @param jobs : a pointer on a job array
 * @param number_of_jobs : the length of the array
 */
void print(Job *jobs, int number_of_jobs);

/*
 * reads instances from a text file
 * @param newfile : file path to read from
 * @param number_of_jobs : a reference on an integer that will be assigned to the number of jobs
 * @param number_of_molds : a reference on an integer that will be assigned to the number of molds
 * @param instance_of_job : a reference on an integer that will be assigned to the instance number of the job
 */
Job *read_instance(std::fstream& newfile, int& number_of_jobs, int& number_of_molds, int& class_of_job, int& instance_of_job);

#endif // JOB_H_INCLUDED
