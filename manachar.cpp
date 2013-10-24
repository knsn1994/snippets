#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int a[10007]; 
int main() {
    int ts,n;
	 long long s; 
	int ans; 
    cin >> ts;
    while(ts--){
        cin >> n; 
		s = 0LL; 
		for(int i=0;i<n;i++){
			cin >> a[i]; 
			s+=a[i]*1LL; 
		}
		sort(a,a+n); 
		bool flog = true; 
		for(int i=n-1;i>=2;i--){
			s -= a[i]; 
			if(s > a[i]){
				cout << i+1 << endl; 
				flag = false; 
				break; 
			}
		}
		if(flag){
			cout << -1 << endl
		}
    }
    return 0;
}
