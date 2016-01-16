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

const int MAXN = 100010;

int n, ind[MAXN];

ll A, m, cf, cm, s[MAXN], sum[MAXN], res, ini[MAXN], resmen, rescnt;

bool cmp(int a,int b){
	return (s[a] < s[b]);
}

inline int bb(int i,int f,ll val){
	while(i < f){
		int mid = (i+f+1)/2;
		if(sum[mid] <= val)
			i = mid;
		else
			f = mid-1;
	}
	return i;
}

int main (){
	scanf("%d", &n);
	cin >> A >> cf >> cm >> m;
	for(int a=0;a<n;a++){
		cin >> s[a];
		ind[a] = a;
	}
	sort(ind,ind+n,cmp);
	ind[n] = n;
	s[n] = A;
	for(int a=1;a<=n;a++){
		if(sum[a-1] == m+1){
			sum[a] = m+1;
			continue;
		}
		sum[a] = sum[a-1] + (s[ind[a]]-s[ind[a-1]])*a;
	}

	if(sum[n] <= m){
		cout << n*cf + A*cm << '\n';
		for(int a=0;a<n;a++){
			cout << A << " ";
		}
		return 0;
	}

	ll cnt = -1;

	for(int a=n;a>0;a--){
		cnt++;
		m -= (A - s[ind[a]]);
		if(m < 0) break;
		int i = min(bb(0,n,m),a-1);
		ll mm = m;
		mm -= sum[i];
		ll men = min((mm/(i+1)) + s[ind[i]],A);
		if( men*cm + cnt*cf > res ){
			res = men*cm + cnt*cf;
			rescnt = cnt;
			resmen = men;
		}
	}
	cout << res << '\n';
	for(int a=n-1;a>=0;a--){
		if(rescnt){
			rescnt--;
			s[ind[a]] = A;
			continue;
		}
		if(s[ind[a]] < resmen){
			s[ind[a]] = resmen;
		}
	}
	for(int a=0;a<n;a++){
		cout << s[a] << " ";
	}

}