
#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(te, tt) int te; scanf("%d", &te); for(int tt = 1; tt <= te; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

const int MAXN = 502;

int n, s[MAXN], sum[MAXN], rsum[MAXN], dp[MAXN*MAXN*2+10][MAXN], t[MAXN*MAXN*2+10][MAXN], t2[MAXN*MAXN*2+10][MAXN];

int testno = 0;
int zer, res;

inline int readInt () {
	bool minus = false;
	int result = 0;
	char ch;
	ch = getchar();
	while (true) {
		if (ch == '-') break;
		if (ch >= '0' && ch <= '9') break;
		ch = getchar();
	}
	if (ch == '-') minus = true; else result = ch-'0';
	while (true) {
		ch = getchar();
		if (ch < '0' || ch > '9') break;
		result = result*10 + (ch - '0');
	}
	if (minus)
		return -result;
	else
		return result;
}


void go(int v, int k){
	if(k == n){
		res = min(res, abs(zer-v));
		return ;
	}
	if(t2[v][k] != testno){
		t2[v+s[k]][k] = testno;
		dp[v+s[k]][k+1] = 1;
		go(v+s[k], k+1);
		t2[v-s[k]][k] = testno;
		dp[v-s[k]][k+1] = 1;
		go(v-s[k], k+1);
	}
	return dp[i][k];
}

int main (){
	for_tests(te, tt){
		n = readInt();
		sum[0] = 0;
		for(int a=0;a<2*n+1;a++){
			char d;
			if(a&1)
				d=getchar();
			else{
				s[a/2] = readInt();
				sum[a/2] = s[a/2];
				if((a/2) != 0)
					sum[a/2] += sum[(a/2)-1];
			}
		}
		n++;
		rsum[n] = 0;
		for(int a=n-1;a>=0;a--){
			rsum[a] = rsum[a+1] + s[a];
		}
		zer = sum[n-1] +10;
		res = INT_MAX;
		//printf("\nZER %d\n", zer);
		dp[zer][0] = 1; 
		t[zer][0] = 0;
		t2[zer][0] = tt;
		go(zer, 0);
		printf("%d\n", res);
	}
}
