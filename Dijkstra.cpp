// 2019015414_JeonYeonji_12838

#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

vector<pair<int, int> > v[5010];
priority_queue < pair<int, int> > pq;
int n, m, ans;
int d[5010];

int main() {
	int i;
	int x, y, w;
	int dist, now, size;
	int next, edgeDist;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &x, &y, &w);
		v[x].push_back({ y, w });
	}
	for (i = 2; i <= n; i++) {
		d[i] = -1;
	}
	pq.push({ 0, - 1 });
	while (!pq.empty()) {
		dist = -pq.top().first;
		now = -pq.top().second;
		pq.pop();
		size = v[now].size();
		for (i = 0; i < size; i++) {
			next = v[now][i].first;
			edgeDist = v[now][i].second;
			if (d[next] == -1 || (d[next] != -1 && d[next] > edgeDist + dist)) {
				d[next] = dist + edgeDist;
				pq.push({ -d[next], -next });
			}
		}
	}
	for (i = 1; i <= n; i++) {
		if (ans < d[i]) ans = d[i];
	}
	printf("%d", ans);
	return 0;
}
