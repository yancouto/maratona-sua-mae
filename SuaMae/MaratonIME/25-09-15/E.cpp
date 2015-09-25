#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int MAXN = 25010;

int n, t;

long long res, ult[MAXN];

char seq[MAXN];

void solve(){
	for(int a=0;a<n;a++){
		ult[seq[a]]=a;
	}
	for(int a=0;a<n;a++){
		res-=5*(ult[seq[a]]-a);
	}
}

int main (){
	scanf("%d",&t);
	for(int z=0;z<t;z++){
		res=0;
		scanf("%d", &n);
		scanf(" %s", seq);

		solve();res*=-1;
		sort(seq,seq+n);
		solve();
		printf("%lld\n", res);
	}
	return 0;

}
