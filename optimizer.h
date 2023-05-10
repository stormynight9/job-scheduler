#ifndef OPTIMIZER_H_INCLUDED
#define OPTIMIZER_H_INCLUDED

#include "machine.h"
#include "assigned_jobs.h"

AssignedJob* assign_job(Machine& machine1, Machine& machine2, Job& job);

void assign_job_to_machine(Machine& machine1, Machine& machine2, Job& job);

void assign_jobs(Machine& machine1, Machine& machine2, Job* jobs, int n);

int fitness(Machine& machine1, Machine& machine2);

#endif // OPTIMIZER_H_INCLUDED
