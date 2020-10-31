#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 100000

void main()
{
  int a[SIZE],b[SIZE],c[SIZE];
  char arr[]={'R','A','D'};
  int i,j,temp,key;
  clock_t start_1, end_1,start_2, end_2,start_3, end_3;
  double cpu_time_used_1,cpu_time_used_2,cpu_time_used_3;

  for(i=0;i<SIZE;i++)
  {
    a[i]=rand()%SIZE;
  }

  for(i=0;i<SIZE;i++)
  {
    b[i]=i;
  }

  for(i=0,j=SIZE;i<SIZE,j>0;i++,j--)
  {
    c[i]=j;
  }


  /*for ( i = 0; i < SIZE; i++)
  {
    printf("%d\t",a[i]);
  }*/

  printf("\n\n");

  start_1 = clock();
 
  for (i = 0; i < SIZE; i++)
  {
    key=a[i];
    j=i-1;

    while (j>=0 && a[j]>key)
    {
      a[j+1]=a[j];
      j=j-1;
    }
    a[j+1]=key;
       
  }
  end_1 = clock();
  cpu_time_used_1 = ((double) (end_1 - start_1)) / CLOCKS_PER_SEC;
  printf("For Random values the algorithm took %f seconds to execute.", cpu_time_used_1); 

  printf("\n\n");

  start_2 = clock();
 
  for (i = 0; i < SIZE; i++)
  {
    key=b[i];
    j=i-1;

    while (j>=0 && b[j]>key)
    {
      b[j+1]=b[j];
      j=j-1;
    }
    b[j+1]=key;
       
  }
  end_2 = clock();
  cpu_time_used_2 = ((double) (end_2 - start_2)) / CLOCKS_PER_SEC;
  printf("For Aecending values the algorithm took %f seconds to execute.", cpu_time_used_2); 

  printf("\n\n");

  start_3 = clock();
 
  for (i = 0; i < SIZE; i++)
  {
    key=c[i];
    j=i-1;

    while (j>=0 && c[j]>key)
    {
      c[j+1]=c[j];
      j=j-1;
    }
    c[j+1]=key;
       
  }
  end_3 = clock();
  cpu_time_used_3 = ((double) (end_3 - start_3)) / CLOCKS_PER_SEC;
  printf("For Decending values the algorithm took %f seconds to execute.", cpu_time_used_3); 

  double g1[]={cpu_time_used_1,cpu_time_used_2,cpu_time_used_3};

  FILE *myfile= fopen ("Insertion_Graph.csv","w");

  for (int i=0; i<3; i++)
    fprintf(myfile, "%c,%f\n",arr[i],g1[i]);    

  fclose(myfile);


  /* for ( i = 0; i < SIZE; i++)
  {
    printf("%d\t",a[i]);
  }*/
    
}