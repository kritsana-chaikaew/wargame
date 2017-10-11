#include <stdio.h>
#include <stdlib.h>
#include  <string.h>
#include <math.h>
int main(int argc, char**argv)
{
   int a = 0x80000001;
    //printf("%x\n%d", atoi(argv[2]), atoi(argv[2]));
    printf("%d\n%d\n",a, abs(a));
    return 0;
}
