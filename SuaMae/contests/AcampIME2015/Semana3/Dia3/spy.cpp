#include <bits/stdc++.h>
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
#ifndef ONLINE_JUDGE
#	define debug(args...) {fprintf(stderr, "%3d| ", __LINE__); fprintf(stderr, args); fprintf(stderr, "\n");}
#else
#	define debug(args...) {}
#endif
const int inf = 1000000007;
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }

int n, T, sum, nt;
int t[55], acc[55], dir[110], ini[110]; 
int memo[52][209];

bool check(int st, int x, int d) {
	if(d)
		return x == (sum - ((st == 0)?0:acc[st-1]));
	return x == ((st == 0)?0:acc[st-1]);
}

int prep[110][250];
void prec() {
	for(int i = 0; i < nt+3; i++)
		for(int j = 0; j < 205; j++)
			prep[i][j] = -1;
	for(int i = 0; i < nt; i++) {
		int s = ini[i];
		if(s > T) continue;
		if(dir[i]) {
			int i1 = n-1, i2 = 0;
			while(42){
				for(int st = i1; st > 0; st--) {
					prep[i][s] = st;
					s += t[st-1];
					if(s > T) break;
				}
				if(s > T) break;
				for(int st = i2; st < n-1; st++) {
					prep[i][s] = st;
					s += t[st];
					if(s > T) break;
				}
				if(s > T) break;
				i1 = n-1;
			}
		} else {
			int i1 = 0, i2 = n-2;
			while(42) {
				for(int st = i1; st < n; st++) {
					prep[i][s] = st;
					s += t[st];
					if(s > T) break;
				}
				if(s > T) break;
				for(int st = i2; st > 0; st--) {
					prep[i][s] = st;
					s += t[st-1];
					if(s > T) break;
				}
				if(s > T) break;
				i1 = 0;
			}
		}

	}
}

//int solve(int st, int tme) {
//	if(tme > T) return inf;
//	if(st == n-1 && tme == T) return 0;
//	int &m = memo[st][tme];
//	if(m != -1) return m;
//	int ans = inf, d;
//	for(int i = 0; i < nt; i++) {
//		if(tme - ini[i] < 0) continue;
//		if(((tme-ini[i])/sum) % 2) d = !dir[i];
//		else d = dir[i];
//		if(check(st, (tme-ini[i])%sum, d)) {
//			if(st == 0) d = 0;
//			else if(st == n-1) d = 1;
//			ans = min(ans, solve(st + (d?-1:1), tme + (d?t[st-1]:t[st])));
//		}
//	}
//	ans = min(ans, 1 + solve(st, tme+1));
//	return m = ans;
//}

int solve(int st, int tme) {
	if(tme > T) return inf;
	if(st == n-1 && tme == T) return 0;
	int &m = memo[st][tme];
	if(m != -1) return m;
	int ans = inf, d;
	for(int i = 0; i < nt; i++) {
		if(prep[i][tme] != st) continue;
		if(st == 0) d = 0;
		else if(st == n-1) d = 1;
		else if(((tme-ini[i])/sum) % 2) d = !dir[i];
		else d = dir[i];
		ans = min(ans, solve(st + (d?-1:1), tme + (d?t[st-1]:t[st])));	
	}
	ans = min(ans, 1 + solve(st, tme+1));
	return m = ans;
}
int main() {
	int cc = 0;
	while(42) {
		scanf("%d", &n);
		if(n == 0) break;
		scanf("%d", &T);
		for(int i = 0; i < n+4; i++)
			for(int j = 0; j < T+4; j++)
				memo[i][j] = -1;

		sum = 0;
		for(int i = 0; i < n-1; i++) {
			scanf("%d", &t[i]);
			sum += t[i];
			acc[i] = sum;
		}
		int a; 
		nt = 0; scanf("%d", &a);
		for(int i = 0; i < a; i++) {
			scanf("%d", &ini[i]);
			dir[i] = 0;
		}
		nt += a; scanf("%d", &a);
		for(int i = 0; i < a; i++) {
			scanf("%d", &ini[i+nt]);
			dir[i+nt] = 1;
		}
		nt += a;
		t[nt-1] = t[nt] = 0;
		prec();
		int ans = solve(0, 0);
		printf("Case Number %d: ", ++cc);
		if(ans == inf)
			puts("impossible");
		else
			printf("%d\n", ans);
	}
	return 0;
}
