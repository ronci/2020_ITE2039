// 2019015414_JeonYeonji_12838

#include <stdio.h>
#include <queue>

using namespace std;

queue< pair<int, int> > q;
int n, m;
int set[1010];
int group;

int findSet(int x) {
	if (x == set[x]) {
		return x;
	}
	return findSet(set[x]);
}

int main() {
	int i;
	int x, y;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		set[i] = i;
	}
	group = n;
	for (i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		q.push({ x, y });
	}
	while (!q.empty()) {
		x = q.front().first;
		y = q.front().second;
		q.pop();
		set[x] = findSet(x);
		set[y] = findSet(y);
		if (set[x] != set[y]) {
			if (set[y] > set[x]) set[set[y]] = set[x];
			else set[set[x]] = set[y];
			group--;
		}
	}
	printf("%d", group);
	return 0;
}