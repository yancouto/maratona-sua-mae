#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXL = 1010;

int len;
char strA[MAXL], strB[MAXL];
int dp[MAXL][MAXL], pre[MAXL][MAXL];

int seq(int i, int j) {
	if(i == len || j == len) return 0;
	int &ret = pre[i][j];
	if(ret == -1) {
		if(abs(strA[i] - strB[j]) <= 1)
			ret = 1 + seq(i + 1, j + 1);
		else
			ret = 0; 
	}
	
	return ret;
}

int solve(int i, int j) {
	if(i == len || j == len) return 0;
	int &ret = dp[i][j];
	if(ret == -1)
		ret = max(max(solve(i + 1, j), solve(i, j + 1)), seq(i, j));
	return ret;
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &len);
		scanf(" %s %s", strA, strB);
		for(int i = 0; i < len; i++) {
			for(int j = 0; j < len; j++) {
				dp[i][j] = pre[i][j] = -1;
			}
		}
		if(solve(0, 0)*2 >= len) {
			printf("POSITIVE\n");
		} else {
			printf("NEGATIVE\n");
		}
	}
	return 0;
}
