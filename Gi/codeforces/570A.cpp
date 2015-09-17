//#include <bits/stdc++.h>
#include <cstdio>
#include <algorithm>
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

int v[105];

int main(){
	int n, m; 
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++){
		int win = -1, vot = 0;
		for(int j = 0; j < n; j++){
			int a; scanf("%d", &a);
			if(win == -1 || vot < a){ win = j; vot = a;}
		}
		v[win] += 1;
	}
	int win, vot;
	win = 0; vot = v[0];
	for(int i = 0; i < n; i++)
		if(vot < v[i]){ win = i; vot = v[i]; }
	printf("%d\n", win+1);
	return 0;
}
