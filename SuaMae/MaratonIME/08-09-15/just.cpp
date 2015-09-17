#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;

const int MOD = 1000000007;
ll mod(ll x) { return x % MOD; }

int t, f[15];

ll base, ans, res, dp[15][100];

ll expo(ll v,int e){
	if(e==0) return 1;
	expo(v,e/2);
	ans = (ans*ans)%MOD;
	if(e%2!=0){
		ans = (base*ans)%MOD;
	}
	return ans;
}

ll fat[105];
ll pot[12];
void pre() {
	fat[0] = 1;
	for(int i = 1; i < 105; i++)
		fat[i] = mod(ll(i) * fat[i - 1]);
	for(int i = 0; i <= 9; i++) {
		base = fat[i]; ans = 1ll;
		pot[i] = expo(base, MOD - 2);
	}
}

ll go(int d,int k){
	if(k<0) return 0;
	if(dp[d][k]==-1){
		if(d==10){
			if(k==0) return dp[d][k]=1;
			else return 0;
		}
		dp[d][k]=0;
		for(int a=0;a<=f[d];a++){
			dp[d][k]=(dp[d][k] + pot[a] * go(d+1,k-a))%MOD;
		}
	}
	return dp[d][k];
}
		

int main(){
	pre();
	scanf("%d", &t);
	for(int z=0;z<t;z++){
		res=0;
		int som=0;
		for(int a=1;a<=9;a++){
			scanf("%d", &f[a]);
			som+=f[a];
		}
		for(int dig=1;dig<=9;dig++){
			if(f[dig]==0) continue;
			f[dig]--;
			ll x = 1;
			for(int a = 1; a <= 10; a++)
				for(int b = 0; b <= som; b++)
					dp[a][b] = -1;
			for(int a=1;a<=som;a++){
				for(int b = 0; b + a <= som; b++)
					res = mod(res + mod(mod(x * dig) * go(1,a-1+b)) * fat[a-1+b]);
				x = (10ll * x) % MOD;
			}
			f[dig]++;
		}
		printf("%lld\n", res);
	}
	return 0;
}
		

