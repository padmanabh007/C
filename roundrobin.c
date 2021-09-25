#include<stdio.h>
int main(){
    
    int n,x,i,bt[20],art[20],total=0,tart=0,watat=0,time_quantnum=0,temp[20],counter=0;
    float avwat=0,avtat=0;

    printf("Enter the total numebr of process required (maximum(20)) = ");
    scanf("%d",&n);
    x=n;
    printf("Enter the process Burst time and the arrival time\n");
    for ( i = 0; i < n; i++)
    {
        printf("P[%d] = ",i+1);
        scanf("%d",&bt[i]);
        printf("Arrival Time : ");
        scanf("%d",&art[i]);
        temp[i]=bt[i];
    }

    printf("Enter the Quantum Time = ");
    scanf("%d",&time_quantnum);

    printf("\nProcesss ID\t BurstTime\t TurnaroundTime\t Waiting Time\n");
    for ( total = 0, i =0; x!=0;)
    {
        if (temp[i]<=time_quantnum && temp[i]>0)
        {
            total=total+temp[i];
            temp[i]=0;
            counter=1;
        }
        else if(temp[i]>0)
        {
            temp[i]=temp[i]-time_quantnum;
            total= total+time_quantnum;
        }
        if (temp[i]==0 && counter == 1)
        {
            x--;
            printf("\nProces[%d]\t\t %d\t\t %d\t\t %d\n",i+1,bt[i],total- art[i],total-art[i]-bt[i]);
            watat=watat+total-art[i]-bt[i];
            tart=tart+total-art[i];
            counter=0;
        }
        if (i==n-1)
        {
            i=0;
        }
        else if (art[i+1]<=total)
        {
            i++;
        }
        else
        {
            i=0;
        }    
    }
    avwat=(watat*0.1)/n;
    avtat=(tart*0.1)/n;
    printf("Average Waiting Time = %d\n",avwat);
    printf("Average TurnaroundTime = %d\n",avtat);
}