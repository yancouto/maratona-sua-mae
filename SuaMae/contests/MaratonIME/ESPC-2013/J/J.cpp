#include <bits/stdc++.h>
using namespace std;
typedef double num;
const double eps = 1e-7;

struct cmp {
	bool operator() (double a, double b) {
		if(abs(b - a) <= eps) return false;
		return a < b;
	}
};

int A[10][10][10][10][10];
int AA(int i, int j, int k, int l, int m) {
	if(i < 0 || j < 0 || k < 0 || l < 0 || m < 0) return 0;
	return A[i][j][k][l][m];
}

void acc() {
	int i, j, k, l, m;
	for(int g = 0; g < 5; g++)
		for(i = 0; i < 10; i++)
			for(j = 0; j < 10; j++)
				for(k = 0; k < 10; k++)
					for(l = 0; l < 10; l++)
						for(m = 0; m < 10; m++) {
							int &a = A[i][j][k][l][m];
							if(g == 0) a += AA(i, j, k, l, m - 1);
							else if(g == 1) a += AA(i, j, k, l - 1, m);
							else if(g == 2) a += AA(i, j, k - 1, l, m);
							else if(g == 3) a += AA(i, j - 1, k, l, m);
							else if(g == 4) a += AA(i - 1, j, k, l, m);
						}

}

int I[2][10009][5];
int calc(int q, int bm) {
	int b[5];
	for(int j = 0; j < 5; j++)
		b[j] = I[!!(bm & (1 << j))][q][j];
	return AA(b[0], b[1], b[2], b[3], b[4]);
}

map<num, int, cmp> s[5];
int query(int q) {
	int j;
	bool bad = false;
	for(j = 0; j < 5; j++) {
		double l;
		scanf("%lf", &l);
		auto it = s[j].lower_bound(l);
		if(it == s[j].end()) bad = true;
		else I[0][q][j] = it->second;
		I[0][q][j]--;
	}
	for(j = 0; j < 5; j++) {
		double r;
		scanf("%lf", &r);
		auto it = s[j].upper_bound(r);
		if(it == s[j].begin()) bad = true;
		else I[1][q][j] = (--it)->second;
	}
	if(bad) return 0;
	int tot = 0;
	for(int i = 0; i < (1 << 5); i++) {
		int p = __builtin_popcount(i) & 1;
		int e = calc(q, i);
		if(p) tot += e;
		else tot -= e;
	}
	if(tot >= 0) return tot;
	else return -tot;
}

// WHYYYY CODEFORCES? AHHHHHHHHHHH
double p[10009][5];
int main() {
	freopen("gift.in", "r", stdin);

	int tn, n, q;
	scanf("%d", &tn);
	for(int tt = 1; tt <= tn; tt++) {
		int i, j;
		scanf("%d %d", &n, &q);
		for(j = 0; j < 5; j++) s[j].clear();
		for(i = 0; i < n; i++) {
			for(j = 0; j < 5; j++) {
				scanf("%lf", &p[i][j]);
				s[j][p[i][j]] = 0;
			}
		}
		memset(A, 0, sizeof A);
		for(j = 0; j < 5; j++) {
			i = 0;
			for(auto &e : s[j])
				e.second = i++;
		}
		for(i = 0; i < n; i++) {
			int g[5];
			for(j = 0; j < 5; j++)
				g[j] = s[j][p[i][j]];
			A[g[0]][g[1]][g[2]][g[3]][g[4]]++;
		}
		acc();
		printf("Case %d:\n", tt);
		for(i = 0; i < q; i++)
			printf("%d\n", query(i));
	}
}
