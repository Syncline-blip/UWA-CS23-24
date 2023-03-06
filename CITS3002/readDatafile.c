
#include <stdio.h>
#include <stdlib.h> // For exit()
  
int main()
{
    FILE *fptr;
  
    char c;
  

    // Open file
    fptr = fopen("Q1.datafile", "rb");
    if (fptr == NULL)
    {
        printf("Cannot open file \n");
        exit(0);
    }
  
    // Read contents from file
    c = fgetc(fptr);
    while (c != EOF)
    {
        printf ("%c", c);
        c = fgetc(fptr);
    }
  
    fclose(fptr);
    return 0;
}