#include <stdio.h>

int main() 
{
    int n, bt[10], wt[10], tat[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i=0;i<n;i++) 
	{
        printf("Enter burst time: ");
        scanf("%d", &bt[i]);
    }

    wt[0] = 0;
    for(int i=1;i<n;i++)
        wt[i] = wt[i-1] + bt[i-1];

    for(int i=0;i<n;i++)
        tat[i] = wt[i] + bt[i];

    printf("\n Process   WT   TAT \n");
    for(int i=0;i<n;i++)
        printf("%d %d  %d\n", i+1, wt[i], tat[i]);

    return 0;
}
