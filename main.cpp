#define CATCH_CONFIG_RUNNER

#include "include/catch.hpp"

using namespace std;

int main( int argc, char* argv[] )
{
    Catch::Session session;

    int result = session.run( argc, argv );

    return result;
}
