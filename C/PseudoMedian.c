#include<stdio.h>
#include<stdlib.h>

void PseudoMedian(int *a, int n)
{
	 int i,j,k,l,temp,temp1,min,x;
	 for(j=0;j<n/5;j++)
	 {
	 	i=j*5;
	 	for(k=i;k<i+3;k++)
	 	{
	 		min = k;
	 		for(l=k+1;l<i+5;l++)
	 		{
	 			if(a[min]>a[l])
	 			min=l;
	 		}
	 		temp = a[k];
	 		a[k] = a[min];
	 		a[min] = temp;
	 	}
	 	temp = a[j];
	 	a[j] = a[i+2];
	 	a[i+2] = temp;
	 }
	 for(i=0;i<n;i++)
	 	printf("%d ",a[i]);

	 printf("\nvalueofn %d\n",n);
	 x = n/5;
	 if(x>0)
	 	PseudoMedian(a,x);
	else
	 {
	 	temp1 = n%5;
	 	for(i=0;i<temp1;i++)
	 	{
	 		min = i;
	 		for(j=i+1;j<temp1;j++)
	 		{
	 			if(a[min]>a[j])
	 			min = j;
	 		}
	 		temp = a[i];
	 		a[i] = a[min];
	 		a[min] = temp;
	 	}
	 	printf("\ntemp1 = %d\n",temp1);
	 	for(i=0;i<n;i++)
	 	printf("%d ",a[i]);
	 	temp = temp1/2;
	 	printf("\nPseudo Median is %d\n",a[temp]);
	 }
}

void main()
{
	int i,n, *p;
	printf("Enter n");
	scanf("%d",&n);
	p = (int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		p[i] = rand()%100+1;

	for(i=0;i<n;i++)
	 	printf("%d ",p[i]);
	printf("\n");

	PseudoMedian(p, n);
}
