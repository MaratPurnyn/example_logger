#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <omp.h>
#include <mutex>
#include <thread>

namespace log{

class Log{
public:
    //variables
    enum Level{
        INFO, WARN, ERROR
    };
    enum OutputStream{
        TERM, FILE, BOTH
    };
private:
    //variables
    Level log_level_;
    OutputStream output_stream_;
    // Lock to make the class thread-safe
    std::mutex mtx_;
    std::ofstream outFile_;

    //functions
    void Write(std::string msg);
public:
    //initialization
    Log(Level level = INFO, OutputStream os = TERM, std::string output_file_name="log.txt");
    ~Log();
    //setting functions
    void SetLevel(Level level);
    void SetOutputStream(OutputStream os);
    void SetOutputFileName(std::string fname);

    // logging functions
    void info(std::string msg);
    void warn(std::string msg);
    void error(std::string msg);
};

}
