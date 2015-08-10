//#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }
#define oo 1000000000

int n;
int a[3][15];
int memo[5000][4][285];
int solve(int mask, int lst, int tme){
	if(tme > 280) return -oo;
	int &m = memo[mask][lst][tme];
	if(m != -1) return m;
	int ans = 0;
	for(int p = 0; p < n; p++){
		int k = 1<<p;
		if(mask&k) continue;
		for(int i = 1; i <= 3; i++){
			if(i == lst) continue;
			ans = max(ans, 1 + solve(mask|k, i, tme+a[i-1][p]));
		}
	}
	return m = ans;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		memset(memo, -1, sizeof memo);
		scanf("%d", &n);
		for(int i = 0; i < 3; i++)
			for(int j = 0; j < n; j++)
				scanf("%d", &a[i][j]);
		printf("%d\n", solve(0, 0, 0));  
	}
	return 0;
}
