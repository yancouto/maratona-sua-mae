#include <cstdio>
#include <cstring>
#include <cmath>
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <climits>
#include <queue>

using namespace std;

int memo[5000002];
long long ac[5000002];
int prime[1000000], ip;

void preproc () {
	prime[ip++] = 2;
	prime[ip++] = 3;
	ac[2] = 1; ac[3] = 2;
	memo[2] = 1; memo[3] = 1;
	for (int i = 4; i <= 5000000; i++) {
		for (int p = 0; p < ip && prime[p]*prime[p] <= i; p++) {
			if (i % prime[p]) continue;
			memo[i] = 1 + memo[i/prime[p]];
			break;
		}
		if (memo[i] == 0) {
			memo[i] = 1;
			prime[ip++] = i;
		}
		ac[i] = ac[i-1] + memo[i];
	}
}


int main () {
	preproc();
	int t, a, b;
	scanf("%d", &t);

	while (t--) {
		scanf("%d%d", &a, &b); 
		printf("%lld\n", ac[a] - ac[b]);
	}
	return 0;
}
//http://codeforces.com/contest/546/problem/D