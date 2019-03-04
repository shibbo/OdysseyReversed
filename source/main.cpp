#include "svc.h"

int main(int argc, char **argv) 
{
    if (svcGetSystemTick() > 0) 
    {
        // if they opened this as a homebrew app they are doing it wrong
        while (1);
    }

    return 0;
}