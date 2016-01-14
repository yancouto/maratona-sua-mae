#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define mp make_pair
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

int n, mrk[5][150], res, k;

char m[5][150];

bool valid(int i,int j){
	return (i>0 && j>0 && i<4 && m[i][j] == '.');
}

void go(int i,int j){
	mrk[i][j] = 1;
	if(res || j >= n){
		res = 1;
		return;
	}

	if(!valid(i,j+1))
		return;
	j++;
	for(int vi = -1;vi <= 1;vi++){
		if(valid(i+vi,j) && valid(i+vi,j+1) && valid(i+vi,j+2) && mrk[i+vi][j+2]==0){
			//printf("de %d %d - >  %d %d\n", i, j, i+vi, j+2);
			go(i+vi,j+2);
		}
	}
}

int main(){
	for_tests(t,tt){
		res=0;
		memset(mrk,0,sizeof(mrk));
		scanf("%d%d", &n, &k);
		int inii, inij;
		for(int b=1;b<=3;b++){
			for(int a=1;a<=n;a++){
				scanf(" %c", &m[b][a]);
				if(m[b][a] == 's'){
					inii = b;
					inij = a;
				}
			}
		}
		for(int b=1;b<=3;b++){
			for(int a=n+1;a<=n+10;a++){
				m[b][a] = '.';
			}
		}
		go(inii,inij);
		if(res)
			puts("YES");
		else
			puts("NO");		
	}
	
}