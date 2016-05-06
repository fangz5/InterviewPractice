#include <cstdint>
#include <iostream>

using namespace std;

/*
Move array B into A, assuming A is large enough.
1) Determine the size of combined array;
2) Fill the combined array (A) from the end;
3) Stop when all values in B are filled. 	
4) Assuming A and B are sorted increasingly.
*/
void MergeInPlace(int32_t A[], int32_t sizeA, int32_t B[], int32_t sizeB){
	int32_t endAB = sizeA + sizeB - 1;	//End index of the merged array.
	sizeA--;
	sizeB--;	//From now on, sizeA and sizeB correspond to the end index of the two arrays.
	while (sizeB >= 0) {	
		if (sizeA >= 0) {
			if (A[sizeA] <= B[sizeB]) {
				A[endAB] = B[sizeB];
				sizeB--;
			}else{
				A[endAB] = A[sizeA];
				sizeA--;
			}
		}else{
			A[endAB] = B[sizeB];
			sizeB--;
		}
		endAB--;
	}		
}

int main(){
	int32_t A[100];
	for (int i = 0; i < 10; i++) {
		A[i] = i;
	} 
	int32_t B[] = {5,6,7,9,20};
	MergeInPlace(A, 10, B, 5);
	for (int i = 0; i < 15; i++) {
		cout<<A[i]<<" ";
	}
	cout<<endl;
}