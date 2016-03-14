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

int n, m, ent[10], deg, bit[MAXN][MAXN], M[MAXN][MAXN];
char lin[10000];

void le(){
	int cnt = 0;
	int num = 0;
	while(1){
		if(lin[cnt] == ' ' && lin[cnt+1] == ' ') break;
		printf("'%c' %d\n", lin[cnt], cnt);
		if(lin[cnt] == ' '){
			cnt++;
			continue;
		}
		num *= 10;
		num += lin[cnt]-'0';
		cnt++;
		if(lin[cnt] == ' ' || lin[cnt] == '\n'){
			ent[deg++] = num;
			num = 0;
		}
	}
}

void updy(int x, int y, int val){
	while( y < MAXN ){
		bit[x][y] += val;
		y += (y&-y);
	}
}

void upd(int x, int y, int val){
	while( x < MAXN ){
		updy(x, y, val);
		x += (x&-x);
	}
}

int qryy(int x, int y){
	int ans = 0;
	while(y > 0){
		ans += bit[x][y];
		y -= (y&-y);
	}
}

int qry(int x, int y){
	int ans = 0;
	while( x > 0 ){
		ans += qryy(x, y);
		x -= (x&-x);
	}
}

int main (){
	scanf("%d%d", &n, &m);
	while(1){
		deg = 0;
		scanf("\n");
		//fgets(lin, 50, stdin);
		scanf(" %[^\n]", lin);
		printf("'%s'\n", lin);
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
			int kk = ent[4];
			printf("Day: n bonecos %d n cenouras %d\n", nn, kk);
		}
	}
}