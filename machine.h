#ifndef MACHINE_H_INCLUDED
#define MACHINE_H_INCLUDED

#include <vector>
#include "assigned_jobs.h"

class Machine {
public:
    std::vector<AssignedJob> assigned_jobs;
    Machine(int s);
    Machine();
    void ajouter(AssignedJob& job);
    int fitness();
    void print();
    void print_timeline();
    bool is_moule_utilise(int moule, int t1, int t2);
    int when_moule_libre(int moule, int t, int dt);
};


#endif // MACHINE_H_INCLUDED
