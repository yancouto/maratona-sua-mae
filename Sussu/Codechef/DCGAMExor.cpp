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
 
#define gc getchar_unlocked
#define pc putchar_unlocked
inline void scan(int&x)
{
register int c = gc();
x = 0;	
int neg = 0;
for(;((c<48 || c>57) && c != '-');c = gc());
if(c=='-') {neg=1;c=gc();}
for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
if(neg) x=-x;
}

const int MAXN = 1000010;
 
int n, m, s[MAXN], maxi, nx[MAXN], bf[MAXN], cnt[MAXN*2], auxb[MAXN];

int sum[2*MAXN];
 
struct qry{
	char t, j;
	int k;
} q[MAXN];

int seti[MAXN*2];

stack <pii> pil;
 
 
bool cmp(int a,int b){
	return (s[a] != s[b] && s[a] > s[b]) || (s[a] == s[b] && a < b);
}
 
inline void upd(int i,int val){
	maxi = max(maxi, i+1);
	sum[i] ^= val;
}
 
inline int qry(int i){
	return sum[i];
}
 
inline char cont(char c){
	if(c == 'C')
		return 'D';
	return 'C';
}
 
int main (){
	scan(n);
	scan(m);
	for(int a=1;a<=n;a++)
		scan(s[a]);
	for(int a=0;a<m;a++){
		char c;
		q[a].t = gc();
		c = gc();
		scan(q[a].k);
		q[a].j = gc();
		c = gc();
	}

 
    for(int a = 1; a <= n; a++) 
    	seti[a-1] = s[a];
    for(int a = 0; a < m; a++) 
    	seti[a+n] = q[a].k;

    sort(seti, seti+n+m);
    int ig = unique(seti,seti+n+m) - seti;
    
    for(int i = 1; i <= n; i++) {
    	s[i] = lower_bound(seti,seti+ig,s[i]) - seti + 1;
    	auxb[i] = cnt[s[i]]++;
    }
    for(int i = 0; i < m; i++)
    	q[i].k = lower_bound(seti,seti+ig,q[i].k) - seti + 1;

    for(int a=1;a<=n;a++){
    	while(!pil.empty() && (pil.top().fst < s[a] || (pil.top().fst == s[a] && auxb[pil.top().snd] < auxb[a]))){
    		pii topo = pil.top();
    		nx[topo.snd] = a;
    		// printf("s[%d] %d nx s[%d] %d\n", topo.snd, topo.fst, a, s[a]);
    		pil.pop();
    	}
    	pil.push(pii(s[a], a));
    }
	while(!pil.empty()){
		pii topo = pil.top();
		nx[topo.snd] = n+1;
		// printf("s[%d] %d nx %d\n", topo.snd, topo.fst, n+1);
		pil.pop();
	}

	for(int a=n;a>0;a--){
    	while(!pil.empty() && (pil.top().fst < s[a] || (pil.top().fst == s[a] && auxb[pil.top().snd] < auxb[a]))){
    		pii topo = pil.top();
    		bf[topo.snd] = a;
    		// printf("s[%d] %d bf s[%d] %d\n", topo.snd, topo.fst, a, s[a]);
    		pil.pop();
    	}
    	pil.push(pii(s[a], a));
    }
	while(!pil.empty()){
		pii topo = pil.top();
		bf[topo.snd] = 0;
    	// printf("s[%d] %d bf 0\n", topo.snd, topo.fst);
		pil.pop();
	}

	for(int a=1;a<=n;a++){
		int val = s[a];
		int f, i;
		i = bf[a];
		f = nx[a];
		int cnt = ((a - i)&1)&((f - a));
		upd(val, cnt);
	}

	for(int a=1;a<=maxi;a++)
		sum[a] ^= sum[a-1];
	
	for(int a=0;a<m;a++){
		int kk = q[a].k;
		if(q[a].t == '<'){
			if(sum[kk-1])
				pc(q[a].j);
			else
				pc(cont(q[a].j));
		}
		else if(q[a].t == '>'){
			if(sum[maxi] ^ sum[kk])
				pc(q[a].j);
			else
				pc(cont(q[a].j));
		}
		else{
			if(sum[kk] ^ sum[kk-1])
				pc(q[a].j);
			else
				pc(cont(q[a].j));
		}
	}	
}