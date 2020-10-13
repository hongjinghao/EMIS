#include "emis.h"

int main(int argc, char const *argv[])
{
    EMIS& emis = EMIS::getOBJ();
    emis.emisMenu();
    return 0;
}
