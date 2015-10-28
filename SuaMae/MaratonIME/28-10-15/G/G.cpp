#include <bits/stdc++.h>
using namespace std;

int a[202], t[50][50];
int l, m;
int memo[103][30];
int solve(int i, int ant) {
	if(i == l - 1) return 0;
	int &r = memo[i][ant];
	if(r != -1) return r;
	r = INT_MAX;
	for(int c = 0; c < m; c++)
		r = min(r, abs(t[ant][c] - a[i]) + solve(i + 1, c));
	return r;
}

void build(int i, int ant) {
	putchar('a' + ant);
	if(i == l - 1) return;
	for(int c = 0; c < m; c++)
		if(solve(i, ant) == abs(t[ant][c] - a[i]) + solve(i + 1, c)) {
			build(i + 1, c);
			return;
		}
}

int main() {
	freopen("ssh.in", "r", stdin);
	freopen("ssh.out", "w", stdout);
	int i, j;
	scanf("%d %d", &l, &m);
	for(i = 0; i < l - 1; i++)
		scanf("%d", &a[i]);
	for(i = 0; i < m; i++)
		for(j = 0; j < m; j++)
			scanf("%d", &t[i][j]);
	memset(memo, -1, sizeof memo);
	int c = INT_MAX;
	for(i = 0; i < m; i++)
		c = min(c, solve(0, i));
	for(i = 0; i < m; i++)
		if(c == solve(0, i)) {
			build(0, i);
			putchar('\n');
			return 0;
		}
}
