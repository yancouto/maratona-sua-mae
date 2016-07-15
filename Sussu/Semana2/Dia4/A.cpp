#include <bits/stdc++.h>
#define mp make_pair
#define debug(args...) //fprintf(stderr, args)
#define pb push_back
#define ff first
#define ss second
using namespace std;

const int MAXN = 2123, INF = 1e7;

int dp[MAXN][2*MAXN], n;
char str[MAXN];

int f(int i, int k) {
	if(k > 2*n || k < 0) return INF;
	if(i == n) return k ? INF : 0;
	int &ret = dp[i][k];
	if(ret == -1) {
		if(str[i] == '(') return ret = 1 + f(i + 1, k + 1);
		else if(str[i] == ')') return ret = 1 + f(i + 1, k - 1);
		else if(str[i] == '[') return ret = min(1 + f(i, k + 1), f(i + 1, k));
		else return ret = min(1 + f(i, k - 1), f(i + 1, k));
	}
	return ret;
}

int main() {
	scanf(" %s", str);
	n = strlen(str);
	memset(dp, -1, sizeof dp);
	debug("%d\n", f(0, 0));
	if(f(0, 0) >= INF) {
		printf("Impossible\n");
		return 0;
	}
	int i = 0, k = 0;
	while(i != n) {
		if(str[i] == '(') {
			printf("(");
			i++; k++;
		}
		if(str[i] == ')') {
			printf(")");
			i++; k--;
		}
		if(str[i] == '[') {
			if(f(i, k) == 1 + f(i, k + 1)) {
				printf("(");
				k++;
			} else {
				i++;
			}
		}
		if(str[i] == ']') {
			if(f(i, k) == 1 + f(i, k - 1)) {
				printf(")");
				k--;
			} else {
				i++;
			}
		}
	}
	puts("");
	return 0;
}
