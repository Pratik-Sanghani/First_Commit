#include<stdio.h>
#include<stdlib.h>

int count=0;
int *p;
int PowerFunc(int n,int x);

void main()
{
  int n,x,i,ans;
  printf("Enter power: ");
  scanf("%d",&n);
  printf("Enter base");
  scanf("%d",&x);
  p = (int*)malloc(n*sizeof(int));
  for(i=0;i<n;i++)
    p[i]=-1;
  ans = PowerFunc(n,x);
  printf("\n%d^%d=%d and number of calculations required=%d",x,n,ans,count);
}

int PowerFunc(int n, int x)
{
  int temp;
  if(n==1)
  {
    p[n]=x;
    return p[n];
  }
  else if(n%2==0)
  {
    if(p[n]!=-1)
      return p[n];
    else
    {
      temp = PowerFunc(n/2,x);
      count++;
      p[n] = temp*temp;
      return p[n];
    }
  }
  else
  {
    if(p[n]!=-1)
      return p[n];
    else
    {
      temp = PowerFunc((n-1)/2,x);
      count++;
      p[n] = p[1]*temp*temp;
      return p[n];
    }
  }
}
