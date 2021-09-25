#include<stdio.h>
int main(){
    int n,bt[20],art[20],temp,wt[20],tat[20],i,j,btime=0,min,k=1,p[10]={1,2,3,4,5,6,7,8,9,10},sum=0,ta=0;
    float avwt=0,avtat=0,tsum=0,wsum=0;
    printf("Enter the number of elements required to process (maximum[20]) = ");
    scanf("%d",&n);
    
    //Enter the burst time of the elements
    printf("Enter the burst time of each element in array\n");
    for ( i = 0; i < n ; i++){
        printf("P[%d] = ",i+1);
        scanf("%d",&bt[i]);
    }

    // Enter the arrival time 
    printf("Enter the arival time of the each element\n");
    for ( i = 0; i < n ; i++)
    {
        printf("P[%d] = ",i+1);
        scanf("%d",&art[i]);
    }

    //Sorting based on the arrival time
    for ( i = 0; i < n; i++)
    {
        for ( j = 0; j < n; j++)
        {
           if (art[i]<art[j])
           {
               temp = p[j];
               p[j] = p[i];
               p[i]=temp;
               temp = art[j];
               art[j] = art[i];
               art[i]=temp;
               temp = bt[j];
               bt[j] = bt[i];
               bt[i]=temp;
           }
           
        }
        
    }
    for ( i = 0; i < n; i++)
    {
        btime = btime+bt[j];
        min=bt[k];
        for ( j = k; j < n; j++)
        {
            if (btime>=art[i] && bt[i]<min)
            {
                temp = p[k];
                p[k] = p[i];
                p[i] = temp;
                temp = art[k];
                art[k] = art[i];
                art[i] = temp;
                temp = bt[k];
                bt[k] = bt[i];
                bt[i] = temp;
            }
            
        }
        k++;  
    }
    //waiting time 
    wt[0]=0;
    for ( i = 1; i < n; i++)
    {
       sum=sum+bt[i-1];
       wt[i]=sum-art[i];
       wsum=wsum+wt[i];
        
    }
    avwt=(wsum/n);
    //turn around time
    for ( i = 0; i < n; i++)
    {
        ta=ta+bt[i];
        tat[i]=ta-art[i];
        tsum=tsum+tat[i];
    }
    avtat=(tsum/n);
    //Printing
    printf("PID\t BurstTime\t Arrival Time\t WaitingTime\t TurnAroundTime\n ");
    for ( i = 0; i < n; i++)
    {
        printf("P[%d]\t\t %d\t\t %d\t\t %d\t\t %d\n ",p[i],bt[i],art[i],wt[i],tat[i]);   
    }   
    printf("\nAverege Waiting Time %d",avwt);
    printf("\nAverege Turn Around Time %d\n",avtat); 
}