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

const int MAXN = 2010, DEZ = 100000000;

int n, h, x[MAXN], esq[MAXN], dir[MAXN], proxe[MAXN], proxd[MAXN];

double p, dp[MAXN][MAXN][2][2];

inline int ant(int i, int ac){
	if(!ac){
		if(x[i]-h>=x[i-1])
			return h;
		else
			return x[i]-x[i-1];
	}
	else{
		if(x[i]-h>=x[i-1]+h)
			return h;
		else 
			return x[i-1]+h-x[i];
	}
}

inline int nxt(int i,int ac){
	if(!ac){
		if(x[i]+h<=x[i+1]-h)
			return h;
		else
			return x[i+1]-h - x[i];
	}
	else{
		if(x[i]+h <= x[i+1])
			return h;
		else
			return x[i+1]-x[i];
	}
}

inline int analisae(int i,int f, int l,int r){
	if(proxe[i]>f)
		return x[f]-x[i] + nxt(f,r); /*falta adicionar o h */
	else
		return (esq[i]-x[i]);
}

inline int analisad(int i,int f, int l,int r){
	if(i>proxd[f])
		return x[f]-x[i] + ant(i,l); /* falta adicionar o h */
	else 
		return (x[f]-dir[f]);
}

double go(int i,int f,int l,int r){
	if(i>f) return 0;
	if(dp[i][f][l][r] == -1){
		double *ans = &dp[i][f][l][r];
		*ans = 0.0;
		*ans += 0.5*(p*(go(i+1,f,0,r)+ant(i,l)  +  go(i,proxd[f],l,0)+analisad(i,f,l,r)) + (1-p)*(go(proxe[i],f,1,r)+analisae(i,f,l,r)  +  go(i,f-1,l,1)+nxt(f,r)));
	}
	return dp[i][f][l][r];
}

int main (){

	scanf("%d %d %lf", &n, &h, &p);

	for(int a=0;a<=n+1;a++){
		for(int b=0;b<=n+1;b++){
			for(int c=0;c<2;c++){
				for(int d=0;d<2;d++){
					dp[a][b][c][d] = -1.0;
				}
			}
		}
	}
	for(int a=1;a<=n;a++)
		scanf("%d", &x[a]);
	x[0] = -2*DEZ - 10;
	x[n+1] = 2*DEZ + 10; 
	sort(&x[1],&x[n+1]);
	for(int a=n;a>0;a--){
		if(h+x[a] > x[a+1]){
			proxe[a] = proxe[a+1];
			esq[a] = esq[a+1];
		}
		else{
			proxe[a] = a+1;
			esq[a] = x[a]+h;
		}
	}
	for(int a=1;a<=n;a++){
		if(x[a]-h < x[a-1]){
			proxd[a] = proxd[a-1];
			dir[a] = dir[a-1];
		}
		else{
			proxd[a] = a-1;
			dir[a] = x[a]-h;
		}
	}
	printf("%.15f\n", go(1,n,0,1));
	return 0;
}