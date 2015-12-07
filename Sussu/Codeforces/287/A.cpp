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

char m[5][5]; 
int n[5][5];

bool valid(int i,int j){
	return (i<4 && j<4 && i>=0 && j>=0);
}

int main (){
	int res = 0;
	for(int a=0;a<4;a++){
		for(int b=0;b<4;b++){
			scanf(" %c", &m[a][b]);
			if(m[a][b]=='#')
				n[a][b]=1;
			else
				n[a][b]=0;
		}
	}
	for(int a=0;a<4;a++){
		for(int b=0;b<4;b++){
			if(valid(a+1,b+1) && (n[a][b]+n[a+1][b]+n[a][b+1]+n[a+1][b+1]==1 || n[a][b]+n[a+1][b]+n[a][b+1]+n[a+1][b+1]==3 || n[a][b]+n[a+1][b]+n[a][b+1]+n[a+1][b+1]==0 || n[a][b]+n[a+1][b]+n[a][b+1]+n[a+1][b+1]==4)){
				res=1;
				break;
			}
		}
		if(res) break;
	}
	if(res)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}