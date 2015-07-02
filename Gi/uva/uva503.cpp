#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#define inf 1000000000

using namespace std;

int N, S;
int coin[105]; 
vector<int> memo[105];

int abs(int a) {
	if (a < 0) return -a;
	return a;
}

int solve (int i, int sum) {
	if (i == N)  
		return abs(sum - abs(sum - S));

	int &m = memo[i][sum];
	if (m != -1) return m;

	int ans;
	ans = min(solve(i + 1, sum + coin[i]), solve(i + 1, sum));	

	return m = ans;
}

int main () {
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &N);
		int i, sum = 0;
		for (i = 0; i < N; i++) {
			scanf("%d", &coin[i]);
			sum += coin[i];
		}
		for (i = 0; i < N + 2; i++) {
			memo[i].clear();
			for (int j = 0; j < sum + 2; j++)
				memo[i].push_back(-1);
		}
		S = sum;
		printf("%d\n", solve(0,0));
	}
	return 0;
}

//http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=503