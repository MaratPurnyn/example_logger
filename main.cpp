#include <iostream>
#include <string>
#include <omp.h>
#include "logger.hpp"

using namespace std;
using namespace logger;

int main()
{
    //get the reference to log
    Log& log = Log::GetInstance();
    //set the level, output steam and log file name
    log.SetLevel(log.WARN);
    log.SetOutputStream(log.BOTH);
    log.SetFileName("log.txt");
    #pragma omp parallel
    {
        int ID = omp_get_thread_num();
        log.warn(to_string(ID)+": warn!");
        log.info(to_string(ID)+": info!");
        log.error(to_string(ID)+": error!");
    }
    return 0;
}
