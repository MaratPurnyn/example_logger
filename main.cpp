#include <iostream>
#include <string>
#include <mutex>
#include <thread>
#include <omp.h>
#include <fstream>

using namespace std;

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
    mutex mtx_;
    ofstream outFile_;

    //functions
    void Write(string msg){
        mtx_.lock();
        switch(output_stream_) {
            case BOTH :
                cout << msg << endl;
                outFile_ << msg << endl;
                break;
            case TERM :
                cout << msg << endl;
                break;
            case FILE :
                outFile_ << msg << endl;
                break;
        }
        mtx_.unlock();
    }
public:
    //initialization
    Log(Level level = INFO, OutputStream os = TERM, string output_file_name="log.txt"){
        SetLevel(level);
        SetOutputStream(os);
        SetOutputFileName(output_file_name);
    }
    ~Log(){
        //deconstructor
        cout << "End of Log" << endl;
    }
    //setting functions
    void SetLevel(Level level){
        log_level_ = level;
    }
    void SetOutputStream(OutputStream os){
        output_stream_ = os;
    }
    void SetOutputFileName(string fname){
        if(outFile_.is_open()){
            outFile_.close();
        }
        outFile_.open(fname);
    }

    // logging functions
    void info(string kMessage)
    {
        if(log_level_ >= INFO){
            string msg = "[INFO:] ";
            msg += kMessage;
            Write(msg);
        }
    }
    void warn(string kMessage)
    {
        if(log_level_ >= WARN){
            string msg = "[WARN:] ";
            msg += kMessage;
            Write(msg);
        }
    }
    void error(string kMessage)
    {
        if(log_level_ >= ERROR){
            string msg = "[ERROR:] ";
            msg += kMessage;
            Write(msg);
        }
    }
};

int main()
{
    Log log(log.ERROR, log.BOTH);
    #pragma omp parallel
    {
        int ID = omp_get_thread_num();
        string warnMsg = to_string(ID);
        warnMsg += ": warn!";
        log.warn(warnMsg);
        log.info("info!");
        log.error("error!");
    }
    return 0;
}
