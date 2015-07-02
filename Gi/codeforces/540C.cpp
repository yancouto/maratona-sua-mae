#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
using namespace std;

int n, m;
int ind[500][500], cave[500][500];

bool isIn (int i, int j) {
	if (i >= 0 && i < n && j >= 0 && j < m)
		return true;
	return false;
}

int dfs (int o, int dest) {
	stack<int> s;
	int vis[250005];
	memset(vis, 0, sizeof(vis));
	//printf("o=%d-dest=%d\n", o, dest);
	if (o == dest) return 1;
	vis[o] = 1;
	s.push(o);
	while (!s.empty()) {
		int i, j, k = s.top();
		s.pop();
		if (((k+1)/m)*m < k + 1)
			i = (k+1)/m;
		else
			i = (k+1)/m - 1; 
		j = k -i*m;
		//printf("\n\ndest=%d-k=%d-(%d,%d)\n", dest, k, i, j);
		if (k == dest) return 1;
		if (isIn(i - 1, j) && !vis[ind[i-1][j]] && (!cave[i-1][j] || ind[i-1][j] == dest)) {
			//printf("cima(%d,%d)\n",i-1, j);
			s.push(ind[i-1][j]);
			vis[ind[i-1][j]] = 1;
		}
		if (isIn(i, j - 1) && !vis[ind[i][j-1]] && (!cave[i][j-1] || ind[i][j-1] == dest)) {
		//	printf("esquerda(%d,%d)\n",i, j-1);
			s.push(ind[i][j-1]);
			vis[ind[i][j-1]] = 1;
		}
		if (isIn(i + 1, j) && !vis[ind[i+1][j]] && (!cave[i+1][j] || ind[i+1][j] == dest)) {
		//	printf("baixo(%d,%d)\n",i+1, j);
			s.push(ind[i+1][j]);
			vis[ind[i+1][j]] = 1;
		}
		if (isIn(i, j + 1) && !vis[ind[i][j+1]] && (!cave[i][j+1] || ind[i][j+1] == dest)) {
		//	printf("direita(%d,%d)\n",i, j+1);
			s.push(ind[i][j+1]);
			vis[ind[i][j+1]]  = 1;
		}
	}
	return 0;

}

int abs(int a) {
	if (a < 0) return -a;
	return a;
}

int main () {
	scanf("%d%d", &n, &m);
	int i, j, count = 0;
	char c;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) {
			scanf(" %c", &c);
			if (c == '.')
				cave[i][j] = 0;
			else cave[i][j] = 1;
			ind[i][j] = count++; 
		}
	int r1, c1, r2, c2;
	scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
	r1--; r2--; c1--; c2--;
	//printf("indice[%d][%d]=%d\n", r2, c2, ind[r2][c2]);
	if (dfs(ind[r1][c1], ind[r2][c2])) {
		if (cave[r2][c2] && ind[r1][c1] != ind[r2][c2]) printf("YES\n");
		else {
			int viz = 0;
			if (isIn(r2-1, c2) && !cave[r2-1][c2]) viz++;
			if (isIn(r2, c2-1) && !cave[r2][c2-1]) viz++;
			if (isIn(r2+1, c2) && !cave[r2+1][c2]) viz++;
			if (isIn(r2, c2+1) && !cave[r2][c2+1]) viz++;
			if (viz > 1) printf("YES\n");
			else if (viz == 1 && (ind[r1][c1] == ind[r2][c2] || (abs(r1-r2) == 1 && c1 == c2) || (abs(c1-c2) == 1 && r1 == r2))) printf("YES\n");
			else
				printf("NO\n");
		}
	} else
		printf("NO\n");

	return 0;
}