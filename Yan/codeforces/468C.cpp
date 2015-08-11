// WROOOONG
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a;
ll mod(ll x) { return x % a; }
char str[200];
int rnum() {
	int n = 10;
	for(int i = 0; i < n; i++) {
		int num = rand() % 1000;
		sprintf(str + i * 3, "%03d", num);
	}
	return n * 3;
}
map<ll, string> mp;
int n;
ll memo[30][2][302];
ll solve(int dig, bool pre, int sum) {
	if(dig == n) return mod(sum);
	ll &r = memo[dig][pre][sum];
	if(r != -1) return r;
	r = 0;
	for(int i = 0; i <= 9; i++) {
		if(pre && i > (str[dig] - '0')) break;
		r = mod(r + solve(dig + 1, pre && (i == (str[dig] - '0')), sum + i));
	}
	return r;
}

char str2[200];

int main() {
	srand(time(NULL)); rand(); rand();
	scanf("%lld", &a);
	//scanf("%s %s", str, str2);
	//memset(memo, -1, sizeof memo); n = strlen(str);
	//ll aa = solve(0, true, 0);
	//strcpy(str, str2);
	//memset(memo, -1, sizeof memo); n = strlen(str);
	//ll bb = solve(0, true, 0);
	//printf("%lld - %lld = %lld\n", bb, aa, bb - aa);
	//return 0;

	while(true) {
		n = rnum();
		memset(memo, -1, sizeof memo);
		ll s = solve(0, true, 0);
		if(mp.count(s)) {
			strcpy(str2, mp[s].c_str());
			char *s1 = str, *s2 = str2;
			if(strcmp(s1, s2) > 0) swap(s1, s2);
			int i = n - 1;
			while(s1[i] == '9') s1[i--] = '0';
			s1[i]++;
			while(s1[0] == '0') s1++;
			while(s2[0] == '0') s2++;
			printf("%s %s\n", s1, s2);
			return 0;
		}
		mp[s] = string(str);
	}
}
