#include <bits/stdc++.h>
using namespace std;
int n;
int t[9], g[9][9];

bool solve(int p) {
	int i = p / n, j = p % n;
	if(i && !j) { // line
		memset(t, 0, sizeof t);
		for(int k = 0; k < n * n; k++)
			t[g[i-1][k] - 1] = 1;
		for(int k = 0; k < n * n; k++)
			if(!t[k]) {
				printf("wrong line:");
				for(int l = 0; l < n * n; l++)
					printf(" %d", g[i-1][l]);
				putchar('\n');
				return false;
			}
	}
	if(i == n * n - 1 && j) { // column
		memset(t, 0, sizeof t);
		for(int k = 0; k < n * n; k++)
			t[g[k][j-1] - 1] = 1;
		for(int k = 0; k < n * n; k++)
			if(!t[k])
				return false;
	}
	int pi = (p - 1) / n, pj = (p - 1) % n;
	if(i && !((pi+1)%n) && !((pj+1)%n)) { // grid
		memset(t, 0, sizeof t);
		for(int k = 0; k < 3; k++)
			for(int l = 0; l < 3; l++)
				t[g[pi-k][pj-l]-1] = 1;
		for(int k = 0; k < n * n; k++)
			if(!t[k])
				return false;
	}
	if(p == n * n * n * n) {
		for(i = 0; i < n*n; i++) {
			printf("%d", g[i][0]);
			for(j = 1; j < n*n; j++)
				printf(" %d", g[i][j]);
			putchar('\n');
		}
		return true;
	}
	if(g[i][j]) return solve(p + 1);	
	for(int k = 1; k <= n * n; k++) {
		g[i][j] = k;
		if(solve(p + 1))
			return true;
	}
	g[i][j] = 0;
	return false;
}

int main() {
	int i, j; bool f = false;
	while(scanf("%d", &n) != EOF) {
		if(f) putchar('\n');
		f = true;
		for(i = 0; i < n*n ; i++)
			for(j = 0; j < n*n; j++)
				scanf("%d", &g[i][j]);
		if(!solve(0)) puts("NO SOLUTION");
	}
}
