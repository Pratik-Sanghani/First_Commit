#include <stdio.h>
#include<stdlib.h>
#include<limits.h>

int totalSplits = 0;

//Creating the file 
int createFile(){

	//Writing the data in file 
	FILE *filePointer ; 
	int i, num;
	
	filePointer = fopen("MainFile.txt", "w") ; 
	
	if ( filePointer == NULL ) 
	{ 
		return 0 ;
	} 
	else
	{ 
		
		for(i=100000;i>0;i--){
			fprintf(filePointer, "%d\n", rand());
		
		}
/*		fprintf(filePointer, "%d\n", EOF);*/
		fclose(filePointer) ; 
		
	}
	
	return 0;	

}
void partionLogic(int inputArray[], int left, int mid, int right ){


	int iIterator1, iTemp, jTemp, kTemp;
	int leftArraySize = mid - left + 1;
	int rightArraySize = right - mid;

	int leftArray[leftArraySize], rightArray[rightArraySize];

	//Data Copying to temp array
	for(iIterator1 = 0; iIterator1 < leftArraySize; iIterator1 ++){

		leftArray[iIterator1] = inputArray[left + iIterator1];
	}
	
	for(iIterator1 = 0; iIterator1 < rightArraySize; iIterator1++){
	
		rightArray[iIterator1] = inputArray[mid + 1 + iIterator1];
	
	}



	//Temp Arrays Sorting and combine to main Array
	iTemp = 0;
	jTemp = 0;
	kTemp = left;

	while(iTemp < leftArraySize && jTemp < rightArraySize){

		if(leftArray[iTemp] <= rightArray[jTemp]){
			
			inputArray[kTemp] = leftArray[iTemp];
			iTemp+=1;
		}else{

			inputArray[kTemp] = rightArray[jTemp];
			jTemp +=1;
		}
		kTemp+=1;

	}

	// if right array is bigger
	while(jTemp < rightArraySize){
		
		inputArray[kTemp] = rightArray[jTemp];
		jTemp++;
		kTemp++;
	} 

	//if left array is smaller 
	while(iTemp < leftArraySize){

		inputArray[kTemp] = leftArray[iTemp];
		iTemp++;
		kTemp++;
	}

}

void merge(int inputArray[], int left, int right){


	if(left < right){

		int mid = left + (right - left) / 2;

		merge(inputArray, left, mid); 
		merge(inputArray, mid+1, right);

		partionLogic(inputArray, left, mid, right);

	}
}

//Opening new Files to Store the Information
FILE *openforwrite(int filecounter) {
	
	totalSplits += 1;
	char fileoutputname[15];

	sprintf(fileoutputname, "file%d.txt",filecounter);
	return fopen(fileoutputname, "w");
}

int splitAndSort(){

	FILE *ptr_readfile;
	FILE *ptr_writefile;
	int inputArray[1000], filecounter= 0, iIterator1 = 0, iIterator2, lineCounter = 1; 


	ptr_readfile = fopen("MainFile.txt","r");
	if (!ptr_readfile)
		return 1;

	ptr_writefile = openforwrite(filecounter);

	while (fscanf(ptr_readfile, "%d" , &inputArray[iIterator1]) !=EOF) {
		//printf("%d\n", line);

		if (lineCounter > 1000) {

			merge(inputArray, 0, iIterator1);
			printf("%d\n",inputArray[iIterator1] );

			for(iIterator2=0; iIterator2< lineCounter; iIterator2++){

					fprintf(ptr_writefile, "%d\n", inputArray[iIterator2]);

			}
			
			iIterator1 = 0;
			lineCounter =1;
			fclose(ptr_writefile);
			filecounter++;
			ptr_writefile = openforwrite(filecounter);	
			if (!ptr_writefile)
			return 1;
		}
		iIterator1 +=1 ; 
		lineCounter++;
		//putw(line,ptr_writefile);
		//fprintf(ptr_writefile, "%d\n", line);

	}
	fclose(ptr_readfile);
	return 0;

}


int kWayMerge(){

	int splits = totalSplits-1;

	FILE* writeFilePointer ; 
	FILE* readFilePointer[splits];

	int arrayMin[splits];
	int min = 0, iIterator1, iIterator2, counter = 0;
	char fileName[15];


	
	writeFilePointer = fopen("SortedFile.txt", "w") ; 

	for(iIterator1 = 0; iIterator1 < splits; iIterator1 ++){

		sprintf(fileName, "file%d.txt",iIterator1);
		printf("%s\n",fileName );
		readFilePointer[iIterator1] = fopen(fileName, "r");
		if(!readFilePointer[iIterator1])
			break;
	}

	for(iIterator1 = 0; iIterator1 < splits; iIterator1 ++){

		fscanf(readFilePointer[iIterator1], "%d", &arrayMin[iIterator1]);

	}

	iIterator1 = 0;

	do{

		counter++;


		for(iIterator2 = 1; iIterator2 < splits; iIterator2++){
			

			if(arrayMin[iIterator2] < arrayMin[min]){
				min = iIterator2;
			}
		}



		fprintf(writeFilePointer, "%d\n", arrayMin[min] );

		if(fscanf(readFilePointer[min], "%d",&arrayMin[min]) != 1){


			arrayMin[min] = INT_MAX;
			iIterator1 +=1;
		}
	}while(iIterator1 != splits);


	fclose(writeFilePointer);
	for(iIterator1 = 0; iIterator1 < splits; iIterator1 ++){

			fclose(readFilePointer[iIterator1]);
	}

	

	printf("Counter :%d\n",counter );



	return 0;
}



void main(){

		createFile();
		splitAndSort();
		kWayMerge();

}