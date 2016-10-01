#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int start();
int f(int m,int n);
int prime(int n);

int prime(int n)
{
  int i=0;
  for (i=2;i*i<=n;i++)
    if (n%i==0) return 0;
  return 1;
}
int f(int m,int n)
{
  int c=0;
  c=m%n;
  while (c!=0)
  {
    m=n;n=c;c=m%n;
  }
  return(n);
}
int start()
{
  int temp=0,p=0,q=0,n=0,l=0,e=0,d=0;
  printf("RSA tool\n");
  printf("please input two prime number:");
  scanf("%d %d",&p,&q);
  if ((prime(p)!=1)||(prime(q)!=1)) {printf("number(s) is(are) not the prime number!\n");exit(0);}
  n=p*q;
  l=(p-1)*(q-1)/f(p-1,q-1);
  srand((unsigned)time(NULL));
  while (1)
  {  
    temp=(rand()%(l-4))+2;
    if (f(l,temp)==1) {e=temp;break;}
  }
  printf("(E,N)=(%d,%d)\n",e,n);
  while (1)
  {
    srand((unsigned)time(NULL));
    temp=(rand()%(l-4))+2;
    if (((temp*e)%l==1)&&(temp!=e)) {d=temp;break;}  
  }

  printf("(D,N)=(%d,%d)\n",d,n);
  return 0;
}

int main()
{
  start();
  return 0;
}
