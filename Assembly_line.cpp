// 2019015414_Àü¿¬Áö_12838

#include <stdio.h>
#define min(x, y) x < y ? x : y

int n, ans;
int e[3], x[3];
int a[3][110];
int t[3][110];
int d[3][110], path[3][110];

void findPath(int line, int station) {
	if (path[line][station] != 0) {
		findPath(path[line][station], station - 1);
	}
	printf("%d %d\n", line, station);
	return;
}

int main() {
	int i, j;
	scanf("%d", &n);
	scanf("%d %d", &e[1], &e[2]);
	scanf("%d %d", &x[1], &x[2]);
	for (i = 1; i <= 2; i++) {
		for (j = 1; j <= n; j++) {
			scanf("%d", &a[i][j]);
		}
	}
	for (i = 1; i <= 2; i++) {
		for (j = 1; j < n; j++) {
			scanf("%d", &t[i][j]);
		}
	}
	d[1][1] = e[1] + a[1][1];
	d[2][1] = e[2] + a[2][1];
	for (i = 2; i <= n; i++) {
		for (j = 1; j <= 2; j++) {
			if (d[j][i - 1] > d[3 - j][i - 1] + t[3 - j][i - 1]) {
				d[j][i] = d[3 - j][i - 1] + t[3 - j][i - 1];
				path[j][i] = 3 - j;
			}
			else {
				d[j][i] = d[j][i - 1];
				path[j][i] = j;
			}
			d[j][i] += a[j][i];
		}
	}
	if (d[1][n] + x[1] > d[2][n] + x[2]) {
		printf("%d\n", d[2][n] + x[2]);
		findPath(2, n);
	}
	else {
		printf("%d\n", d[1][n] + x[1]);
		findPath(1, n);
	}
	return 0;
}
