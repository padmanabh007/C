#include<stdio.h>
void main(){
    int ioq[20],i,n,j,ihead,itail,tot,temp,scan;
    float seek=0,avgs=0;
    printf("Enter the number of requests\t");
    scanf("%d",&n);
    ioq[0]=0;
    printf("Enter the intial head position\t");
    scanf("%d",&ihead);
    ioq[1]=ihead;
    printf("Enter the maximum track limit\t");
    scanf("%d",&itail);
    ioq[2]=itail;
    n+=3;
    printf("Enter the number I/O queue requests\n");
    for ( i = 3; i <n; i++)
    {
        scanf("%d",&ioq[i]);
    }
    for ( i = 0; i < n-1; i++)
    {
        for ( j = 0; j < n-1; i++)
        {
            if (ioq[j]>ioq[j+1])
            {
                temp=ioq[j];
                ioq[j]=ioq[j+1];
                ioq[j+1]=temp;
            }   
        }
    }
    for (i = 0; i < n; i++)
    {
        if (ihead==ioq[i])
        {
            scan=i;
            break;
        }
    }
    i=scan;
    temp=n;
    printf("\nOrder of request served\n");
    while (i!=temp)
    {
        if(i<temp-1){
            tot=ioq[i+1]-ioq[i];
            if (tot<0)
            {
                tot=tot*-1;
            }
            seek+=tot;
        }
        printf("%d-->",ioq[i]);
        i++;
        if (i==n)
        {
            i=0;
            temp=scan;
            seek+=itail;
        }   
    }    
    avgs=seek/(n-3);
    printf("\nTotal seek time\t:%2f",seek);
    printf("\nAverage seek time\t:%2f\n",avgs);
}