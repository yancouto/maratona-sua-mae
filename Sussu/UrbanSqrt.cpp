
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

const int MAXN = 30010, INF = 2000000000;

int n, m;

struct ares{
	int i, j, k, ind;
	
	bool operator < (ares other) const {
		return k < other.k;
	}
} ar[MAXN];

struct qry{
	int i, j;
	
	qry(){}
	qry(int ii, int jj){
		i = ii; j = jj;
	}
	bool operator < (qry other) const {
		if(i/sq != other.i/sq)
			return i/sq < other.i/sq;
		return j < other.j;
	}
};

vector <qry> q;

set <int> s;

map <int,int> ini;

void prec(int dif){
	for(int a=0;a<m;a++){
		q.pb(qry(ini[ar[a].k], ini[*(lower_bound(ar[a].k+dif)--)]));
	}
}

int main (){
	scanf("%d%d", &n, &m);
	for(int a=0;a<m;a++){
		scanf("%d%d%d", &ar[a].i, &ar[a].j, ar[a].k);
		ar[a].ind = a+1;
	}
	sort(ar, ar+m);
	s.insert(INF);
	for(int a=0;a<m;a++){
		if(s.find(ar[a].k) == s.end()){
			ini[ar[a].k] = a;
			s.insert(ar[a].k);
		}
	}
	int i = 0, j = ar[m-1].k - ar[0].k;
	while(i < j){
		int m = (i+j+1)/2;
		prec(m);
		
	}
}
