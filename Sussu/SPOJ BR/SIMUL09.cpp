
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

int n, m;

struct qry{
	ll i, j;
	qry(ll ii, ll jj){
		i = ii;
		j = jj;
	}
	qry(){}
};

vector <qry> s;

vector <qry> ind;

inline ll inv(ll v,qry l){
	return l.j - (v - l.i);
}

int main (){
	scanf("%d%d", &n, &m);

	for(int a=0;a<m;a++){
		char t;
		ll i, j;
		scanf(" %c %lld %lld", &t, &i, &j);
		if(t == 'I')
			s.pb(qry(i, j));
		else{
			ind.clear();
			ind.pb(qry(i, j));
			for(int a = s.size()-1;a>=0;a--){
				qry q = s[a];
				int tam = ind.size();
				for(int b = 0;b<tam;b++){
					qry lim = ind[b];
					if((lim.i <= q.i && lim.j >= q.j) || q.i > lim.j || q.j < lim.i)
						continue;
					if(lim.i > q.i && lim.j < q.j){
						ll ii = inv(lim.j, q);
						ll jj = inv(lim.i, q);
						ind[b] = qry(ii, jj);
					}
					else if(lim.i <= q.i){
						ll ii = inv(lim.j, q);
						ll jj = inv(q.i, q);
						ind[b] = qry(ii, jj);
						if(q.i == lim.i) continue;
						ind.pb(qry(lim.i, q.i-1));
					}
					else if(lim.i > q.i){
						ll ii = inv(q.j, q);
						ll jj = inv(lim.i, q);
						ind[b] = qry(ii, jj);
						if(q.j == lim.j) continue;
						ind.pb(qry(q.j+1, lim.j));
					}
				}
			}
			ll res = 0;
			for(qry i: ind){
				//printf("%d %d\n", i.i, i.j);
				res += ((i.i + i.j)*(i.j - i.i + 1))/2;
			}
			printf("%lld\n", res);
		}
	}
}
