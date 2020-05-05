/* Import */
#include <iostream> // Input-Output Stream
#include "src/lapys.hpp" // Lapys

/* Main */
int Lapys::Main(...) {
    // [Begin] ...
    ::write(STDOUT_FILENO, "[PROGRAM INITIATED]\n\r", 21u);

    Error errorA, errorB;

    objects.remove((object*) &errorA);

    // [End] ...
    ::write(STDOUT_FILENO, "[PROGRAM TERMINATED]\0", 21u);

    // Return
    return 0;
}
