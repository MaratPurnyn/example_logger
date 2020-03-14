#include <iostream>
#include <string>

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

    //functions
    void Write(string msg){
        switch(output_stream_) {
            case BOTH : cout << msg << endl; break;
            case TERM : cout << msg << endl; break;
            case FILE : break;
        }
    }
public:
    //initialization
    Log(Level level = INFO, OutputStream os = TERM){
        SetLevel(level);
        SetOutputStream(os);
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

    // logging functions
    void info(const char* kMessage)
    {
        if(log_level_ >= INFO){
            string msg = "[INFO:] ";
            msg += kMessage;
            Write(msg);
        }
    }
    void warn(const char* kMessage)
    {
        if(log_level_ >= WARN){
            string msg = "[WARN:] ";
            msg += kMessage;
            Write(msg);
        }
    }
    void error(const char* kMessage)
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
    Log log(log.ERROR, log.TERM);
    log.warn("warn!");
    log.info("info!");
    log.error("error!");
    cin.get();
    return 0;
}
