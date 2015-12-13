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

const int MAXN = 100010, INF = 0x3f3f3f3f;

int n, m, deg, s[MAXN];

struct pilha{
	int v, i;
} p[MAXN];

inline void bota(int v,int i){
	p[deg].v = v;
	p[deg++].i = i;
}

inline int bb(int i,int f,int v){
	while(i<f){
		int m = (i+f)/2;
		if(p[m].v < v)
			i = m+1;
		else
			f = m;
	}
	if(i == f && p[i].v<v) i++;
	return i;
}

int main(){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
		if(deg==0){
			bota(s[a],a);
		}
		else{
			int i = bb(0,deg-1,s[a]);
			p[i].v = s[a];
			p[i].i - a;
			if(i==deg) deg++;
		}
	}
	printf("%d\n", n-deg);
	return 0;
}