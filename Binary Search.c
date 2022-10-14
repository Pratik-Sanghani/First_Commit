#include <stdio.h>
int main(void){
	int a[100],n,search,i,l,h,m;
	printf("Enter the number of elements\n");
	scanf("%d",&n);
	l=0;
	h=n-1;
	m=(l+h)/2;
	printf("Enter the numbers:\n");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("Enter the search number:\n");
	scanf("%d",&search);
	while(l<=h){
		if(a[m]==search){
		printf("element found at index %d:\n",m+1);
		break;
		}		
		else if(search>a[m]){
			l=m+1;
		}
		else{
		h=m-1;
		}
		m=(l+h)/2;
	}
	if(l>h)
	printf("search element is not found");
	return 0;
}