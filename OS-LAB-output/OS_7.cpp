#include <stdio.h>

int main()
 {
    int n, tq, bt[10], rt[10], wt[10], tat[10];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(int i=0;i<n;i++) 
	{
        printf("Burst time: ");
        scanf("%d", &bt[i]);
        rt[i] = bt[i];
    }

    printf("Enter time quantum: ");
    scanf("%d", &tq);

    int time = 0, done;
    do {
        done = 1;
        for(int i=0;i<n;i++)
		 {
            if(rt[i] > 0) 
			{
                done = 0;
                if(rt[i] > tq)
				 {
                    time += tq;
                    rt[i] -= tq;
                } else {
                    time += rt[i];
                    wt[i] = time - bt[i];
                    rt[i] = 0;
                }
            }
        }
    } while(!done);

    for(int i=0;i<n;i++)
        tat[i] = wt[i] + bt[i];

    printf("\nWT\tTAT\n");
    for(int i=0;i<n;i++)
        printf("%d\t%d\n", wt[i], tat[i]);

    return 0;
}
