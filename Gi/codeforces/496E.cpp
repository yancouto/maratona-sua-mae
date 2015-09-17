#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef pair<int, int> pii;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ull modn = 1000000007;
inline ull mod(ull x) { return x % modn; }

struct Play{
	int c, d;
};

struct Actor{
	int	a, b, q; 
};

map<int, int> compress;
vector<int> sta[400010], stp[400010];
Play p[100010];
Actor act[100010];
int ans[100010];

int main(){
	int n, m;

	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d %d", &p[i].c, &p[i].d);
		compress[p[i].c] = 0;
		compress[p[i].d] = 0;
	}

	scanf("%d", &m);
	for(int i = 0; i < m; i++){
		scanf("%d %d %d", &act[i].a, &act[i].b, &act[i].q);
		compress[act[i].a] = 0;
		compress[act[i].b] = 0;
	}

	int c = 0;
	for(map<int, int> :: iterator it = compress.begin(); it != compress.end(); ++it)
		it->snd = c++;	

	for(int i = 0; i < n; i++){
		p[i].c = compress[p[i].c];
		p[i].d = compress[p[i].d];
		stp[p[i].c].pb(i);
	}

	for(int i = 0; i < m; i++){
		act[i].a = compress[act[i].a];
		act[i].b = compress[act[i].b];
		sta[act[i].a].pb(i);
	}
	
	multimap< int, pii > mmp;
	for(int i = 0; i < compress.size(); i++){
		while(!mmp.empty() && mmp.begin()->fst < i) mmp.erase(mmp.begin());
		for(int j = 0; j < sta[i].size(); j++){
			int who = sta[i][j];
		//	printf("Inserindo ator %d com comeco %d final %d e qtd %d\n", who, act[who].a, act[who].b, act[who].q);
			mmp.insert(make_pair(act[who].b, make_pair(who, act[who].q)));
		}
		for(int j = 0; j < stp[i].size(); j++){
			int who = stp[i][j];
			multimap< int, pii > :: iterator it;
			it = mmp.lower_bound(p[who].d);
		//	printf("Procurando peça %d - (%d, %d)\n", who, p[who].c, p[who].d);
			if(it == mmp.end()) { puts("NO"); return 0; }
			it->snd.snd--;
			ans[who] = (it->snd.fst) + 1;
			if(it->snd.snd == 0) mmp.erase(it);
		}
 	}

	printf("YES\n");
	for(int i = 0; i < n; i++)
		printf("%d ", ans[i]);
	printf("\n");
	return 0;
}
