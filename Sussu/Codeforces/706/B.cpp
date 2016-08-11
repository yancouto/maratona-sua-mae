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

const int MAXN = 112345;

int n, m;
int s[MAXN];

int bb(int i, int j, int v){
	while(i < j){
		int m = (i+j+1)/2;
		if(s[m] <= v)
			i = m;
		else
			j = m-1;
	}
	return i;
}

int main (){
	int i, j;
	scanf("%d", &n);
	s[0] = INT_MIN;
	for(int a=1;a<=n;a++){
		scanf("%d", &s[a]);
	}
	sort(s, s+n+1);
	scanf("%d", &m);
	for(int a=0;a<m;a++){
		int v;
		scanf("%d", &v);
		printf("%d\n", bb(0, n, v));
	}
}
