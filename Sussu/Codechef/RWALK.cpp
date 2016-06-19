#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(te, tt) int te; scanf("%lld", &te); for(int tt = 1; tt <= 2*te; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#define int ll
const int MAXN = 512;

int n, s[MAXN], s2[MAXN], sum[MAXN], rsum[MAXN], dp[MAXN*MAXN*2+10][2], t[MAXN*MAXN*2+10][2], t2[MAXN*MAXN*2+10][2];

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

 main (){
	for_tests(te, tt){
		n = readInt();
		int deg1, deg2;
		deg1 = deg2 = 0;
		sum[0] = 0;
		for(int a=0;a<2*n+1;a++){
			char d;
			if(a&1)
				d=getchar();
			else{
				if((a/2)&1)
					s[deg1++] = readInt();
				else
					s2[deg2++] = readInt();
			}
		}
		if(n <= 2){
			puts("NO");
			continue;
		}
		n = deg1;
		rsum[n] = 0;
		for(int a=0;a<n;a++){
			if(a != 0)
				sum[a] = sum[a-1];
			sum[a] += s[a];
		}
		for(int a=n-1;a>=0;a--){
			rsum[a] = rsum[a+1] + s[a];
		}
		int zer = sum[n-1] +10;
		int res = INT_MAX;
		//printf("\nZER %lld\n", zer);
		dp[zer][0] = 1; 
		t[zer][0] = 0;
		t2[zer][0] = tt;
		for(int i=0;i<n;i++){
			for(int j = max(zer-(sum[i]+2),zer-rsum[i]-2);j<= min(zer+sum[i]+2, zer+rsum[i]+2);j++){
				if(t2[j][i&1] != tt){
					t2[j][i&1] = tt;
					t[j][i&1] = -1;
				}
				if(t[j][i&1] != i){
					dp[j][i&1] = 0;
					t[j][i&1] = i;
				}
				if(dp[j][i&1] == 1){
					//printf("boto em %lld %d e ", j+s[i], (i+1)&1);
					//printf("boto em %lld %d\n", j-s[i], (i+1)&1);
					dp[j+s[i]][(i+1)&1] = 1;
					t[j+s[i]][(i+1)&1] = i+1;
					t2[j+s[i]][(i+1)&1] = tt;
					dp[j-s[i]][(i+1)&1] = 1;
					t[j-s[i]][(i+1)&1] = i+1;
					t2[j-s[i]][(i+1)&1] = tt;
					if(i+1 == n){
						res = min(res, abs(zer - j - s[i]));
						res = min(res, abs(zer-(j-s[i])));
					}
				}
			}
		}
		int ans = res;
		tt++;
		n = deg2;
		rsum[n] = 0;
		for(int a=0;a<n;a++){
			s[a] = s2[a];
			if(a != 0)
				sum[a] = sum[a-1];
			sum[a] += s[a];
		}
		for(int a=n-1;a>=0;a--){
			rsum[a] = rsum[a+1] + s[a];
		}
		zer = sum[n-1] +10;
		res = INT_MAX;
		//printf("\nZER %lld\n", zer);
		dp[zer][0] = 1; 
		t[zer][0] = 0;
		t2[zer][0] = tt;
		for(int i=0;i<n;i++){
			for(int j = max(zer-(sum[i]+2),zer-rsum[i]-2);j<= min(zer+sum[i]+2, zer+rsum[i]+2);j++){
				if(t2[j][i&1] != tt){
					t2[j][i&1] = tt;
					t[j][i&1] = -1;
				}
				if(t[j][i&1] != i){
					dp[j][i&1] = 0;
					t[j][i&1] = i;
				}
				if(dp[j][i&1] == 1){
					//printf("boto em %lld %d e ", j+s[i], (i+1)&1);
					//printf("boto em %lld %d\n", j-s[i], (i+1)&1);
					dp[j+s[i]][(i+1)&1] = 1;
					t[j+s[i]][(i+1)&1] = i+1;
					t2[j+s[i]][(i+1)&1] = tt;
					dp[j-s[i]][(i+1)&1] = 1;
					t[j-s[i]][(i+1)&1] = i+1;
					t2[j-s[i]][(i+1)&1] = tt;
					if(i+1 == n){
						res = min(res, abs(zer - j - s[i]));
						res = min(res, abs(zer-(j-s[i])));
					}
				}
			}
		}

		printf("%lld\n", ans+res);
	}
}
