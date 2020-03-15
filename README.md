# example logging library in cpp

1. It can log strings to a file or to the terminal depending on the configuration
2. The caller is multithreaded (the log handles multiple threads using it)
3. Logger has automated tests with your choice of testing framework


How to compile on Windows
`x86_64-w64-mingw32-g++.exe -Wall -fexceptions -g -std=c++11 -fopenmp  -c D:\Libraries\Projects\cpp\example_logger\main.cpp -o obj\Debug\main.o`
`x86_64-w64-mingw32-g++.exe  -o bin\Debug\example_logger.exe obj\Debug\main.o   "D:\Program Files (x86)\CodeBlocks\MinGW\bin\libgomp-1.dll"`
