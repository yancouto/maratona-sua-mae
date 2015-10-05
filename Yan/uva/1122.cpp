#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

int g[4][4];
ll pot[17];
ll hsh() {
	ll sum = 0;
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
			sum = mod(sum + pot[i * 4 + j] * g[i][j]);
	return sum;
}

bool ok(int i, int j) {
	if(i != 3 || j != 3) return false;
	for(i = 0; i < 4; i++)
		for(j = 0; j < 4; j++)
			if(g[i][j] != i * 4 + j + 1)
				return false;
	return true;
}

inline bool valid(int i, int j) { return i >= 0 && j >= 0 && i < 4 && j < 4; }

unordered_set<int> seen;
char act[50]; int an;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
void solve(int i, int j) {
	if(ok(i, j)) {
		reverse(act, act + an);
		for(i = 0; i < an; i++)
			putchar(act[i]);
		putchar('\n');
		exit(0);
	}
	if(an > 45) return;
	if(!seen.insert(hsh()).second) return;
	for(int d = 0; d < 4; d++) {
		int ni = i + dx[d], nj = j + dy[d];
		if(!valid(ni, nj)) continue;
		act[an++] = "RLDU"[d];
		swap(g[i][j], g[ni][nj]);
		solve(ni, nj);
		swap(g[i][j], g[ni][nj]);
		an--;
	}
}

int main() {
	int t, i, j, si, sj;
	scanf("%d", &t);
	pot[0] = 1;
	for(i = 1; i <= 16; i++)
		pot[i] = mod(pot[i - 1] * 19ll);
	while(t--) {
		for(i = 0; i < 4; i++)
			for(j = 0; j < 4; j++) {
				scanf("%d", &g[i][j]);
				if(!g[i][j]) si = i, sj = j;
			}
		solve(si, sj);
		puts("This puzzle is not solvable.");
	}
}
