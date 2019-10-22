#include<stdio.h>
#include<stdlib.h>

void MergeAndSwap(int *p, int n, int startIndex, int dir);
void Divide(int *p, int n, int startIndex, int dir);
void BitonicSort(int *p, int n, int dir);

void Divide(int *p, int n, int startIndex, int dir)
{
  int x,i;
  if(n>1)
  {
    x = n/2;
    Divide(p, x, startIndex, 1);
    Divide(p, x, startIndex+x, 0);
    MergeAndSwap(p, n, startIndex, dir);
    for(i=0;i<n;i++)
      printf("%d ",p[i]);
    printf("\n");
  }
}

void MergeAndSwap(int *p, int n, int startIndex, int dir)
{
  int x,temp,i;
  if(n>1)
  {
    x = n/2;
    for(i=startIndex;i<(startIndex+x);i++)
    {
      if(dir == (p[i]>p[i+x]))
      {
        temp = p[i];
        p[i] = p[i+x];
        p[i+x] = temp;
      }
    }
    MergeAndSwap(p, x, startIndex, dir);
    MergeAndSwap(p, x, startIndex+x, dir);
  }
}

void BitonicSort(int *p, int n, int dir)
{
  Divide(p, n, 0, dir);
}


void main()
{
  int i,n;
  int *p;
  printf("Enter size of the array ");
  scanf("%d",&n);
  p = (int*)malloc(n*sizeof(int));

  printf("Enter the elements ");
  for(i=0;i<n;i++)
  {
    scanf("%d",&p[i]);
  }

  BitonicSort(p, n, 1);

  for(i=0;i<n;i++)
    printf("%d ",p[i]);
}
