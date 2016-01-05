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

int n, npod['z'+10]['z'+10], mrk['z'+10];

vector<int> adj['z'+10], rev['z'+10];

stack<int> s;

queue<int> res;

void dfs(int v){
	mrk[v] = 1;
	for(int a = 0;a<adj[v].size();a++){
		int nxt = adj[v][a];
		if(mrk[nxt]) continue;
		dfs(nxt);
	}
	s.push(v);
}

void go(int v){
	mrk[v] = 2;
	if(res.size() == 1) res.clear();
	else return;
	res.push(v);
	for(int a = 0;a<rev[v].size();a++){
		int nxt = rev[v][a];
		if(mrk[nxt] == 2) continue;
		res.push(nxt);
		go(nxt);
	}
}

int main (){
	printf("z - %d\n", 'z');
	for_tests(t,tt){
		scanf("%d", &n);

		for(int a = 'a';a<='z';a++){
			mrk[a] = 0;
			for(int b = 'a';b<='z';b++){
				npod[a][b] = 0;
			}
		}

		for(int a=0;a<n;a++){
			char c1, c2;
			scanf(" %c%c", &c1, &c2);
			npod[c1][c2] = 1;
		}
		are.clear();	
		for(int a = 'a';a<='z';a++){
			for(int b = 'a';b<='z';b++){
				if(!npod[a][b]){
					are[a].pb(b);
					rev[b].pb(a);
				}
			}
		}
		for(int a = 'a';a<='z';a++){
			if(mrk[a] == 0)
				dfs(a);
		}
		while(!s.empty()){
			int v = s.front();
			s.pop();
			go(v);
		}
	}
}