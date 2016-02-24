#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 2*5010;

#define ADD 0
#define RMV 1

int n;

struct even{
	int i;
	int t;
	char g;
	even(){}
	even(char gg, int ii, int tt){
		g = gg;
		i = ii;
		t = tt;
	}
} s[MAXN];

bool cmp(even a, even b){
	return ((a.i !=  b.i && a.i < b.i) || (a.i == b.i && a.t < b.t));
}

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		char g; int i, j;
		scanf(" %c %d%d", &g, &i, &j);
		s[a*2] = even(g, i, ADD);
		s[a*2+1] = even(g, j, RMV);
	}
	sort(s, s+2*n, cmp);
	int nh, nm;
	nh = nm = 0;
	int res = 0;
	for(int a=0;a<2*n;a++){
		//printf("%d  %c %d\n", s[a].t, s[a].g, s[a].i);
		if(s[a].t == ADD){
			if(s[a].g == 'M')
				nh++;
			else
				nm++;
		}
		else{
			if(s[a].g == 'M')
				nh--;
			else
				nm--;
		}
		res = max(res, 2*min(nm, nh));
	}
	printf("%d", res);
}