// 2019015414_Àü¿¬Áö_12838

#include <stdio.h>
#define MIN -2147483648 

int n;
int p[110], r[110], s[110];
int q;

void printCut(int x) {
	if (x == 0) return;
	
	printf("%d ", s[x]);
	printCut(x - s[x]);
	return;
}

int main() {
	int i, j;
	scanf("%d", &n);
	for (i = 1; i <= n; i++) {
		scanf("%d", &p[i]);
	}
	for (j = 1; j <= n; j++) {
		q = MIN;
		for (i = 1; i <= j; i++) {
			if (q < p[i] + r[j - i]) {
				q = p[i] + r[j - i];
				s[j] = i;
			}
		}
		r[j] = q;
	}
	printf("%d\n", r[n]);
	printCut(n);
	return 0;
}
