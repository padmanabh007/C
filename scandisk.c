#include<stdio.h>
void main(){
    int ioq[20],i,n,j,ihead,tot,temp,scan;
    float seek=0,avgs=0;
    printf("Enter the number of requests\t");
    scanf("%d",&n);
    printf("Enter the intial head position\t");
    scanf("%d",&ihead);
    ioq[0]=ihead;
    ioq[1]=0;
    n+=2;
    printf("Enter the number I/O queue requests\n");
    for ( i = 2; i < n; i++)
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
    ioq[n]=ioq[n-1];
    for (i = 0; i < n; i++)
    {
        if (ihead==ioq[i])
        {
            scan=i;
            break;
        }
    }
    printf("\nOrder of request served\n");
    tot=0;
    for ( i =scan; i >=0; i--)
    {
        tot=ioq[i]-ioq[i-1];
        if (i==0)
        {
            tot=ioq[i]-ioq[scan+1];
        }
        if (tot<0)
        {
            tot=tot*-1;
        }
        printf("%d\t%d\n",ioq[i],tot);
    }
    for ( i = scan+1; i < n; i++)
    {
        tot=ioq[i+1]-ioq[i];
        if (tot<0)
        {
            tot=tot*-1;
        }
        printf("%d\t%d\n",ioq[i],tot);
    }
    seek=ihead+ioq[n-1];
    avgs=seek/(n-2);
    printf("\nTotal seek time\t:%2f",seek);
    printf("\nAverage seek time\t:%2f\n",avgs);
}
