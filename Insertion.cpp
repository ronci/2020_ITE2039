// 2019015414_Àü¿¬Áö_Algorithm

#include <stdio.h>

void InsertionSort(int n, int array[]) {
	int i, j;
	int key;
	for (i = 1; i < n; i++) {
		key = array[i];
		for (j = i - 1; j >= 0; j--) {
			if (key > array[j]) {
				array[j + 1] = array[j];
			}
			else break;
		}
		array[j + 1] = key;
	}

}

int main() {
	int n, array[30000];
	int i;
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &array[i]);
	}
	InsertionSort(n, array);
	for (i = 0; i < n; i++) {
		printf("%d\n", array[i]);
	}
	return 0;
}
