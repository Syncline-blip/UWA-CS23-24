
#include <stdio.h>
#include <stdlib.h> // For exit()
  
int main()
{
   unsigned char buffer[1024];
    FILE *ptr;

    ptr = fopen("Q1.datafile","rb");  // r for read, b for binary
    fread(buffer,sizeof(buffer),1,ptr); // read 10 bytes to our buffer
    for(int i = -50; i<50; i++)
    printf("%i\n", buffer[i]); // prints a series of bytes
}