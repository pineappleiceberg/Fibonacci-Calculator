//Copied from The Art of 64-bit Assembly by Randall Hyde
// https://www.randallhyde.com/#Main 

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



extern "C"
{
   
    
	
    void asmMain( void );

    
    char *getTitle( void );
    
    int readLine( char *dest, int maxLen );
    
};


int readLine( char *dest, int maxLen )
{

    char *result = fgets( dest, maxLen, stdin );
    if( result != NULL )
    {

        
        int len = strlen( result );
        if( len > 0 )
        {
            dest[ len - 1 ] = 0;
        }
        return len;
    } 
    return -1;
}

int main(void)
{
    
    
    try
    {
        char *title = getTitle();
            
        printf( "Calling %s:\n", title );
		clock_t start = clock();
        asmMain();
        clock_t end = clock();
		double elapsed_time = (end-start)/(double)CLOCKS_PER_SEC ;
		printf("\n asmMain took %f time to run\n", elapsed_time);
		printf( "%s terminated\n", title );
    }
    catch(...)
    {
        printf
        ( 
            "Exception occurred during program execution\n"
            "Abnormal program termination.\n"
        );
    }
    
}
