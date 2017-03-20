#include <iostream>
using namespace std;

const int SIZE = 15;
void BuildHeap(int *array, int len);
void AdjustHeap(int *array, int len, int index);
void swap(int &a, int &b);

int main() {

	int a[SIZE] = { 2, 3, 5, 4, 9, 8, 7, 10, 12, 16, 18, 20, 3, 4, 1 };
	int array[SIZE + 1];
	for (int i = 1; i <= SIZE; i++) {
		array[i] = a[i - 1];
	}

	int k = 9;
	BuildHeap(array, k);

	for(int j = k+1; j<= SIZE;j++){
		if(array[1] > array[j]){
			swap(array[1], array[j]);
			AdjustHeap(array, k, 1);
		}
	}

//	BuildHeap(array, SIZE);

	for (int i = 1; i <= k; i++) {
		cout << "array[" << i << "]=" << array[i] << endl; // prints !!!Hello World!!!
	}

	return 0;
}

void BuildHeap(int *array, int len) {
	for (int i = len / 2; i > 0; i--) {
		AdjustHeap(array, len, i);
	}
}

void AdjustHeap(int *array, int len, int index) {
	while (2 * index <= len) {
		int max = index;
		int lChild = 2 * index, rChild = 2 * index + 1;
		if (rChild <= len) {
			if (array[lChild] > array[rChild] && array[lChild] > array[index]) {
				max = lChild;
			} else if (array[lChild] <= array[rChild]
					&& array[rChild] > array[index]) {
				max = rChild;
			}
		} else if (lChild <= len && array[lChild] > array[index]) {
			max = lChild;
		}

		if (max != index) {
			swap(array[max], array[index]);
			index = max;
		}else{
			break;
		}
	}

}

void swap(int &a, int &b) {
	int temp = a;
	a = b;
	b = temp;
}
