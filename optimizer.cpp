#include <iostream>
#include "optimizer.h"

using namespace std;

AssignedJob* assign_job(Machine& machine1, Machine& machine2, Job& job) {
    int t1 = machine1.fitness();
    int dt;

    if(machine2.is_moule_utilise(job.moule, t1, t1 + job.temps_execution)) {
        dt = machine2.when_moule_libre(job.moule, t1, job.temps_execution);
        t1 += dt;
    }

    return new AssignedJob(&job, t1, t1 + job.temps_execution);
}

void assign_job_to_machine(Machine& machine1, Machine& machine2, Job& job) {
    AssignedJob *assigend_job1 = assign_job(machine1, machine2, job), *assigned_job2 = assign_job(machine2, machine1, job);
    if(assigend_job1->t_fin <= assigned_job2->t_fin) machine1.ajouter(*assigend_job1); else machine2.ajouter(*assigned_job2);
}

void assign_jobs(Machine& machine1, Machine& machine2, Job* jobs, int n) {
    for(int i=0; i<n; i++) {
        assign_job_to_machine(machine1, machine2, jobs[i]);
    }

    /*cout << "\nMachine 1\n";
    machine1.print_timeline();
    cout << "\n\nMachine 2\n";
    machine2.print_timeline();*/
}

int fitness(Machine& machine1, Machine& machine2) {
    return (machine1.fitness() > machine2.fitness()) ? machine1.fitness() : machine2.fitness();
}
