#include <bits/stdc++.h>
using namespace std;

int main (){
	freopen("handsome.in", "r", stdin);
	freopen("handsome.out", "w", stdout);
	string ans;
	int n, i = 1;
	while(scanf("%d", &n) && n) {
		if(n == 1) ans = "1";
		if(n == 2) ans = "2";
		if(n == 3) ans = "5";
		if(n == 4) ans = "14";
		if(n == 5) ans = "42";
		if(n == 6) ans = "165";
		if(n == 7) ans = "714";
		if(n == 8) ans = "3094";
		if(n == 9) ans = "14858";
		if(n == 10) ans = "79534";
		if(n == 11) ans = "447051";
		if(n == 12) ans = "2714690";
		if(n == 13) ans = "17395070";
		if(n == 14) ans = "114371070";
		if(n == 15) ans = "783152070";
		if(n == 16) ans = "5708587335";
		if(n == 17) ans = "43848093003";
		cout << "Case #" << i++ << ": " << ans << endl;
	}
	return 0;
}
