#include <cstdio>
#include <algorithm>
#include <cstring>
#define inf 1000000000

using namespace std;

int alt[1005], n;
int memo[1005];

int solve (int i) {
	int ans = -1;
	int &m = memo[i];
	if (m != -1) return m;
	//printf("i = %d\n",i);
	int stop = 1;
	for (int k = i + 1; k < n; k++)
		if (alt[i] < alt[k]) {
			stop = 0;
			ans = max(ans, 1 + solve(k));
		}

	if (stop) return 1;
	return m = ans;
}

void build (int i) {
	int ans = solve(i);
	int stop = 1;

	if (i != 0)
		printf("%d\n", alt[i]);
	for (int k = i + 1; k < n; k++)
		if (alt[i] < alt[k]) {
			stop = 0;
			if (ans == 1 + solve(k)) {
				build(k);
			}
		}
	if (stop) 
		return;
}

int main () {
	int t;
	char a[10];
	scanf("%d ", &t);

	while (t--) {
		n = 0;
		memset(memo, -1, sizeof(memo));
		if (t == 0) {
			while (scanf("%d", &alt[++n]) != EOF);
		}
		else {
			while (true) {
				fgets(a, 10, stdin);
				if (a[0] == '\n') 
					break;
				sscanf(a, "%d", &alt[++n]);
			}
			n++;
		}
		alt[0] = -inf;
		/*for (int i = 0; i < n; i++)
			printf("%d ",alt[i]);
		printf("\n");*/
		printf("Max hits: %d\n", solve(0) - 1);
		if (n == 0) printf("0\n");
		else build(0);
		if (t != 0) printf("\n");

	}
	return 0;
}

//http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=438