#include <bits/stdc++.h>

using namespace std;

const int MAX = 100010;

typedef long long lint;

lint dp[MAX][2][2], c[MAX][2][2], T;

int sol[MAX][2][2], N;

lint solve(int i, int st, int cm) {
	if(i == N) return 0;
	lint &ret = dp[i][st][cm];
	if(ret != -1) return ret;
	lint p1 = LLONG_MAX, p2 = LLONG_MAX;
	if(i == N - 1) {
			if(cm == 0) p1 = c[i][!st][0] + solve(i + 1, 0, cm);
			else p2 = c[i][!st][1] + solve(i + 1, 1, cm);
	}
	else {
		p1 = c[i][!st][0] + solve(i + 1, 0, cm);
		p2 = c[i][!st][1] + solve(i + 1, 1, cm);
	}
	if(p1 < p2) {
		sol[i][st][cm] = 0;
		ret = p1;
	} else {
		sol[i][st][cm] = 1;
		ret = p2;
	}
	return ret;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--) {
		lint sum = 0;
		scanf("%d %lld", &N, &T);
		for(int i = 0; i < N; i++) {
			lint aux;
			scanf("%lld%lld%lld%lld%lld", &aux, &c[i][0][0], &c[i][0][1], &c[i][1][0], &c[i][1][1]);
			sum += aux;
			dp[i][0][0] = dp[i][0][1] = dp[i][1][0] = dp[i][1][1] = -1;
		}
		lint ansA = solve(0, 0, 0), ansB = solve(0, 1, 1);
		if(ansA <= T - sum || ansB <= T - sum) {
			int idx = 0, idy, idz;
			if(ansA < ansB) {
				printf("F");
				idz = idy = 0;
			} else {
				printf("B");
				idz = idy = 1;
			}
			while(idx < N - 1) {
				if(sol[idx][idy][idz] == 0) printf("F");
				else printf("B");
				idy = sol[idx][idy][idz];
				idx++;
			}
			printf("\n");
		} else {
			printf("IMPOSSIBLE\n");
		}
	}
	return 0;
}
