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

const int MAXN = 200010;

int n, m, q, pai[MAXN], sq, sz[MAXN], cnt;

int guarda;

struct ares{
	int i, j;
	int ind, r;
	bool operator < (ares other) const {
		if(i/sq != other.i/sq)
			return i/sq < other.i/sq;
		return j < other.j;
	}
} ar[MAXN], qry[MAXN];

stack <int> changes;

void join(int i, int j){
	if(sz[i] > sz[j])
		swap(i, j);
	pai[i] = j;
	sz[j] += sz[i];
	cnt--;
	if(guarda) changes.push(i);
}

inline int raiz(int v){
	while(pai[v] != v) v = pai[v];
	return v;
}

void brute(int *i, int j){
	while((*i) <= j){
		int ri = raiz(ar[(*i)].i), rj = raiz(ar[(*i)].j);
		if(ri != rj)
			join(ri, rj);
		(*i)++;
	}
}

void rollback(){
	while(!changes.empty()){
		int v = changes.top();
		changes.pop();
		sz[pai[v]] -= sz[v];
		pai[v] = v;
		cnt++;
	}
}

inline void prec(){
	for(int a=0;a<=n;a++){
		pai[a] = a;
		sz[a] = 1;
	}
	cnt = n;
}

inline int fimsq(int v){
	return (v/sq + 1)*sq - 1;
}

bool cmp(ares a, ares b){
	return a.ind < b.ind;
}

int main (){
	for_tests(t, tt){
		scanf("%d%d%d", &n, &m, &q);
		guarda = 0;
		sq = sqrt(q);
		prec();
		for(int a=1;a<=m;a++){
			scanf("%d%d", &ar[a].i, &ar[a].j);
		}
		for(int a=0;a<q;a++){
			scanf("%d%d", &qry[a].i, &qry[a].j);
			qry[a].ind = a;
		}
		sort(qry, qry+q);
		int i, j;
		for(int a=0;a<q;a++){
			int ii = qry[a].i, jj = qry[a].j;
			if(a == 0 || qry[a-1].i/sq != ii/sq){
				prec();
				j = (ii/sq + 1)*sq;
			}
			if(ii/sq == jj/sq){
				guarda = 1;
				brute(&ii, jj);
				qry[a].r = cnt;
				rollback();
			}
			else{
				guarda = 0;
				brute(&j, jj);
				guarda = 1;
				brute(&ii, fimsq(ii));
				qry[a].r = cnt;
				rollback();
			}
		}
		sort(qry, qry+q, cmp);
		for(int a=0;a<q;a++){
			printf("%d\n", qry[a].r);
		}
	}
} 
