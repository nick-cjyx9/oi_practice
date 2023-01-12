#include <bits/stdc++.h>
using namespace std;
//WA on point#4
int main(){
	int n,nums[11],hans=0;
	cin>>n;for(int i=1;i<=n;i++)cin>>nums[i];
	for(int i=1;i<=n;i++){
		if(nums[i]==-1)continue;
		if(i==n){hans++;break;}
		for(int j=i+1;j<=n;j++){
			int mvd[11],cnt=1;mvd[1]=nums[i];
			bool stat=1;
			for(int k=1;k<=cnt;k++)
			if(__gcd(mvd[k],nums[j])!=1)stat=0;
			if(stat){
				mvd[++cnt]=nums[j];
				nums[j]=-1;
			}
		}hans++;
	}
	cout<<hans;
	return 0;
}
