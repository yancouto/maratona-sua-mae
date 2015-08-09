#include <cstdio>
#include <cstring>
#include <algorithm>
#define NMAX 1005
#define inf 1000000000
using namespace std;

struct elephant {
	int w, q;
};

elephant e[NMAX], eor[NMAX];
int n;
int memo[NMAX];

bool myfunction (elephant a, elephant b) {
	if (a.w == b.w) return a.q > b.q;
	return a.w < b.w;
}

void search (int i) {
	for (int k = 0; k < n; k++)
		if (e[i].w == eor[k].w && e[i].q == eor[k].q) {
			printf("%d\n", k);
			return;
		}

}

int solve (int i) {
	int ans = -1;
	int &m = memo[i];
	if (m != -1) return m;

	int stop = 1;
	for (int k = i + 1; k < n; k++) {
		if (e[i].w < e[k].w && e[i].q > e[k].q) {
			stop = 0;
			ans = max(ans, 1 + solve(k));
		}
	}

	if (stop) return 0;

	return m = ans;
}

void build (int i) {

	int ans = solve(i);
	int stop = 1;
	for (int k = i + 1; k < n; k++) {
		if (e[i].w < e[k].w && e[i].q > e[k].q) {
			stop = 0;
			if (ans == 1 + solve(k)) {
				search(k);
				build(k);
				break;
			}
		}
	}

	if (stop) return;

	return ;
}


int main () {
	int t = 1;
	while (scanf("%d%d", &e[t].w, &e[t].q) != EOF) {
		eor[t].w = e[t].w;
		eor[t].q = e[t].q;
		t++;
	}
	e[0].w = eor[0].w = 0; e[0].q = eor[0].q = inf;
	memset(memo, -1, sizeof(memo));
	n = t;
	sort(e, e + n, myfunction);

	printf("%d\n", solve(0));
	build(0);
	return 0;
}
//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1072
