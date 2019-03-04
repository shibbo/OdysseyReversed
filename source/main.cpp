#include "svc.h"
#include "types.h"

// Write your code here.
void your_code_func()
{

}

int main(int argc, char **argv) 
{
    // this is to ensure that this isn't being ran by the HBL
    if (svcGetSystemTick() > 0) 
    {
        return 0;
    }

    your_code_func();
}