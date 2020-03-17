#ifndef LOGGER_INCLUDED
#define LOGGER_INCLUDED
#include <iostream>
#include <fstream>
#include <string>
#include <omp.h>
#include <mutex>
#include <thread>

namespace logger{

class Log{
public:
    //singleton instance
    static Log& GetInstance()
    {
        static Log instance;
        return instance;
    }
    ~Log();
    //singleton implementation
    Log(const Log&) = delete;
    void operator=(Log const&)  = delete;
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
    std::string output_file_name_;
    // Lock to make the class thread-safe
    std::mutex mtx_;
    std::ofstream outFile_;

    //functions
    Log(Level level = INFO, OutputStream os = TERM, std::string output_file_name="log.txt");

    void Write(std::string msg);
public:
    // setting functions
    void SetLevel(Level level);
    void SetOutputStream(OutputStream os);
    void SetFileName(std::string fname);

    // getting functions
    Level GetLevel();
    OutputStream GetOutputStream();
    std::string GetFileName();

    // logging functions
    void info(std::string msg);
    void warn(std::string msg);
    void error(std::string msg);
};

}
#endif // LOGGER_INCLUDED
