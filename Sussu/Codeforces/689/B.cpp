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

const int MAXN = 212345;

int n, s[MAXN], d[MAXN];

set<pii> q;


int main (){
	scanf("%d", &n);
	for(int a=1;a<=n;a++){
		scanf("%d", &s[a]);
		d[a] = INT_MAX;
	}
	d[0] = INT_MIN;
	d[1] = 0;
	q.insert(pii(0, 1));
	while(!q.empty()){
		pii t = *(q.begin());
		q.erase(t);
		int v = t.snd;
		if(d[v-1] > d[v] + 1){
			if(d[v-1] != INT_MIN)
				q.erase(pii(d[v-1], v-1));
			d[v-1] = d[v] + 1;
			q.insert(pii(d[v-1], v-1));
		}
		if(d[v+1] > d[v] + 1){
			if(d[v+1] != INT_MIN)
				q.erase(pii(d[v+1], v+1));
			d[v+1] = d[v] + 1;
			q.insert(pii(d[v+1], v+1));
		}
		if(d[s[v]] > d[v] + 1){
			if(d[s[v]] != INT_MIN)
				q.erase(pii(d[s[v]], s[v]));
			d[s[v]] = d[v] + 1;
			q.insert(pii(d[s[v]], s[v]));
		}
	}
	for(int a=1;a<=n;a++){
		printf("%d ", d[a]);
	}
}
