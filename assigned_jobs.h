#ifndef ASSIGNED_JOBS_H_INCLUDED
#define ASSIGNED_JOBS_H_INCLUDED

#include <ostream>

#include "job.h"

class AssignedJob {
public:
    Job* job;
    int t_debut, t_fin;
    AssignedJob(Job*, int, int);
    AssignedJob();
    void print();
};

std::ostream& operator<<(std::ostream& os, const AssignedJob& dt);

#endif // ASSIGNED_JOBS_H_INCLUDED
