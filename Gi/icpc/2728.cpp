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
int n, t, m1, m2;
int tme[52], acc[52], s1[52], s2[52];
int memo[210][52];
bool check(int s, int tcur, int st, int tr){
	if(s)
		return s2[tr]+acc[n-1]-acc[st] == tcur;
	return acc[st]+s1[tr] == tcur;
}

int solve(int tcur, int st){
	if(tcur > t) return oo;
	if(tcur == t && st == n-1) return 0;
	int &m = memo[tcur][st];
	if(m != -1) return m;
	int ans;
	ans = 1 + solve(tcur+1, st);
	for(int tr = 0; tr < m1; tr++){
		if(st == n-1) break;
		if(check(0, tcur, st, tr))
			ans = min(ans, solve(tcur+tme[st], st+1));
	}
	for(int tr = 0; tr < m2; tr++){
		if(st == 0) break;
		if(check(1, tcur, st, tr))
			ans = min(ans, solve(tcur+tme[st-1], st-1));
	}
	return m = ans;
}

int main(){
	int c = 0;
	while(42){
		scanf("%d", &n);
		if(n == 0) break;
		memset(memo, -1, sizeof(memo));
		scanf("%d", &t);
		acc[0] = 0;
		for(int i = 0; i < n-1; i++){
			scanf("%d", &tme[i]);
			acc[i+1] = acc[i] + tme[i];
		}
		scanf("%d", &m1);
		for(int i = 0; i < m1; i++)
			scanf("%d", &s1[i]);
		scanf("%d", &m2);
		for(int i = 0; i < m2; i++)
			scanf("%d", &s2[i]);
		printf("Case Number %d: ", ++c);
		int a = solve(0, 0);
		if(a >= oo)
			printf("impossible\n");
		else
			printf("%d\n", a);
	}
	return 0;
}
