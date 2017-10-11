#include <stdio.h>
#include <stdlib.h>

unsigned char mem[20];
unsigned char blk[5][4];
unsigned char res[4];
unsigned char answer[5][4]; 
unsigned char hash[4];

int check_byte(unsigned char* b, int ind)
{
    if(b[ind] == hash[ind])
    {
        return 1;
    }
    
    return 0;
}
unsigned long int check_word(const char* s)
{
    return 0;
}

int main(int argc, char* argv[])
{
    unsigned int* ip = (unsigned int*)hash;
    unsigned char* cp = (unsigned char*)ip;
    *ip = 0x21dd09ec;
    ip = (int*)res;
    blk[0][0] = '0';
    blk[0][1] = '0';
    blk[0][2] = '0';
    blk[0][3] = '0';
    blk[1][0] = '0';
    blk[1][1] = '0';
    blk[1][2] = '0';
    blk[1][3] = '0';
    blk[2][0] = '0';
    blk[2][1] = '0';
    blk[2][2] = '0';
    blk[2][3] = '0';
    blk[3][0] = '0';
    blk[3][1] = '0';
    blk[3][2] = '0';
    blk[3][3] = '0';
    blk[4][0] = '0';
    blk[4][1] = '0';
    blk[4][2] = '0';
    blk[4][3] = '0';
    
    int found = 0;
    int cur = 0;
    while (cur<=3)
    {
        *ip = 0; 
        blk[4][cur] = 'A';
        while (!found)
        {
            blk[3][cur] = 'A';
            while (!found&&blk[3][cur]<='z')
            {
                blk[2][cur] = 'A';
                while (!found&&blk[2][cur]<='z')
                {
                    blk[1][cur] = 'A';
                    while (!found&&blk[1][cur]<='z')
                    {
                        blk[0][cur] = 'A';
                        while (!found&&blk[0][cur]<='z')
                        {
                            int i = 0;
                            *ip=0;
                            for (i=0; i<5; i++)
                            {
                                *ip += *((unsigned int*)(blk[i]));
//                                printf("\t\t%x\n",  *((unsigned int*)(blk[i])));
                            }
                            printf("%8x\t[%2x][%2x][%2x][%2x][%2x]\n", *ip, (unsigned int)blk[4][cur],(unsigned int)blk[3][cur],(unsigned int)blk[2][cur],(unsigned int)blk[1][cur],(unsigned int)blk[0][cur]);
                            found = check_byte(res, cur); 
                            if (found==1)
                            {
                                answer[0][cur] = blk[0][cur];
                                answer[1][cur] = blk[1][cur];
                                answer[2][cur] = blk[2][cur];
                                answer[3][cur] = blk[3][cur];
                                answer[4][cur] = blk[4][cur];
/*                            printf("\t[%2x][%2x][%2x][%2x][%2x]\n", (unsigned int)blk[0][4],(unsigned int)blk[0][3],(unsigned int)blk[0][2],(unsigned int)blk[0][1],(unsigned int)blk[0][0]);
                            printf("\t[%2x][%2x][%2x][%2x][%2x]\n", (unsigned int)blk[1][4],(unsigned int)blk[1][3],(unsigned int)blk[1][2],(unsigned int)blk[1][1],(unsigned int)blk[1][0]);
                            printf("\t[%2x][%2x][%2x][%2x][%2x]\n", (unsigned int)blk[2][4],(unsigned int)blk[2][3],(unsigned int)blk[2][2],(unsigned int)blk[2][1],(unsigned int)blk[2][0]);
                            printf("\t[%2x][%2x][%2x][%2x][%2x]\n", (unsigned int)blk[3][4],(unsigned int)blk[3][3],(unsigned int)blk[3][2],(unsigned int)blk[3][1],(unsigned int)blk[3][0]);
                            printf("\t[%2x][%2x][%2x][%2x][%2x]\n", (unsigned int)blk[4][4],(unsigned int)blk[4][3],(unsigned int)blk[4][2],(unsigned int)blk[4][1],(unsigned int)blk[4][0]);
*/                                printf("\n\n");
                                cur++;
                            }
                            else
                            {
                                blk[0][cur]++;
                                if (blk[0][cur]=='9'+1)
                                {
                                    blk[0][cur] = 'A';
                                }
                                else if (blk[0][cur]=='Z'+1)
                                {
                                    blk[0][cur] = 'a';
                                }
                            }                      
                        }
                        if (found!=1)
                        {
                            blk[1][cur]++;
                            if (blk[1][cur]=='9'+1)
                            {
                                blk[1][cur] = 'A';
                            }
                            else if (blk[1][cur]=='Z'+1)
                            {
                                blk[1][cur] = 'a';
                            }                       
                            
                        }
                    }
                    if (found!=1)
                    {
                        blk[2][cur]++;
                        if (blk[2][cur]=='9'+1)
                        {
                            blk[2][cur] = 'A';
                        }
                        else if (blk[2][cur]=='Z'+1)
                        {
                            blk[2][cur] = 'a';
                        }                       
                    }
                }
                if (found!=1)
                {
                    blk[3][cur]++;
                    if (blk[3][cur]=='9'+1)
                    {
                        blk[3][cur] = 'A';
                    }
                    else if (blk[3][cur]=='Z'+1)
                    {
                        blk[3][cur] = 'a';
                    }                       
                }
            }
            if (found!=1)
            {
                blk[4][cur]++;
                if (blk[4][cur]=='9'+1)
                {
                    blk[4][cur] = 'A';
                }
                else if (blk[4][cur]=='Z'+1)
                {
                    blk[4][cur] = 'a';
                }                       
            }
        }
        found = 0;
    }
    printf("%s\n", (char*)(*answer));
    return 0;
}
