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

int n, p[MAXN], deg[MAXN], mrk[MAXN];

queue<int> q;

vector<int> r;

int main (){
	scanf("%d", &n);
	for(int a=1;a<=n;a++){
		scanf("%d", &p[a]);
		if(p[a] != a)
			deg[p[a]]++;
		else
			r.pb(a);
	}
	int res = 0;
	for(int a=1;a<=n;a++){
		if(deg[a] == 0){
			q.push(a);
		}
	}
	while(!q.empty()){
		int top = q.front();
		mrk[top] = 1;
		q.pop();
		deg[p[top]]--;
		if(deg[p[top]] == 0)
			q.push(p[top]);
	}
	int raiz;
	if(r.size() == 0){
		for(int a=1;a<=n;a++){
			if(mrk[a] == 0){
				raiz = a;
				break;
			}
		}
		res++;
		deg[p[raiz]]--;
		if(deg[p[raiz]] == 0)
			q.push(p[raiz]);
		p[raiz] = raiz;
		r.pb(raiz);
	}
	raiz = r[0];

	while(!q.empty()){
		int top = q.front();
		mrk[top] = 1;
		q.pop();
		deg[p[top]]--;
		if(deg[p[top]] == 0)
			q.push(p[top]);
	}
	for(int a=1;a<=n;a++){
		if(!mrk[a]){
			res++;
			deg[p[a]]--;
			if(deg[p[a]] == 0)
				q.push(p[a]);
			p[a] = raiz;
		}
		while(!q.empty()){
			int top = q.front();
			mrk[top] = 1;
			q.pop();
			deg[p[top]]--;
			if(deg[p[top]] == 0)
				q.push(p[top]);
		}
	}
	for(int rz: r){
		if(rz == raiz) continue;
		res++;
		p[rz] = raiz;
	}
	printf("%d\n", res);
	for(int a=1;a<=n;a++){

		printf("%d ", p[a]);
	}
	printf("\n");
}
