#include <iostream>

#include "assigned_jobs.h"

using namespace std;

#define DEBUG 1

AssignedJob::AssignedJob(Job* job, int debut, int fin) : job(job), t_debut(debut), t_fin(fin) {}

AssignedJob::AssignedJob(): job(), t_debut(0), t_fin(0) {}

void AssignedJob::print() {
    cout << 'temps: debut(' << this->t_debut << '), fin(' << this->t_fin << ')' << endl;
}

ostream& operator<<(ostream& os, const AssignedJob& dt)
{
    os << 'temps: debut(' << dt.t_debut << '), fin(' << dt.t_fin << ')' << endl;
    return os;
}
