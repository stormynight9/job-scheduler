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
    Job() {};
    Job(int temps_execution, int moule) : temps_execution(temps_execution), moule(moule) {};
    Job clone() {
        return Job(temps_execution, moule);
    }
};

void print(Job *jobs, int number_of_jobs);
void print(Job job);

Job *read_instance(fstream& newfile, int& number_of_jobs, int& number_of_molds, int& instance_of_job) {
    int class_of_job;
    newfile >> number_of_jobs >> number_of_molds >> class_of_job >> instance_of_job;
    Job *jobs = new Job[number_of_jobs];

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

void print(Job job) {
    cout << "temps: " << job.temps_execution << ", moule: " << job.moule << endl;
}

void print(queue<Job> m) {
    while(!m.empty()) {
        Job job = m.front();
        for(int i = 0; i < job.temps_execution; i++)
            cout << job.moule << " ";
        m.pop();
    }
    cout << endl;
}

Job& get_moule_at(int temps, queue<Job> m) {
    Job *job = new Job;

    job->temps_execution = 0;
    job->moule = 0;

    while(!m.empty() && job->temps_execution <= temps) {
        job->temps_execution += m.front().temps_execution;
        job->moule = m.front().moule;
        m.pop();
    }
    return *job;
}

int get_next_at(queue<Job> m) {
    int temps = 0;

    while(!m.empty()) {
        temps += m.front().temps_execution;
        m.pop();
    }

    return temps;
}

bool job_valid_for_m1(Job& job, const queue<Job> m1, const queue<Job> m2) {
    int ta = get_next_at(m1);
    Job& job1 = get_moule_at(ta, m2);
    if(job.moule == job1.moule){
        return false;
        // int temps_reste = job.temps_execution - ta;
        // if()
        // m1.push({temps_reste, 0});
        // m1.push(job);
    }
    else
        return true;
}

void assign_jobs(Job *jobs, queue<Job>& m1, queue<Job>& m2, int number_of_jobs, int number_of_molds) {
    for(int i = 0; i < number_of_jobs; i++) {
        int ta1 = get_next_at(m1), ta2 = get_next_at(m2);
        Job& job1 = get_moule_at(ta1, m2), &job2 = get_moule_at(ta2, m1);

        if(DEBUG) {
            cout << "info pour job " << i << endl;
            print(jobs[i]);
            cout << endl;
            cout << "temps attente machine 1: " << ta1 << ", temps attente machine 2: " << ta2 << endl;
            cout << "pour t=" << ta1 << " pour machine 1 on a le temps pour ceder le moule pour machine 2: " << job1.temps_execution << ", moule utilise machine 2: " << job1.moule << endl;
            cout << "pour t=" << ta2 << " pour machine 2 on a le temps pour ceder le moule pour machine 1: " << job2.temps_execution << ", moule utilise machine 2: " << job2.moule << endl;
        }

        if(ta1 <= ta2) {
            bool is_valid = job_valid_for_m1(jobs[i], m1, m2);
            if(DEBUG)
                cout << is_valid << endl;
            if(is_valid){
                m1.push(Job(jobs[i]));
            }
            else {
                int temps_reste = jobs[i].temps_execution - ta1;
                m1.push(Job(temps_reste, 0));
                m1.push(Job(jobs[i]));
            }
        } else {
            bool is_valid = job_valid_for_m1(jobs[i], m2, m1);
            if(DEBUG)
                cout << is_valid << endl;
            if(is_valid)
                m2.push(jobs[i]);
            else {
                int temps_reste = jobs[i].temps_execution - ta2;
                m2.push({temps_reste, 0});
                m2.push(jobs[i]);
            }
        }

        if(DEBUG) {
            cout << "machine 1: " << endl;
            print(m1);
            cout << endl;
            cout << "machine 2: " << endl;
            print(m2);
            cout << endl;
        }
    }
}

int main()
{
    fstream newfile;
    
    Job *jobs;
    int number_of_jobs, number_of_molds, instance_of_job;

    queue<Job> m1 = queue<Job>(), m2 = queue<Job>();

    newfile.open("sample2.txt", ios::in); // open a file to perform write operation using file object
    if (newfile.is_open())               // checking whether the file is open
    {
        jobs = read_instance(newfile, number_of_jobs, number_of_molds, instance_of_job);
        assign_jobs(jobs, m1, m2, number_of_jobs, number_of_molds);
        
        cout << "temps total machine 1: " << get_next_at(m1) << endl;
        cout << "temps total machine 2: " << get_next_at(m2) << endl;
        cout << "temps total: " << (get_next_at(m1) > get_next_at(m2) ? get_next_at(m1) : get_next_at(m2)) << endl;

        print(m1);
        cout << endl;
        print(m2);

        newfile.close(); // close the file object.
    }
}