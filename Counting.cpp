// 2019015414_JeonYeonji_12838

#include <stdio.h>

int n, m, k;
int key;
int count_array[100001];
int qurey_range[100000][2];

int main() {
	int i;
	scanf("%d %d %d", &n, &m, &k);
	for (i = 0; i < k; i++) {
		scanf("%d %d", &qurey_range[i][0], &qurey_range[i][1]);
	}
	for (i = 0; i <= m; i++) {
		count_array[i] = 0;
	}
	for (i = 0; i < n; i++) {
		scanf("%d", &key);
		count_array[key]++;
	}
	for (i = 1; i <= m; i++) {
		count_array[i] += count_array[i - 1];
	}
	for (i = 0; i < k; i++) {
		if (qurey_range[i][0] == 0) {
			printf("%d\n", count_array[qurey_range[i][1]]);
		}
		else {
			printf("%d\n", count_array[qurey_range[i][1]] - count_array[qurey_range[i][0] - 1]);
		}
	}
	return 0;
}
