// 2019015414_Àü¿¬Áö_Algorithm

#include <stdio.h>

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
		if (left > mid || (right <= ed && cp_array[right] > cp_array[left])) {
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
	int n, array[100000];
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &array[i]);
	}
	MergeSort(array, 0, n-1);
	for (i = 0; i < n; i++) {
		printf("%d\n", array[i]);
	}
	return 0;
}
