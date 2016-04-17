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
 
int n, m, s[MAXN], pos[MAXN], maxi;

ll sum[2*MAXN];
 
struct qry{
	char t, j;
	int k;
} q[MAXN];
 
int seti[MAXN*2];
set <int> mai;
 
 
bool cmp(int a,int b){
	return s[a] > s[b];
}
 
inline void upd(int i,ll val){
	maxi = max(maxi, i+1);
	sum[i] += val;
	/*while(i < 2*MAXN-2){
		bit[i] = bit[i]^val;
		//printf("UPD %d %d val %d\n", i, bit[i], val);
		i += (i&-i);
	}*/
}
 
inline ll qry(int i){
	return sum[i];
	/*
	int ans = 0;
	while( i > 0 ){
		//printf("i %d %d\n", i, bit[i]);
		ans ^= bit[i];
		i -= (i&-i);
	}
	return ans;
	*/
}
 
inline char cont(char c){
	if(c == 'C')
		return 'D';
	else
		return 'C';
}
 
int main (){
	//scanf("%d%d", &n, &m);
	scan(n);
	scan(m);
	for(int a=1;a<=n;a++){
		// scanf("%d", &s[a]);
		scan(s[a]);
		//seti.pb(s[a]);
		pos[a] = a;
	}
	for(int a=0;a<m;a++){
		char c;
		q[a].t = gc();
		c = gc();
		scan(q[a].k);
		q[a].j = gc();
		c = gc();
		//scanf(" %c %d %c", &q[a].t, &q[a].k, &q[a].j);
		//seti.pb(q[a].k);
	}

 
    for(int a = 1; a <= n; a++) 
    	seti[a-1] = s[a];
    for(int a = 0; a < m; a++) 
    	seti[a+n] = q[a].k;

    sort(seti, seti+n+m);
    int ig = unique(seti,seti+n+m) - seti;
    
    for(int i = 1; i <= n; i++) {
    	//printf("%d vira ", s[i]);
    	s[i] = lower_bound(seti,seti+ig,s[i]) - seti + 1;
    	//printf("%d\n", s[i]);
    }
    for(int i = 0; i < m; i++){
    	//printf("%d vira ", q[i].k); 
    	q[i].k = lower_bound(seti,seti+ig,q[i].k) - seti + 1;
    	//printf("%d\n", q[i].k);
    }

	int cnt = 1;
	sort(pos+1, pos+n+1, cmp);
	mai.insert(0);
	mai.insert(n+1);
	for(int a=1;a<=n;a++){
		int val = s[pos[a]];
		int f, i;
		auto p = mai.lower_bound(pos[a]);
		f = *p;
		i = *(--p);
		mai.insert(pos[a]);
		//printf("%d %d\n", i, f);
		ll cnt = (pos[a] - i)*(f - pos[a]);
		//printf("cara %d de pos %d e ind %d tem range %d-%d %d-%d\n", pos[a], s[pos[a]], ind[s[pos[a]]], i, pos[a], pos[a], f);
		//printf("cnt %d => %d upd(%d, %d)\n ", cnt, cnt&1, val, cnt&1);
		upd(val, cnt);
	}

	for(int a=1;a<=maxi;a++)
		sum[a] += sum[a-1];
	
	for(int a=0;a<m;a++){
		int kk = q[a].k;
		if(q[a].t == '<'){
			//printf("< qry(%d -1)&1 %d\n", ind[q[a].k], qry(ind[q[a].k]-1));
			if(qry(kk-1)&1ll)
				pc(q[a].j);
			else
				pc(cont(q[a].j));
		}
		else if(q[a].t == '>'){
			//printf("> (qry(%d-5) %d ^ qry(%d-1) %d)&1\n", MAXN*2-5, qry(MAXN*2-5), ind[q[a].k], qry(ind[q[a].k]));
			if((qry(maxi) - qry(kk)&1ll))
				pc(q[a].j);
			else
				pc(cont(q[a].j));
		}
		else{
			//printf("= (qry(%d) %d ^ qry(%d-1) %d)&1\n", ind[q[a].k], qry(ind[q[a].k]), ind[q[a].k], qry(ind[q[a].k]-1));
			if((qry(kk) - qry(kk-1))&1ll)
				pc(q[a].j);
			else
				pc(cont(q[a].j));
		}
	}	
	//printf("\n");
}