#include<stdio.h>
#include<stdlib.h>
#include <math.h>

#define MAX 1000000
#define mod 1000000007
long long f[ MAX ] , f1[ MAX ] ;
/* f is an array for number of ways the current step can be reached using steps of 2 and 5
f1 is an array for number of ways the current step can be reached using steps of 2, 5 and k*/

int main( ) {
	// t is the number of test cases and n is the total number of steps
	long n , t ;
	int cur , k ;
	int i;

	printf("Enter number of test cases followed by total number of steps..\n ");
	scanf("%d %d", &t, &n);
	f[0] = 0 ; f[1] = 0 ; f[2] = 1 ; f[3] = 0 ; f[4] = 1 ; f[5] = 1 ; // Assigning number of ways in which the first 5 steps can be reached
	for( i = 6 ; i <= n; i++ )
		f[i] = (f[i-2] + f[i-5])%mod ; // Calculating number of ways different steps can be reached


    while( t-- )
	{
		 //cur is the current step and k is the kth step
		 printf("\nEnter step number Harit wants to reach followed by the number of steps he wants to skip..\n ");
		scanf("%d %d", &cur, &k);

        if( (cur < k) || ( k == 2 ) || ( k == 5 ))  // If value of current step is less than k value
        	printf("\n Number of ways he can reach desired step = %d\n", f[cur]);

        else if( cur == k )  // If value of k and current step is equal
        	printf("\n Number of ways he can reach desired step = %d\n", (f[cur]+1)%mod);

        else // Otherwise (value of current step is greater than k value)
		{
            for(i = 0 ; i <= k ; i++ )
				f1[i] = f[i] ;
            f1[k] = (f1[k]+1)%mod;

            for(i = k+1 ; i <= cur ; i++ )
				f1[i] = (f1[i-2] + f1[i-5] + f1[i-k])%mod ;

            printf("\n Number of ways he can reach desired step = %d\n", f1[cur]);
            printf("\n");
        }

    }
	return 0 ;
}
