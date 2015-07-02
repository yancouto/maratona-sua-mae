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

int main () {
	long long n, k, m;
	scanf("%lld %lld %lld", &k, &m, &n);
	
	long long cost = (1 + n)*n/2;
	m-= k*cost;
	if (m >= 0)
		printf("0\n");
	else
		printf("%lld\n", -m);
	
	return 0;
}
//http://codeforces.com/contest/546/problem/A