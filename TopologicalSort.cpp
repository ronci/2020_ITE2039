// 2019015414_JeonYeonji_12838

#include <stdio.h>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

stack <int> st, dfs;
vector<int> v[1010];
int n, m;
int visit[1010], finish[1010];
int path[1010];
int cnt, checkDAG = 1;

int DFS(int x) {
	int i;
	visit[x] = 1;
	int size = v[x].size();
	for (i = 0; i < size; i++) {
		if (visit[v[x][i]] == 0) {
			DFS(v[x][i]);
		}
		else if (visit[v[x][i]] == 1 && finish[v[x][i]] == 0) {
			return 0;
		}
	}
	finish[x] = 1;
	dfs.push(x);
	return 1;
}

int main() {
	int i;
	int x, y;
	scanf("%d %d", &n, &m);
	for (i = 0; i < m; i++) {
		scanf("%d %d", &x, &y);
		v[x].push_back(y);
	}
	for (i = 1; i <= n; i++) {
		sort(v[i].begin(), v[i].end());
	}
	for (i = 1; i <= n; i++) {
		if (visit[i] == 0) {
			checkDAG = DFS(i);
			if (checkDAG == 0) {
				break;
			}
		}
	}

	while (!dfs.empty()) {
		x = dfs.top();
		path[cnt] = x;
		cnt++;
		dfs.pop();
	}

	printf("%d\n", checkDAG);
	if (checkDAG) {
		for (i = 0; i < cnt; i++) {
			printf("%d ", path[i]);
		}
	}
	return 0;
}
