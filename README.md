# example logging library in cpp

## implementation
This is a singleton implementation of log class with functions for writing info, warn, and error logs.

1. It can log strings to a file or to the terminal depending on the configuration
2. The caller is multithreaded
3. Logger has automated tests with Catch2 testing framework

### how to use
`#include "../logger.hpp"`
#### get the reference to log
`Log& log = Log::GetInstance();`
### how to set error level and outputstream configuration
```
log.SetLevel(log.WARN);
log.SetOutputStream(log.BOTH);
log.SetFileName("test_log.txt");
```

## How to Build Logging library on Windows 
1.  `x86_64-w64-mingw32-g++.exe -Wall -fexceptions -g -std=c++11 -fopenmp  -c D:\Libraries\Projects\cpp\example_logger\logger.cpp -o obj\Debug\logger.o`

# Optional building the main executable to run tests
1. `x86_64-w64-mingw32-g++.exe  -o bin\Debug\example_logger.exe obj\Debug\logger.o obj\Debug\main.o obj\Debug\tests\tests.o   "D:\Program Files (x86)\CodeBlocks\MinGW\bin\libgomp-1.dll"`

## How to run tests
1. `"D:\Libraries\Projects\cpp\example_logger\bin\Debug\example_logger.exe"`


## Testing Framework Used:
https://github.com/catchorg/Catch2


## output of test if it succeeds
```
[EPOCH] 1584429490, [INFO] 5: info!
[EPOCH] 1584429490, [INFO] 2: info!
[EPOCH] 1584429490, [INFO] 3: info!
[EPOCH] 1584429490, [INFO] 0: info!
[EPOCH] 1584429490, [INFO] 1: info!
[EPOCH] 1584429490, [INFO] 4: info!
[EPOCH] 1584429490, [INFO] 7: info!
[EPOCH] 1584429490, [INFO] 6: info!
===============================================================================
All tests passed (7 assertions in 1 test case)

Process returned 0 (0x0)   execution time : 0.033 s 
Press any key to continue
```