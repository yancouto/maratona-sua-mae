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

const int MAXN = 109;

struct even{
	int i, j, ind;

	even(){}
	even(int ii, int jj, int indd): i(ii), j(jj), ind(indd){}

	bool operator < (even other) const {
		return (j != other.j && j < other.j) || (j == other.j && ind < other.ind);
	}
} s[MAXN];

bool cmp(even a, even b){
	return a.i < b.i;
}

set <even> v;
int n;

int main (){
	scanf("%d", &n);
	for(int a=0;a<n;a++){
		scanf("%d %d", &s[a].i, &s[a].j);
		s[a].ind = a;
	}
	sort(s, s+n, cmp);
	int mrk[MAXN];
	int i = 0, j = 10000;
	while(i < j){
		memset(mrk, 0, sizeof(mrk));
		int m = (i+j+1)/2;
		int deg = 0;
		bool deu = 1;
		//printf("tenta com %d\n\n", m);
		for(int p=0;p<10001;p++){
			while(deg < n && s[deg].i == p){
				v.insert(s[deg]);
				//printf("insere %d %d %d\n", s[deg].i, s[deg].j, s[deg].ind);
				deg++;
			}
			if(!v.empty()){
				even top = *v.begin();
				//printf("topo %d %d %d  p %d\n", top.i, top.j, top.ind, p);
				if(top.j <= p){
					deu = 0;
					break;
				}
				mrk[top.ind]++;
				if(mrk[top.ind] >= m){
					//printf("dou erase em %d %d %d\n", top.i, top.j, top.ind);
					v.erase(top);
				}
			}
		}
		v.clear();

		if(deu)
			i = m;
		else
			j = m-1;
	}
	printf("%d\n", i*n);
}