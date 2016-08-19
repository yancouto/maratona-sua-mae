
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

const int MAXN = 512345;

int n, m;

vector <pii> s;

vector <pii> cs;

bool cmp(pii a, pii b){
	return (a.fst < b.fst || (a.fst == b.fst && a.snd >= b.snd));
}

int main (){
	for_tests(t, tt){
		scanf("%d%d", &n, &m);
		for(int a=0;a<m;a++){
			int i, j;
			scanf("%d %d", &i, &j);
			s.pb(pii(i, j));
		}
		sort(s.begin(), s.end(), cmp);
		for(int a=0;a<m;a++){
			if(a == 0 || s[a].fst != s[a-1].fst){
				cs.pb(s[a]);
			}
		}
		int ult = 1;
		int ans = 0;
		int i = 0;
		while(i < cs.size() && ult != n){
			//printf("ent\n");
			while(i+1 < cs.size() && cs[i+1].fst <= ult)
				i++;
			//printf("sai %d %d %d\n", i, ult, ans);
			ult = cs[i].snd;
			ans++;
			i++;
		}
		printf("%d\n", ans);
		if(tt != t-1) printf("\n");
		cs.clear();
		s.clear();
	}
}
