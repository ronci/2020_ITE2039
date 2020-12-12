// 2019015414_JeonYeonji_12838

#include <stdio.h>
#include <queue>

using namespace std;

priority_queue< pair<int, pair<int, int> > > pq, ans;
int n, m;
int depth[1010], set[1010];
int edge;

int findSet(int x) {
	if (x == set[x]) {
		return x;
	}
	return findSet(set[x]);
}

int main() {
	int i;
	int x, y, w;
	scanf("%d %d", &n, &m);
	for (i = 1; i <= n; i++) {
		set[i] = i;
	}
	for (i = 0; i < m; i++) {
		scanf("%d %d %d", &x, &y, &w);
		if(x > y) pq.push({ -w, {-y, -x} });
		else pq.push({ -w, {-x, -y} });
	}
	while (!pq.empty()) {
		w = -pq.top().first;
		x = -pq.top().second.first;
		y = -pq.top().second.second;
		pq.pop();
		set[x] = findSet(x);
		set[y] = findSet(y);
		if (set[x] != set[y]) {
			ans.push({ -w, {-x, -y} });
			edge++;
			if (depth[set[x]] > depth[set[y]]) {
				set[set[y]] = set[x];
			}
			else if (depth[set[x]] < depth[set[y]]) {
				set[set[x]] = set[y];
			}
			else {
				if (set[y] > set[x]) {
					set[set[y]] = set[x];
					depth[set[x]]++;
				}
				else { //set[y] < set[x]
					set[set[x]] = set[y];
					depth[set[y]]++;
				}
			}
		}
	}
	printf("%d\n", edge);
	while (!ans.empty()) {
		printf("%d %d %d\n", -ans.top().second.first, -ans.top().second.second, -ans.top().first);
		ans.pop();
	}
	return 0;
}