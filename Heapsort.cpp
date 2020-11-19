// 2019015414_JeonYeonji_12838

#include <stdio.h>

void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void BuildMaxHeap(int array[], int key, int length) {
	int pre_length;
	int temp;
	array[length] = key;
	while (length > 1) {
		pre_length = length;
		length = length / 2;
		if (array[length] > array[pre_length]) {
			break;
		} 
		swap(array + length, array + pre_length);
	}
}

void ExtractMax(int array[], int length) {
	swap(array + 1, array + length);
	length--;
	int nextidx;
	int idx = 1;
	while (1) {
		nextidx = idx;
		if (idx * 2 > length) {
			break;
		}
		else if (idx * 2 + 1 <= length && array[idx * 2 + 1] > array[idx]) {
			nextidx = idx * 2 + 1;
		}
		if (array[idx * 2] > array[nextidx]) {
			nextidx = idx * 2;
		}
		swap(array + idx, array + nextidx);
		if (nextidx == idx) {
			break;
		}
		idx = nextidx;
	}
}

int main() {
	int n, k, array[100001];
	int key;
	int i;
	scanf("%d %d", &n, &k);
	for (i = 1; i <= n; i++) {
		scanf("%d", &key);
		BuildMaxHeap(array, key, i);
	}
	for (i = n; i >= 1; i--) {
		printf("%d ", array[1]);
		ExtractMax(array, i);
		if (i == n - k + 1) printf("\n");
	}
	return 0;
}
