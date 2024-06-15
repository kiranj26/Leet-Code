#include <stdio.h>

int findChildWithBall(int n, int k);

int main() {
    int n, k;
    
    // Example 1
    n = 3;
    k = 5;
    printf("Output for n = %d, k = %d: %d\n", n, k, findChildWithBall(n, k));
    
    // Example 2
    n = 5;
    k = 6;
    printf("Output for n = %d, k = %d: %d\n", n, k, findChildWithBall(n, k));
    
    // Example 3
    n = 4;
    k = 2;
    printf("Output for n = %d, k = %d: %d\n", n, k, findChildWithBall(n, k));
    
    return 0;
}

int findChildWithBall(int n, int k) {

    int direction = 1;
    int position = 0;

    for (int i = 0; i< k; i++)
    {
        position = position + direction;

        if (position == (n-1) || position == 0)
        {
            direction =  - direction;
        }
    }

    return position;
}
