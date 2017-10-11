#include <stdio.h>

unsigned long int check(const char* n)
{
    int* ip = (int*)n;
    int i = 0;
    int r;
    for (i=0; i<5; i++)
    {
        r += ip[i];
        printf("%x\n", ip[i]);
    }
    printf("%x", r);
    return r;
    
}

int main(int argc, char** argv)
{
    printf("%lx\n", *((unsigned long*)argv[1]));
    if (check(argv[1])==0x21dd09ec)
    {
        printf("FOUND");
    }
    return -1;
}
