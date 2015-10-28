#include <bits/stdc++.h>

using namespace std;

typedef unsigned int num;

const int N = 23;

struct prob {
	int i, a, l, o;
};

struct team {
	int t, z, v, c;
};

int m, n, t, l;
int anc;
prob ps[N];
team ts[N];
int expc[N][N];
int rea[N][N];
int ord[N][N];
int sol[N];
int pen[N];

bool cmp_anc (int i, int j) {
	if (expc[anc][i] == expc[anc][j])
		return rea[anc][i] < rea[anc][j];
	return expc[anc][i] < expc[anc][j];
}

bool rnk_ord (int i, int j) {
	if (sol[i] != sol[j])
		return sol[i] > sol[j];
	if (pen[i] != pen[j])
		return pen[i] < pen[j];
	return i < j;
}

void calc (int tm, num st) {
	sol[tm] = 0;
	pen[tm] = 0;
	int att = 0;
	for (int j = 0; j < m; j++) {
		int k = ord[tm][j];
		if (!(st&(1u<<k)))
			continue;
		if (expc[tm][k] == INT_MAX)
			break;
		att += rea[tm][k];

		if (att > l)
			break;
		sol[tm]++;
		pen[tm] += att;
	}
}

int solve (num st) {
	calc(0, st);

	int rank = 0;
	for (int i = 1; i < t; i++) {
		calc(i, st);
		if (rnk_ord(i, 0))
			rank++;
	}
	return rank;
}

int main ( ){
	freopen("unfair.in", "r", stdin);
	freopen("unfair.out", "w", stdout);

	scanf("%d %d %d %d", &m, &n, &t, &l);

	for (int i = 0; i < m; i++)
		scanf("%d %d %d %d", &ps[i].i, &ps[i].a, &ps[i].l, &ps[i].o);
	
	for (int i = 0; i < t; i++)
		scanf("%d %d %d %d", &ts[i].t, &ts[i].z, &ts[i].v, &ts[i].c);

	for (int i = 0; i < t; i++) {
		team tr = ts[i];
		for (int j = 0; j < m; j++) {
			prob pr = ps[j];
			if (tr.t+tr.c <= pr.i-pr.o)
				expc[i][j] = INT_MAX;
			else
				expc[i][j] = ((pr.i+pr.o-1)/pr.o) + max((pr.a+tr.c-1)/tr.c, 5);
			rea[i][j] = max(pr.i-tr.t, 0) + ((pr.a+(tr.z+tr.c)-1)/(tr.z+tr.c)) + ((pr.l+tr.v-1)/tr.v);
			ord[i][j] = j;
		}
		anc = i;
		sort(ord[i], ord[i]+m, cmp_anc);
	}

	int best = INT_MAX;
	num res = 0u;

	for (num i = 0; i < (1u << m); i++) {
		if (__builtin_popcount(i) != n)
			continue;

		int loc = solve(i);

		if (loc < best) {
			best = loc;
			res = i;
		}
	}

	bool ok = 0;
	for (int i = 0; i < m; i++) {
		if (res&(1u<<i)) {
			if (ok)
				printf(" ");
			printf("%d", i+1);
			ok = 1;
		}
	}
	printf("\n");
}

