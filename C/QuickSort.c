#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int partition(int *, int, int);

int partition(int *a, int low, int high)
{
int pivot, j, i, temp;
pivot = a[high];
i = (low-1);
for(j=low;j<=high-1;j++)
{
	if(a[j]<=pivot)
	{
		i++;
		temp = a[j];
		a[j] = a[i];
		a[i] = temp;
	}
}
temp = a[i+1];
a[i+1] = a[high];
a[high] = temp;
return(i+1);
}

void quicks(int *a, int low, int high)
{
int ptn;
if(low < high)
{
	ptn = partition(a, low, high);
	quicks(a, low, ptn-1);
	quicks(a, ptn+1, high);
}
}
void main()
{
int *ptr;
int j,k,n;
clock_t start,end;
double clock_time;
printf("Enter the size of an array ");
scanf("%d",&n);
ptr = (int*)malloc(n*sizeof(int));

//Ascending order
for(j=0;j<n;j++)
	ptr[j] = j;

printf("\n");
start = clock();
quicks(ptr, 0, n-1);
end = clock();
clock_time = ((double)(end-start))/CLOCKS_PER_SEC;
printf("Time required is %lf\n",clock_time);

//Descending order
for(j=n-1,k=0;j>=0;j--,k++)
	ptr[j] = k;

start = clock();
quicks(ptr, 0, n-1);
end = clock();
clock_time = ((double)(end-start))/CLOCKS_PER_SEC;
printf("Time required is %lf\n",clock_time);

//Random order
for(j=0;j<n;j++)
	ptr[j] = rand()%1000+1;

start = clock();
quicks(ptr, 0, n-1);
end = clock();
clock_time = ((double)(end-start))/CLOCKS_PER_SEC;
printf("Time required is %lf\n",clock_time);
}
