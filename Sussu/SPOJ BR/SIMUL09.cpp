
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
	int i, j;
	qry(int ii, int jj){
		i = ii;
		j = jj;
	}
	qry(){}
};

vector <qry> s;

int main (){
	scanf("%d%d", &n, &m);

	for(int a=0;a<m;a++){
		char t;
		int i, j;
		scanf(" %c %d %d", &t, &i, &j);
		if(t == 'I')
			s.pb(qry(i, j));
		else{
			vector <qry>
			int tam = s.size()-1;
			for(int a = tam;a>=0;a--){

			}
		}
	}
}
