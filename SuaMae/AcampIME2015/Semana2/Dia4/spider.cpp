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
inline int count_1s(int x) { return __builtin_popcount(x); }
inline int count_1s(ull x) { return __builtin_popcountll(x); }
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
#ifndef ONLINE_JUDGE
#	define debug(args...) fprintf(stderr, "%3d| ", __LINE__); fprintf(stderr, args); fprintf(stderr, "\n");
#else
#	define debug(args...)
#endif
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }

vector<int> v[1003];

int bridge(int sec, int v1, int v2) {
	auto it = upper_bound(v[sec].begin(), v[sec].end(), v1);
	auto it2 = lower_bound(v[sec].begin(), v[sec].end(), v2);
	int p1 = it-v[sec].begin();
	int p2 = it2-v[sec].begin()-1;
	if(p1 == v[sec].size()) return 0;
	if(p2 == -1 || p2 == v[sec].size()) return 0;
	return p2-p1+1;
}

int main() {
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; i++){
		int k;
		scanf("%d", &k);
		for(int j=0; j<k; j++){
			int a;
			scanf("%d", &a);
			v[i].pb(a);
		}
		sort(v[i].begin(), v[i].end());
	}
	int a=bridge(1, 1, 6);
	int resp=0;
	for(int i=0; i<n; i++){
		for(int j=v[i].size()-1; j>0; j--){
			int d1=v[i][j], d2=v[i][j-1];
			int sec=(i+1)%n, sec2=(i==0)?n-1:i-1;
			int n1, n2;
			n1=bridge(sec, d2, d1);
			n2=bridge(sec2, d2, d1);
			if(n1==n2) 
				continue;
			resp++;
		}
	}
	printf("%d\n", resp);
	return 0;
}