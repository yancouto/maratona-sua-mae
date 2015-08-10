#include <cstdio>
#include <cstring>
#include <algorithm>
#define NMAX 5

using namespace std;

int a[NMAX];
int memo[32][405];

int solve (int mask, int res) {
	int ans = 0;
	if (mask == 31 && res == 23) return 1;
	if (mask == 31 || res > 225 || res < -177) return 0;
	int &m = memo[mask][res + 177];
	if (m != -1) return m;

	for (int i = 0; i < NMAX; i++)
		if ((mask&(1<<i)) == 0) {
			ans = max(ans, solve(mask|(1<<i), res + a[i]));
			if (mask == 0) 
				ans = max(ans, solve(mask|(1<<i), a[i]));
			else {
				ans = max(ans, solve(mask|(1<<i), res * a[i]));
				ans = max(ans, solve(mask|(1<<i), res - a[i]));
			}
		}

	return m = ans;
}

void read() {
	for (int i = 0; i < NMAX; i++)
		scanf("%d", &a[i]);
}

int main () {
	read();
	while (a[0] && a[1] && a[2] && a[3] && a[4]) {
		memset(memo, -1, sizeof(memo));
		if (solve(0,0)) printf("Possible\n");
		else printf("Impossible\n");
		read();
	}

	return 0;
}
//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1285