#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>
#include <sys/param.h>
#include <stdio.h>
#include "./checksum_ccitt.c"
#include "./checksum_crc16.c"
#include "./checksum_internet.c"
#define FRAMELEN 100
#define FRAMECOUNT 10
#define MIN_BURSTLEN            15
#define MAX_BURSTLEN            50
/*  This is a simple function designed to test checksum algorithms.
    The function randomly corrupts one or more bits of a given frame.

    As corruption is random, you'll need to call srand() from somewhere
    earlier in your program to ensure different random sequences.

    You may like to devise other forms of corruption and run tests on them.
 */

typedef unsigned char    BYTE;

void corrupt_frame(BYTE frame[], int length, int burstlen)
{
    int nbits           = (length * NBBY);
    int firstbit        = rand() % (nbits - burstlen);  // 1st bit of burst

    for(int b=0 ; b<burstlen ; ++b) {
        setbit(frame, firstbit+b);
    }
}

// int computeCheckSum(unsigned char frame)
// {
//     int sum = 0;
//     for (size_t i = 0; i < sizeof(frame); i++)
//     {
//         /* code */
//         sum +=i;
//     }
//     return sum;
    
// }
void testCRC(unsigned short (*function)(), char *name)
{
    unsigned char frame[FRAMELEN];
    // Check how many times CRC function fails to check for errors
    int failIter = 0, preCheck = 0, postCheck = 0;

    for (size_t i = 0; i < FRAMECOUNT; i++)
    {
        // Frame populator from lab sheet
        for (int j = 0; j < sizeof(frame); i++)
        {
            frame[j] = rand()%256;
        }
        // If checksum before and after are the same, then iterate
        preCheck = (*function)(frame, sizeof(frame));
        int burstlen    = MIN_BURSTLEN + rand() % (MAX_BURSTLEN - MIN_BURSTLEN);
        corrupt_frame(frame,FRAMELEN, burstlen);
        postCheck = (*function)(frame, sizeof(frame));
        if(preCheck == postCheck)
        {
            failIter++;
        }

    }
    printf("%s\t|\tfail count:\t %5i", name, failIter);

}

int main(int argc, char const *argv[])
{
    testCRC(checksum_ccitt,    "checksum_ccitt");

    testCRC(checksum_crc16,    "checksum_crc16");

    testCRC((unsigned short (*)())checksum_internet,   "checksum_internet");

    
    exit(EXIT_SUCCESS);
}

#if   OTHER_POSSIBLE_FORMS_OF_FRAME_CORRUPTION

//  corrupt one character by setting it to the complement of its own value
    int byte    = (rand() % length);
    frame[byte] = ~(frame[byte]) ;



//  corrupt one bit of a byte by toggling its value
    int byte    = (rand() % length);
    int bit     = (rand() % NBBY);
    frame[byte] = (frame[byte] ^ (1UL << bit));



//  corrupt a frame with a burst error
#define MIN_BURSTLENGTH         10
#define MAX_BURSTLENGTH         100
    int nbits           = (length * NBBY);
    while(true) {
        int     b0      = rand() % nbits;
        int     b1      = rand() % nbits;
	int	burst	= b1 - b0;

        if(burst >= MIN_BURSTLENGTH && burst <= MAX_BURSTLENGTH) {
            for(int b=b0 ; b<b1 ; ++b) {
                int     byte    = b / NBBY;
                int     bit     = b % NBBY;

                frame[byte]     = (frame[byte] | (1UL << bit));
            }
            break;
        }
    }

#endif
