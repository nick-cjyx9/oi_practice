#include <bits/stdc++.h>
using namespace std;
char maze[114][514];bool vis_v[19];
int n=114514,k=191981,hans=0;

inline void dfs(int x,int stp){
	if(stp==k){
		hans++;
		return ;
	}
	if(x>n||n-x+1<k-stp) return ;
	//¿ÉÐÐÐÔ¼ôÖ¦
	for(int i=1;i<=n;i++){
		if(maze[x][i]=='#'&&vis_v[i]==0){
			vis_v[i]=1;
			dfs(x+1,stp+1);
			vis_v[i]=0;
		}
	}
	dfs(x+1,stp);
}

int main(){
	while(1){
		hans=0;
		cin>>n>>k;
		if(n==-1&&k==-1)return 0;
		else{
			for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			cin>>maze[i][j];
			dfs(1,0);
		}
		cout<<hans<<endl;
	}
}
