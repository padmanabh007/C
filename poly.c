#include<stdio.h>
#include<malloc.h>
struct Node
{ int expp;
  int c;
  struct Node *link;
}*rh,*ph,*qh,*pptr,*rptr,*qptr,*nptr;
typedef struct Node node;
int main()
{  
int i,p,q,cf,exp,f=0;
ph=(node*)malloc(sizeof(node));
qh=(node*)malloc(sizeof(node));
ph->link=NULL;
qh->link=NULL;
pptr=ph;
qptr=qh;
printf("\nENter the number of terms in P : ");
scanf("%d",&p);
printf("\nEnter the polynomial : ");
for(i=0;i<p;i++)
{nptr=(node*)malloc(sizeof(node));
printf("\nEnter the %d the exp : ",i+1);
scanf("%d",&exp);
nptr->expp=exp;
printf("\nEnter the %d the coeff : ",i+1);
scanf("%d",&cf);
nptr->c=cf;
nptr->link=NULL;
pptr->link=nptr;
pptr=nptr;}
pptr=ph->link;
printf("\nPolynomial P: ");
do
{printf("%dx^%d",(pptr->c),(pptr->expp));
if(pptr->link!=NULL)
printf("+");
pptr=pptr->link;}while(pptr!=NULL);
printf("\nEnter the number of terms in Q : ");
scanf("%d",&q);
printf("\nEnter the polynomial Q");
for(i=0;i<q;i++)
{nptr=(node*)malloc(sizeof(node));
printf("\nENter the %d exp : ",i+1);
scanf("%d",&exp);
nptr->expp=exp;
printf("\nEnter the %d coeff : ",i+1);
scanf("%d",&cf);
nptr->c=cf;
nptr->link=NULL;
qptr->link=nptr;
qptr=nptr;}
qptr=qh->link;
printf("\nPolynomial Q : ");
do
{printf("%dx^%d",(qptr->c),(qptr->expp));
if(qptr->link!=NULL)
printf("+");
qptr=qptr->link;
}while(qptr!=NULL);
rh=(node*)malloc(sizeof(node));
rh->link=NULL;
rptr=rh;
pptr=ph->link;
qptr=qh->link;
while(pptr!=NULL&&qptr!=NULL)
{if(pptr->expp==qptr->expp)
{nptr=(node*)malloc(sizeof(node));
rptr->link=nptr;
rptr=nptr;
rptr->c=(pptr->c)+(qptr->c);
rptr->expp=pptr->expp;
rptr->link=NULL;
pptr=pptr->link;
qptr=qptr->link;}
else if(pptr->expp>qptr->expp)
{nptr=(node*)malloc(sizeof(node));
rptr->link=nptr;
rptr=nptr;
rptr->c=pptr->c;
rptr->expp=pptr->expp;
pptr=pptr->link;}
else if(pptr->expp<qptr->expp)
{nptr=(node*)malloc(sizeof(node));
rptr->link=nptr;
rptr=nptr;
rptr->c=qptr->c;
rptr->expp=qptr->expp;
qptr=qptr->link;}}
if(pptr!=NULL&&qptr==NULL)
{nptr=(node*)malloc(sizeof(node));
rptr->link=nptr;
rptr=nptr;
rptr->c=pptr->c;
rptr->expp=pptr->expp;
pptr=pptr->link;}
if(pptr==NULL&&qptr!=NULL)
{nptr=(node*)malloc(sizeof(node));
rptr->link=nptr;
rptr=nptr;
rptr->c=qptr->c;
rptr->expp=qptr->expp;
qptr=qptr->link;}
rptr=rh->link;
printf("\nSum of polynomial : ");
do
{printf("%dx^%d",(rptr->c),(rptr->expp));
if(rptr->link!=NULL)
printf("+");
rptr=rptr->link;
}while(rptr!=NULL);
rptr=rh;
pptr=ph;
while(pptr->link!=NULL)
{qptr=qh->link;
pptr=pptr->link;
while(qptr!=NULL)
{exp=(pptr->expp)+(qptr->expp);
cf=(pptr->c)*(qptr->c);
if(rptr->link==NULL)
{nptr=(node*)malloc(sizeof(node));
nptr=(node*)malloc(sizeof(node));
nptr->c=cf;
nptr->expp=exp;
rptr->link=nptr;
nptr->link=NULL;
qptr=qptr->link;
rptr=rh;}
else
rptr=rptr->link;
if(rptr->expp=exp)
{rptr->c=rptr->c+cf;
qptr=qptr->link;
rptr=rh;}}}
rh->link=NULL;
rptr=rh;
pptr=ph;
while(pptr->link!=NULL)
{qptr=qh->link;
pptr=pptr->link;
while(qptr!=NULL)
{exp=(pptr->expp)+(qptr->expp);
cf=(pptr->c)*(qptr->c);
if(rptr->link=NULL)
{nptr=(node*)malloc(sizeof(node));
nptr->c=cf;
nptr->expp=exp;
rptr->link=NULL;
qptr=qptr->link;
rptr=rh;}
else
rptr=rptr->link;
if(rptr->expp==exp)
{rptr->c=rptr->c+cf;
qptr=qptr->link;
rptr=rh;}}}
rptr=rh->link;
printf("\nPolynomial Mult : ");
do
{printf("%dx^%d",(rptr->c),(rptr->expp));
if(rptr->link!=NULL)
printf("+");
rptr=rptr->link;
}while(rptr!=NULL);
}
