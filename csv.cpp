#include "csv.h"

using namespace std;

CSV::CSV(string filename): filename(filename), file() {
    file.open(filename, ios::out);
    file << "number of jobs,number of molds,class,instance number,execution time\n";
}

void CSV::write(int jobs, int molds, int className, int instance, float temps_execution) {
    file << jobs << ',' << molds << ',' << className << ',' << instance << ',' << temps_execution << '\n';
}

CSV::~CSV() {
    file.close();
}
