#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()

{
    int n;
    int fd[2];          // file descriptor fd[0] is read end, f[1] is write end
    char buf[1024];     // buffer for write
    char* data = "Hello World!";

    pipe(fd);           //create a pipe

    /*      f[0] <---------- f[1]           */

    write(fd[1], data, strlen(data));

    if ((n = read(fd[0], buf, 1024)) >= 0)
    {
        buf[n] = 0;     // terminate string
        printf("data is: \"%s\"\n", buf);
    }
    else
    {
        perror("read");
    }
    exit(0);
}
