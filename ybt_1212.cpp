#include <bits/stdc++.h>
using namespace std;
char maze[114][514];int R,S,hans=1;
int fxx[5]={0,-1,1,0,0};
int fxy[5]={0,0,0,-1,1};
bool vis[255];
inline void dfs(int x,int y,int stp){
	bool stat=1;
	for(int i=1;i<=4;i++){
		int xx=x+fxx[i];
		int yy=y+fxy[i];
		if(maze[xx][yy]!=0&&vis[maze[xx][yy]]==0){
			stat=0;
//			cout<<maze[xx][yy]<<'-';
			vis[maze[xx][yy]]=1;
			dfs(xx,yy,stp+1);
			vis[maze[xx][yy]]=0;			
		}
	}
	if(stat){
//		cout<<endl;
		if(stp>hans)hans=stp;
	}
}

int main(){
	cin>>R>>S;
	memset(maze,0,sizeof(maze));
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=R;i++)
	for(int j=1;j<=S;j++)
	cin>>maze[i][j];
	vis[maze[1][1]]=1;
	dfs(1,1,1);
	cout<<hans;
	return 0;
}
