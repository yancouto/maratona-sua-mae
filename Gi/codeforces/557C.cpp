//#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
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

int n;
int d[100005];
int maskd[210];

struct Leg{
	int l, d;
};

bool myfunction(Leg a, Leg b){
	return a.l < b.l;
}

Leg info[100005];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &info[i].l);
	for(int i = 0; i < n; i++)
		scanf("%d", &info[i].d);
	sort(info, info+n, myfunction);
	d[0] = info[0].d;
	for(int i = 1; i < n; i++)
		d[i] = d[i-1] + info[i].d;
	int ans = 1000000000;
	for(int i = 0; i < n;){
		int value = info[i].l;
		int j;
		for(j = i+1; info[j].l == value && j < n; j++);
		int cost = d[n-1]-d[j-1];	
		int need = j - (j-i-1)*2 -1;
		for(int k = 1; k <= 200 && need > 0; k++){
			cost += k*min(maskd[k], need);	
			need -= min(maskd[k], need);
		}
		ans = min(ans, cost);
		for(j = i; info[j].l == value && j < n; j++)
			maskd[info[j].d]++;
		i = j;
	}
	printf("%d\n", ans);
	return 0;
}
