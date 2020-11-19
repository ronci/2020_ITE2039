// 2019015414_JeonYeonji_12838

#include <stdio.h>

int array_a[100000], array_b[100000];

void Merge(int array[], int st, int mid, int ed) {
	int i;
	int n1 = mid - st + 1;
	int n2 = ed - mid;
	int cp_array[100000];
	for (i = st; i <= ed; i++) {
		cp_array[i] = array[i];
	}

	int left = st;
	int right = mid + 1;
	for (i = 0; i < n1 + n2; i++) {
		if (left > mid || (right <= ed && cp_array[right] < cp_array[left])) {
			array[st + i] = cp_array[right];
			right++;
		}
		else {
			array[st + i] = cp_array[left];
			left++;
		}
	}
}

void MergeSort(int array[], int st, int ed) {
	if (st < ed) {
		int mid = (st + ed) / 2;
		MergeSort(array, st, mid);
		MergeSort(array, mid + 1, ed);
		Merge(array, st, mid, ed);
	}
}

int main() {
	int n, m, max_len, cnt;
	int i, j;
	cnt = 0;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++) {
		scanf("%d", &array_a[i]);
	}
	MergeSort(array_a, 0, n - 1);
	for (i = 0; i < m; i++) {
		scanf("%d", &array_b[i]);
	}
	MergeSort(array_b, 0, m - 1);
	for (i = 0, j = 0; i < n && j < m; ) {
		if (array_a[i] == array_b[j]) {
			cnt++;
			i++;
			j++;
		}
		else if (array_a[i] > array_b[j]) {
			j++;
		}
		else {
			i++;
		}
	}
	printf("%d", cnt);
	return 0;
}
