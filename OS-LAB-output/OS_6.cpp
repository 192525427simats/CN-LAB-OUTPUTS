#include <stdio.h>

int main() 
{
    int n, bt[10], wt[10], tat[10], p[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) 
	{
        printf("Enter burst time for P%d: ", i+1);
        scanf("%d", &bt[i]);
        p[i] = i+1;
    }

    // Sorting by burst time
    for(int i = 0; i < n; i++) 
	{
        for(int j = i+1; j < n; j++) 
		{
            if(bt[i] > bt[j]) {
                int temp = bt[i];
                bt[i] = bt[j];
                bt[j] = temp;

                temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    wt[0] = 0;

    for(int i = 1; i < n; i++)
	 {
    	
        wt[i] = wt[i-1] + bt[i-1];
    }

    for(int i = 0; i < n; i++) 
	{
        tat[i] = wt[i] + bt[i];
    }

    printf("\nProcess\tBT\tWT\tTAT\n");
    for(int i = 0; i < n; i++)
	 {
        printf("P%d\t%d\t%d\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }

    return 0;
}
