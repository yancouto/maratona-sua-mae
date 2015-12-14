#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int 	MAXN = 10010;

int n, k, t;

long long maiv, v[MAXN];

long long da(long long val){
	long long ans=0;
	for(int a=0;a<n;a++){
		ans+=v[a]/val;
	}
	return ans;
}

int main (){
	scanf("%d", &t);
	for(int z=0;z<t;z++){
		scanf("%d%d", &n, &k);
		if(z > 0) printf("\n");
		maiv=-1;
		for(int a=0;a<n;a++){
			double aux;
			scanf("%lf", &aux);
			v[a]=aux*10000LL;
			maiv=max(maiv,v[a]);
		}
		long long i = 1, f = maiv;
		while(i!=f){
			long long m = (i+f+1)/2;
			if(da(m)<k)
				f=m-1;
			else
				i=m;
		}
		double res = i/10000.00;
		
		if(i<100) 
			printf("0.00\n");
		else
			printf("%.2f\n", res);
	}
	return 0;
}
			
