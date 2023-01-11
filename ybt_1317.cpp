#include <bits/stdc++.h>
using namespace std;
int n,r,vis[999];

inline void dfs(int x,int y){
	if(x==r+1){
		for(int i=1;i<=r;i++)
		cout<<setw(3)<<vis[i];
		cout<<endl;
		return ;
	}
	for(int i=y+1;i<=n;i++){
		vis[x]=i;
		dfs(x+1,i);
	}
}

int main(){
	cin>>n>>r;
	dfs(1,0);
	return 0;
}
