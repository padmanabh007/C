#include<stdio.h>
int main(){

    int n ,bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j;
    printf("Enter the number of elements required to process (maximum 20)= ");
    scanf("%d",&n);
    printf("Enter the burst time of elements to the array \n");
    for ( i = 0; i < n; i++)
    {
        printf("P[%d] = ",i+1);
        scanf("%d",&bt[i]);
    }

    //For entering the waiting time
    wt[0]=0;
    for (i = 1; i < n; i++)
    {
        wt[i]=0;
        for ( j = 0; j < i; j++)
        {
           wt[i] =wt[i] + bt[j];
        }
        
    }
    
    printf("Process\t Burst Time\t WaitingTime\t TurnaroudTime");
    for ( i = 0; i < n; i++)
    {
        tat[i]=bt[i]+wt[i];
        avwt = avwt+wt[i];
        avtat = avtat + tat[i];
        printf("\n P[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
    }
    
    avwt = avwt/n;
    avtat = avtat/n;
    printf("\nAverege Waiting Time %d",avwt);
    printf("\nAverege Turn Around Time %d\n",avtat);
}

