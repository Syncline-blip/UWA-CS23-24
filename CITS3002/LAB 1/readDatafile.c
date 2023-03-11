
#include <stdio.h>
#include <stdlib.h> // For exit()
#include <fcntl.h>
int main()
{
    // Simple function to read Q1.DataFile
    uint32_t op;
    FILE *ptr;
    ptr = fopen("Q1.datafile","rb+");  // r for read, b for binary
    for(int32_t a = -50; a<=50; ++a)
    {   
        fread(&op,sizeof(op),1,ptr); // read 10 bytes to our buffer
        printf("%4i\t0x%08x\t%10i\t0x%08x\n", a, a, op,op);
    }
    
    
}