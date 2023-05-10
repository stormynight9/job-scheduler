#ifndef CSV_H_INCLUDED
#define CSV_H_INCLUDED

#include <string>
#include <fstream>

class CSV {
public:
    std::string filename;
    std::fstream file;
    CSV(std::string filename);
    ~CSV();
    void write(int jobs, int molds, int className, int instance, float temps_execution);
};

#endif // CSV_H_INCLUDED
