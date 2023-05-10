#include <iostream>
#include <string>

#include "machine.h"

using namespace std;

#define DEBUG 1

Machine::Machine(int s): assigned_jobs() {}

Machine::Machine(): assigned_jobs() {}

void Machine::ajouter(AssignedJob& assigned_job) {
    assigned_jobs.push_back(assigned_job);
}

int Machine::fitness() {
    if(assigned_jobs.empty()) return 0;
    return assigned_jobs.back().t_fin;
}

void Machine::print() {
    cout << '\n';
    for (vector<AssignedJob>::iterator it = assigned_jobs.begin() ; it != assigned_jobs.end(); ++it)
        cout << '\n' << *it;
    cout << '\n\n';
}

void Machine::print_timeline() {
    for(int i=0; i<assigned_jobs.size(); i++) {
        for(int j=assigned_jobs[i].t_debut; j<assigned_jobs[i].t_fin; j++) cout << assigned_jobs[i].job->moule;
        if(i>0) {
            for(int j=assigned_jobs[i-1].t_fin; j<assigned_jobs[i].t_debut; j++) cout << 0;
        }
    }
}

bool Machine::is_moule_utilise(int moule, int t1, int t2) {
    int texec = 0;
    if(assigned_jobs.size() == 0) return false;
    for (int i=0; i<assigned_jobs.size(); i++) {
        if(texec + assigned_jobs[i].job->temps_execution > t1)
            if(assigned_jobs[i].job->moule == moule) return true;
        if(texec + assigned_jobs[i].job->temps_execution >= t2) break;
        texec += assigned_jobs[i].job->temps_execution;
    }
    return false;
}

int Machine::when_moule_libre(int moule, int t, int dt) {
    vector<AssignedJob>::iterator it = assigned_jobs.begin();
    while(it->t_fin <= t) ++it;
    int tp = t;
    while(is_moule_utilise(moule, tp, tp + dt)) {
        tp = it->t_fin;
        ++it;
    }
    return tp;
}
