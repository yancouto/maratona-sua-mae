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

const int MAXN = 1010;

int n, m, ent[10], deg;
char lin[1000100];

ll f[10010010], bit[MAXN][MAXN], M[MAXN][MAXN];


void pre() {
	f[0] = 1;
	for(int i = 1; i < 10010006; i++)
		f[i] = mod(f[i - 1] * i);
}

void le(){
	int cnt = 0;
	int num = 0;
	while(1){
		//if(lin[cnt] == ' ' && lin[cnt+1] == ' ') break;
		if(lin[cnt] == '\0') break;
		while(lin[cnt] == ' ') cnt++;
		//printf("'%c' %d %d\n", lin[cnt], lin[cnt], cnt);
		num *= 10;
		num += lin[cnt]-'0';
		cnt++;
		if(lin[cnt] == ' ' || lin[cnt] == '\0'){
			//printf("ent[%d] = %d\n", deg, num);
			ent[deg++] = num;
			num = 0;
		}
	}
}

void updy(int x, int y, ll val){
	while( y < MAXN-3 ){
		bit[x][y] += val;
		y += (y&-y);
	}
}

void upd(int x, int y, ll val){
	while( x < MAXN-3 ){
		updy(x, y, val);
		x += (x&-x);
	}
}

ll qryy(int x, int y){
	ll ans = 0;
	while(y > 0){
		ans += bit[x][y];
		y -= (y&-y);
	}
	return ans;
}

ll qry(int x, int y){
	ll ans = 0;
	while( x > 0 ){
		ans += qryy(x, y);
		x -= (x&-x);
	}
	return ans;
}

ll expo(ll base, ll e){
	if(e == 0) return 1;
	ll ans = expo(base, e/2);
	ans = mod(ans*ans);
	if(e&1) ans = mod(ans*base);
	return ans;
}

ll fat(int v){
	return f[v];
}

ll calc(int nn, int kk){
	return mod(mod(fat(nn+kk-1)*expo(fat(kk), modn-2))*expo(fat(nn-1), modn-2));
}

int main (){
	pre();
	int test = 0;
	scanf("%d%d", &n, &m);
	while(scanf(" %[^\n]", lin)!= EOF){
		deg = 0;
		//fgets(lin, 50, stdin);
		le();
		if(deg == 3){
			upd(ent[0], ent[1], ent[2]);
			M[ent[0]][ent[1]] += ent[2];
		}
		else if(deg == 2){
			upd(ent[0], ent[1], -M[ent[0]][ent[1]]);
			M[ent[0]][ent[1]] = 0;
		}
		else{
			int nn = qry(ent[2], ent[3]) + qry(ent[0]-1, ent[1]-1) - qry(ent[2], ent[1]-1) - qry(ent[0]-1, ent[3]);
			//printf("qry(%d, %d) %d + qry(%d, %d) %d - qry(%d, %d) %d - qry(%d, %d) %d\n", ent[2], ent[3], qry(ent[2], ent[3]), ent[0]-1, ent[1]-1, qry(ent[0]-1, ent[1]-1), 
			//	ent[2], ent[1]-1, qry(ent[2], ent[1]-1), ent[0]-1, ent[3], qry(ent[0]-1, ent[3]));
			int kk = ent[4];
			//printf("Day: n bonecos %d n cenouras %d\n", nn, kk);
			printf("Day #%d: %lld\n", ++test, calc(nn, kk));
		}
	}
}