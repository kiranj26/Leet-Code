#include <stdio.h>
#include <stdlib.h>

int main(void) {
	// your code goes here
	int T;
	scanf("%d", &T);
	
	while(T--)
	{
	    int N,X;
	    scanf("%d %d", &N, &X);
	    
	    // array A`
	    int * arrayA = (int *)malloc(sizeof(int) * N);
	    for(int i=0;i<N;i++)
	    {
	        scanf("%d", &arrayA[i]);
	    }
	    // array B
	    int * arrayB = (int *) malloc(sizeof(int) * N);
	    for(int i=0;i<N;i++)
	    {
	        scanf("%d", &arrayB[i]);
	    }
	    int total_cost = 0;
	    // calculate total const
	    // traverse arrayA
	    for(int i=0;i<N;i++)
	    {
	        if (arrayA[i] > X)
	        {
	            total_cost = total_cost + arrayB[i];
	        }
	    }
	    printf("%d", total_cost);
	    
	}
	return 0;
}

