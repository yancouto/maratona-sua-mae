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

struct Edge{
	int v;
	string s;
};

struct No{
	int v, d;
	No(){}
	No(int v, int d) : v(v), d(d){}
	bool operator < (const No &e) const{
		return d > e.d;
	}
};

vector<int> g1[1005], g2[1005];
int n1, n2, p1, p2, m1, m2;
Edge ed[10005], ed2[100005];
int seen1[10005], seen2[10005];
map<string, int> mp;
int bfs(int o, int o2, int d, int d2){
	queue<No> q, q2;
	q.push(No(o, 0));
	q2.push(No(o, 0));
	while(!q.empty() && !q2.empty()){
		No no, no2;
		no = q.front(); no2 = q2.front();
		q.pop(); q2.pop();
		if(no.v == d && no2.v == d2) return no.d;
		for(int i = 0; i < g1[no.v].size(); i++){
			int x = g1[no.v][i];
			map<string, int>::iterator it;
			it = mp.find(ed[x].s);
			if(it == mp.end()) continue;
			int y =	it->snd; 
			if(ed[x].s.compare(ed2[y].s) == 0){
				if(seen1[x] || seen2[y]) continue;
				seen1[x] = seen2[y] = 1;
				q.push(No(ed[x].v, no.d+1));
				q2.push(No(ed2[y].v, no2.d+1));
			}	
		}
	}
	return -1;
}

int main(){
	int t; scanf("%d", &t);
	while(t--){
		memset(seen1, 0, sizeof seen1);
		memset(seen2, 0, sizeof seen2);
		scanf("%d %d %d", &n1, &p1, &m1);
		for(int i = 0; i < m1; i++){
			char s[10]; int u;
			scanf("%d %s %d", &u, s, &ed[i].v);
			int j; for(j = 0; s[j] != '\0'; j++);
			ed[i].s = string(s, s+j);
			g1[u].pb(i);
		}
		scanf("%d %d %d", &n2, &p2, &m2);
		for(int i = 0; i < m2; i++){
			char s[10]; int u;
			scanf("%d %s %d", &u, s, &ed2[i].v);
			int j; for(j = 0; s[j] != '\0'; j++);
			ed2[i].s = string(s, s+j);
			mp[ed2[i].s] = i;
			g2[u].pb(i);
		}
		printf("%d\n",bfs(0,0,p1,p2));
		if(t) printf("\n");		
	}
	return 0;
}
