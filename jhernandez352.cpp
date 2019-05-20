#include <iostream>
using namespace std;

//Referenced sudo code in the text book pg. 31 and 34. Or at least I tried following but slight modifications had to be made.
//Print function for printing arrays. Simple for loop.
void print(int *output, int size){
	for(int i = 0; i < size; i++){
		cout << output[i] <<";";
	}
}
//Merge function.
void merge(int *data, int start, int mid, int size)
{
	//Decrlare the sizes of the two temporary arrays.
	int left = mid - start + 1;
	int right =  size - mid;
	//Initialize arrays.
   	int *leftArr = new int[left];
	int *rightArr = new int[right];
    //Split data array in two and copy over each half into corresponding array.

    for (int i = 0; i < left; i++){
        leftArr[i] = data[start + i];
	}
	//print(leftArr, left);
    for (int j = 0; j < right; j++){
        rightArr[j] = data[mid  + j + 1];
	}
	//print(rightArr, right);
	//We need new counters for merging process.
    int i, j = 0;
	//This keeps track of what index we need to continue off of since some numbers left over from certain arrays have been left unsorted.
	int tempCounter = start;
	//This loop by itself did not work correctly so I needed to implement clean up loops what would account for "unaccounted" integers.
	//NEEDS FIX****
	for(int k = start; k < size; k++){
		//cout << "merging..." << endl;
		//Once we reach the end of one of these arrays, we need to stop making comparisons or we will reach indexes out of scope.
		if(i < left && j < right ){	
			if (leftArr[i] <= rightArr[j])
			{
				data[k] = leftArr[i];
				i++;
			}
			else
			{
				data[k] = rightArr[j];
				j++;
			}
		tempCounter++;
		}
	}
	//print(data, tempCounter);
	//For loop clean up... accounts for all the numbers that cannot be compared due to different array sizes. Some numbers did not have a specific number to be compared to.
	for(int m = i; m  < left;m++v,tempCounter++){
		data[tempCounter] = leftArr[m];
	}
	for(int n = j; n < right; n++, tempCounter++){
		data[tempCounter] = rightArr[n];
	}
	//Delte arryas from memory.	
	delete[] leftArr, rightArr;
	
}
//Recursice mergeSort algorithm from pg. 34 of textbook.
void mergeSort(int *data,int start, int size)
{
    if (start < size)
    {
		//The mid values have to change. After 
        int mid = start + (size - start)/2;
		mergeSort(data, start, mid);
		//mergeSort right array.
        mergeSort(data, mid + 1, size);
		//merge two arrays
        merge(data, start, mid, size);
	}
}

int main(int argc, char **argv){
	//initialize variables.
	int size;
	cin >> size;
	int *data = new int[size];
	for(int i = 0; i < size; i++){
		cin >> data[i];
	}
	//MergeSort the data.
	mergeSort(data, 0, size-1);
	//Print the data;
	print(data, size);
	//delete the array from memory.
	delete[] data;
	
	return 0;
}