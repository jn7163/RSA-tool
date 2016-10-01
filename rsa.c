#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int start();
int f(int m,int n);

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
  n=p*q;
  l=(p-1)*(q-1)/f(p-1,q-1);
  srand((unsigned)time(NULL));
  while (1)
  {
    temp=rand()%(l-3);
    if (f(l,temp)==1) {e=temp;break;}
  }
  srand((unsigned)time(NULL));
  while (1)
  {
    temp=rand()%(l-3);
    if ((temp*e%l==1)&&(temp!=e)) {d=temp;break;}
  }
  printf("(E,N)=(%d,%d)\n",e,n);
  printf("(D,N)=(%d,%d)\n",d,n);
  return 0;
}

int main()
{
  start();
  return 0;
}