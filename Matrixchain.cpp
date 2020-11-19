// 2019015414_JeonYeonji_12838

#include <stdio.h>
#define MAX_INT 2147483647

int n;
int p[110];
int m[110][110], s[110][110];

void printParens(int x, int y) {
	if (x == y) {
		printf("%d ", x);
		return;
	}
	printf("( ");
	printParens(x, s[x][y]);
	printParens(s[x][y] + 1, y);
	printf(") ");
	return;
}

int main() {
	int i, j, l, k;
	int q;
	scanf("%d", &n);
	for (i = 0; i <= n; i++) {
		scanf("%d", &p[i]);
	}
	for (l = 2; l <= n; l++) { 
		for (i = 1; i <= n - l + 1; i++) {
			j = i + l - 1;
			m[i][j] = MAX_INT;
			for (k = i; k < j; k++) {
				q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
				if (q < m[i][j]) {
					m[i][j] = q;
					s[i][j] = k;
				}
			}
		}
	}
	printf("%d\n", m[1][n]);
	printParens(i, j);
	return 0;
}
