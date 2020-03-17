#include <iostream>
#include <string>
#include <omp.h>
#include "../logger.hpp"
#include "../include/catch.hpp"

using namespace logger;

TEST_CASE("Test Case"){
    //get the reference to log
    Log& log = Log::GetInstance();
    //set the level, output steam and log file name

    SECTION("Can get instance?"){
        REQUIRE(log.GetLevel() == log.INFO);
        REQUIRE(log.GetOutputStream() == log.TERM);
        REQUIRE(log.GetFileName() == "log.txt");
    }

    log.SetLevel(log.WARN);
    log.SetOutputStream(log.BOTH);
    log.SetFileName("test_log.txt");

    SECTION("Can set attributes?"){
        REQUIRE(log.GetLevel() == log.WARN);
        REQUIRE(log.GetOutputStream() == log.BOTH);
        REQUIRE(log.GetFileName() == "test_log.txt");
    }

    SECTION("Can write in parallel?"){
        int failure = 0;
        try{
            #pragma omp parallel
            {
                int ID = omp_get_thread_num();
                log.info(std::to_string(ID)+": info!");
            }
        }
        catch(const std::exception& e){
            failure = 1;
        }
        REQUIRE(failure == 0);
    }
}
