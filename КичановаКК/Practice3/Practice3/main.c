#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 6
int main()
{
    int n, i, j, num[N], guess[N], cows = 0, bulls = 0;
    do {
        printf("Input number length from 2 to 5: ");
        scanf("%d", &n);
    } while ((n < 2) || (n > 5));
    srand((unsigned int)time(0));
    for (i = 0; i < n; i++)
    {
        while (1)
        {
            int digit = rand() % 10;

            int one = 1;
            for (j = 0; j < n; j++)
                if (num[j] == digit) one = 0;

            if (one)
            {
                num[i] = digit;
                break;
            }
        }
    }
    do {
        cows = 0; bulls = 0;
        printf("Input your guess:\n");
        for (i = 0;  i < n; i++) 
        {
            printf("%d -", i+1);
            scanf("%d", &guess[i]);
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (num[i] == guess[j]){
                    if (i == j) bulls++;
                    else if (i != j) cows++;
                }
            }
        }
        printf("cows: %d bulls: %d\n", cows, bulls);
    } while (bulls != n);
    printf("You win! Number was:");
    for (i = 0; i < n; i++)
    {
        printf("%d", num[i]);
    }
    return 0;
}
    