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


char M[10][10];

int main (){
	for(int a=0;a<8;a++){
		for(int b=0;b<8;b++){
			scanf(" %c", &M[a][b]);
		}
	}
	int resa,resb;
	resa=resb=10;
	for(int c=0;c<8;c++){
		int w=10, b=-1;
		for(int l=0;l<8;l++){
			if(M[l][c] == 'W' && w==10){
				w=l;
				if(b!=-1)
					w=11;
			}
			if(M[l][c]=='W' && b!=-1)
				b=-1;
			if(M[l][c]=='B')
				b=l;
		}
		resa=min(resa,w);
		resb=min(resb,7-b);
	}
	if(resa<=resb)
		printf("A\n");
	else
		printf("B\n");
	return 0;
}