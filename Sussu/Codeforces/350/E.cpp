
#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<char, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 512345;
int n, m , k;


int nxt[MAXN], prev[MAXN];
int lig[MAXN];

char s[MAXN];

int main (){
	scanf("%d%d%d", &n, &m, &k);
	stack<int> q;
	for(int a=1;a<=n;a++){
		scanf(" %c", &s[a]);
		nxt[a] = a+1;
		prev[a] = a-1;
		if(s[a] == '(')
			q.push(a);
		else{
			int t = q.top();
			lig[t] = a;
			lig[a] = t;
			q.pop();
		}
	}
	nxt[0] = 1;
	prev[n+1] = n;
	int i = k;
	for(int a=0;a<m;a++){
		char c;
	//	printf("i %d\n", i);
		scanf(" %c", &c);
		if(c == 'L'){
			i = prev[i];
		}
		else if(c == 'R'){
			i = nxt[i];
		}
		else{
			if(s[i] == '('){
				//printf("nxt[%d] = %d\n", prev[i], prev[lig[i]]);
				//printf("prev[%d] = %d\n", nxt[lig[i]], prev[i]);
				nxt[prev[i]] = nxt[lig[i]];
				prev[nxt[lig[i]]] = prev[i];
				if(nxt[prev[i]] != n+1)
					i = nxt[prev[i]];
				else
					i = prev[i];
			}
			else{
				//printf("pref[%d] = %d\n", nxt[i], prev[lig[i]]);
				//printf("nxt[%d] = %d\n", prev[lig[i]], nxt[i]);
				prev[nxt[i]] = prev[lig[i]];
				nxt[prev[lig[i]]] = nxt[i];
				if(nxt[i] != n+1)
					i = nxt[i];
				else
					i = prev[lig[i]];
			}
		}
	}
	for(int a=0;a<=n;){
		//printf("to em %d vou para %d volto de %d\n", a, nxt[a], prev[a]);
		if(a != 0) printf("%c", s[a]);
		a = nxt[a];
	}
}
