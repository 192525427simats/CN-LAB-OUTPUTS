#include <stdio.h>

int main() 
{
    int n, bt[10], pr[10], rt[10];
    int wt[10] = {0}, tat[10];
    int time = 0, completed = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
	 {
        printf("Enter burst time and priority for P%d: ", i+1);
        scanf("%d %d", &bt[i], &pr[i]);
        rt[i] = bt[i];
    }

    while(completed != n) 
	{
        int highest = -1;

        for(int i = 0; i < n; i++) 
		{
            if(rt[i] > 0) {
                if(highest == -1 || pr[i] < pr[highest]) 
				{
                    highest = i;
                }
            }
        }

        rt[highest]--;
        time++;

        if(rt[highest] == 0) 
		{
            completed++;
            wt[highest] = time - bt[highest];
        }
    }

    for(int i = 0; i < n; i++)
	 {
        tat[i] = wt[i] + bt[i];
    }

    printf("\nProcess WT TAT\n");
    for(int i = 0; i < n; i++) {
        printf("P%d %d %d\n", i+1, wt[i], tat[i]);
    }

    return 0;
}
