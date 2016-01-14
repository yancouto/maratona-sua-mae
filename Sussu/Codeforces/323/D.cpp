#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define mp make_pair
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int INF = 0X3f3f3f3f;

int n, t, s[110], seq[110*110], mrk[310], ini[310], res, sobra[310], ant[310];

set <int> ss;

inline void resto(int val,int pos){
	for(int a=(pos%n)+1;a<n;a++){
		if(seq[a] == val){
			sobra[val]++;
		}
	}
}

int main (){
	scanf("%d%d", &n, &t);
	for(int a=0;a<n;a++){
		scanf("%d", &s[a]);
		mrk[s[a]]++;
		seq[a] = s[a];
		ss.insert(s[a]);
	}

	int tam = min(n*t,n*n);

	for(int a=n;a<tam;a++){
		seq[a] = seq[a%n];
	}

	memset(ini,INF,sizeof(ini));

	int v = *ss.begin(), cnt = 0, antv = 0;
	for(int a=0;!ss.empty() && a<tam;a++){
		if(seq[a] == v){
			ant[v] = ant[antv]+cnt;
			cnt = 0;
			antv = v;
			ini[v] = a;
			resto(v,a);
			ss.erase(v);
			res = max(res,v);
			v = *ss.begin();

		}
		if(seq[a] == antv){
			cnt++;
		}
	}
	sort(s,s+n);
	for(int a=0;a<n;a++){
		if(s[a] != s[a+1] || a==n-1){
			if(ini[s[a]] == INF) continue;
			res = max(res,ant[s[a]] + 1 + sobra[s[a]] + mrk[s[a]]*(t - (ini[s[a]]/n + 1)) + maior(s[a]));
		}
	}
	printf("%d", res);
}