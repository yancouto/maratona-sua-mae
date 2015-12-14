#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct res {
	int n, bm1, bm2;
	res() {}
	res(int a, int b, int c) : n(a), bm1(b), bm2(c) {}
	bool operator == (res o) const { return bm1 == o.bm1 && bm2 == o.bm2; }
	bool operator < (res o) const {
		if(bm1 != o.bm1) return bm1 < o.bm1;
		if(bm2 != o.bm2) return bm2 < o.bm2;
		return n < o.n;
	}
};
vector<res> pre[1000][1000];

//ll memo[1 << 9][1 << 9][32];
//ll solve(int bm1, int bm2, int n) {
//	if(n == 0) return bm1 == 0 && bm2 == 0;
//	if(n == 1 && bm2 != 0) return 0;
//	ll &r = memo[bm1][bm2][n];
//	if(r != -1) return r;
//	r = 0;
//	for(res re : pre[bm1][bm2])
//		r += ll(re.n) * solve(re.bm1, re.bm2, n - 1);
//	return r;
//}

int n, m;
ll memo[1 << 9][1 << 9][2];
void pd() {
	memo[0][0][0] = 1;
	int n, bm1, bm2;
	for(n = 1; n <= ::n; n++) {
		for(bm1 = 0; bm1 < (1 << m); bm1++)
			for(bm2 = 0; bm2 < (1 << m); bm2++) {
				ll &r = memo[bm1][bm2][n & 1];
				r = 0;
				for(res re : pre[bm1][bm2])
					r += ll(re.n) * memo[re.bm1][re.bm2][!(n & 1)];
			}
	}
}


void go(int pos, int bm1, int bm2, int bm3, int i, int j) {
	if(pos == m) {
		pre[i][j].push_back(res(1, bm2, bm3));
		return;
	}
	if(bm1 & (1 << pos)) { go(pos + 1, bm1, bm2, bm3, i, j); return; }
	if(pos < m - 2 && (bm1 & (7 << pos)) == 0)
		go(pos + 3, bm1 | (7 << pos), bm2, bm3, i, j);
	if(!(bm2 & (1 << pos)))
		go(pos + 1, bm1 | (1 << pos), bm2 | (1 << pos), bm3 | (1 << pos), i, j);
}

void prep() {
	int i, j;
	for(i = 0; i < (1 << m); i++)
		for(j = 0; j < (1 << m); j++) {
			go(0, i, j, 0, i, j);
			sort(pre[i][j].begin(), pre[i][j].end());
			int k = 0, l = 0;
			for(k = 0; k < pre[i][j].size(); k++) {
				if(k == 0 || !(pre[i][j][k] == pre[i][j][k - 1]))
					pre[i][j][l++] = pre[i][j][k];
				else pre[i][j][l - 1].n++;
			}
		}

}

int main() {
	freopen("dominoes.in", "r", stdin);
	freopen("dominoes.out", "w", stdout);
	scanf("%d %d", &m, &n);
	prep();
	pd();
	printf("%I64d\n", memo[0][0][n & 1]);
}
