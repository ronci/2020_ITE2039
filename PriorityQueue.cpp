// 2019015414_JeonYeonji_12838

#include <stdio.h>

void swap(int* a, int* b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void BuildMaxHeap(int array[], int key, int len) {
	int pre_len;
	int temp;
	array[len] = key;
	while (len > 1) {
		pre_len = len;
		len = len / 2;
		if (array[len] > array[pre_len]) {
			break;
		} 
		swap(array + len, array + pre_len);
	}
}

void ExtractMax(int array[], int idx, int maxlen) {
	int nextidx;
	while (1) {
		nextidx = idx;
		if (idx * 2 > maxlen) {
			break;
		}
		else if (idx * 2 + 1 <= maxlen && array[idx * 2 + 1] > array[idx]) {
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
	int cnt, array[100001];
	int key, cmd, idx;
	int i;
	cnt = 0;
	while (1) {
		scanf("%d", &cmd);
		if (cmd == 0) {
			printf("\n");
			for (i = 1; i <= cnt; i++) {
				printf("%d ", array[i]);
			}
			break;
		}
		else if (cmd == 1) {
			cnt++;
			scanf("%d", &key);
			BuildMaxHeap(array, key, cnt);
		}
		else if (cmd == 2) {
			printf("%d ", array[1]);
			swap(array + 1, array + cnt);
			cnt--;
			ExtractMax(array, 1, cnt);
		}
		else {
			scanf("%d %d", &idx, &key);
			if (array[idx] > key) {
				array[idx] = key;
				ExtractMax(array, idx, cnt);
			}
			else if (array[idx] < key) {
				array[idx] = key; 
				BuildMaxHeap(array, key, idx);
			}
		}
	}
	
	return 0;
}
