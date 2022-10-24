#include <iostream>
#include <string.h>
using namespace std;

int dp[2][5005];
int num[2][5005];
int mod = 1e8;
int main()
{
	memset(dp, 0, sizeof(dp));	
	string s1, s2;
	int t = 0;
	cin >> s1 >> s2;
	for(int i = 0; i < s2.length(); i++) num[0][i] = 1;
	num[1][0] = 1;
	for (int i = 1; i < s1.length(); i++, t ^= 1) {
		for (int j = 1; j < s2.length(); j++) {
			num[t^1][j] = 0;
			if(s1[i - 1] == s2[j - 1]) {
				dp[t^1][j] = dp[t][j - 1] + 1;
				num[t^1][j] += num[t][j-1] % mod;
			}
			else dp[t^1][j] = max(dp[t][j], dp[t^1][j - 1]);
			if(dp[t^1][j] == dp[t][j]) num[t^1][j] += num[t][j] % mod;
			if(dp[t^1][j] == dp[t^1][j-1]) num[t^1][j] += num[t^1][j-1] % mod;
			if(s1[i-1] != s2[j-1] && dp[t^1][j] == dp[t][j-1]) num[t^1][j] -= num[t][j-1];
		}
	}
	cout << dp[t][s2.size() - 1] << endl;
	cout << num[t][s2.size() -1] << endl;
}