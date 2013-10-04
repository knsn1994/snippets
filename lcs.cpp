#include<iostream>
#include<string.h>
#include<cstdio>
#include<string>

using namespace std;
#define gc getchar
#define MAXN 5001
int fcin(){register int c = gc();int x = 0;for(;(c<48 || c>57);c = gc());for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}return x;}
static char a[MAXN],b[MAXN];
int n;
static int dp[MAXN][MAXN];

int main(){
	int t = fcin();
	while (t--) {
		scanf("%s",a);
	    n = strlen(a);
		for(int i=0;i<n;i++){
			b[i] = a[n-i-1]; 
		}
		for(int i=0;i<n;i++)dp[i][n] = dp[n][i] = 0;
		for(int i=n-1;i>=0;i--){
			for(int j=n-1;j>=0;j--){
				if(a[i] == b[j])dp[i][j] = 1+dp[i+1][j+1]; 
				else dp[i][j] = max(dp[i][j+1],dp[i+1][j]);
			}
		}
		
		printf("%d\n",n-dp[0][0]);
	}
	return 0;
}