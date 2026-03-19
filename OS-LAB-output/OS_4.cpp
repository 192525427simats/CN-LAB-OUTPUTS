#include <stdio.h>

int main()
 {
    int n, bt[10], pr[10], wt[10], tat[10];

    printf("Enter no. of processes: ");
    scanf("%d", &n);

    for(int i=0;i<n;i++)
	 {
        printf("Burst time and Priority: ");
        scanf("%d %d", &bt[i], &pr[i]);
    }

    for(int i=0;i<n;i++) 
	{
        for(int j=i+1;j<n;j++) 
		{
            if(pr[i] > pr[j]) 
			{
                int t = bt[i]; bt[i] = bt[j]; bt[j] = t;
                t = pr[i]; pr[i] = pr[j]; pr[j] = t;
            }
        }
    }

    wt[0] = 0;
    for(int i=1;i<n;i++)
        wt[i] = wt[i-1] + bt[i-1];

    for(int i=0;i<n;i++)
        tat[i] = wt[i] + bt[i];

    printf("\nWT  TAT\n");
    for(int i=0;i<n;i++)
        printf("%d  %d\n", wt[i], tat[i]);

    return 0;
}
