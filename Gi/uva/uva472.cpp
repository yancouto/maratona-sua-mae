#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

int t1, t2;
char txt1[105][35], txt2[105][35];
int memo[105][105];


int solve (int i, int j) {
	int ans = -1;
	if (i == t1 || j == t2) return 0;
	int &m = memo[i][j];
	if (m != -1) return m;

	if (!strcmp(txt1[i], txt2[j]))
		ans = max(ans, 1 + solve(i + 1, j + 1));
	else {
		ans = max(ans, solve(i, j + 1));
		ans = max(ans, solve(i + 1, j));
	}

	return m = ans;
}

void build (int i, int j) {
	
	if (i == t1 || j == t2) return;
	int ans = solve(i, j);
	if (!strcmp(txt1[i], txt2[j])) {
		if (ans == 1 + solve(i + 1, j + 1)) {
			printf("%s", txt1[i]);
			if (ans != 1) printf(" ");
			build(i + 1, j + 1);
			return;
		}
	}
	else {
		if (ans == solve(i, j + 1))
			build(i, j + 1);
		else if (ans == solve(i + 1, j))
			build(i + 1, j);
	}

	return;
}

int main () {

	int i;
	while (scanf("%s", txt1[0]) != EOF) {
		i = 0;
		memset(memo, -1, sizeof(memo));
		while (strcmp(txt1[i++], "#")) 
			scanf("%s", txt1[i]); 
		t1 = i - 1;
		i = 0;
		scanf("%s", txt2[0]);
		while (strcmp(txt2[i++], "#"))
			scanf("%s", txt2[i]); 
		t2 = i - 1;
		build(0,0);
		if (memo[0][0] && memo[0][0] != -1) printf("\n");
	}
	return 0;
}

//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=472