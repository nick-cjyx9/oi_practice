#include <bits/stdc++.h>
using namespace std;
int n,hans[666],cnt;
inline void dfs(int x,int y,int lmt){
	if(x==0&&y!=2){
		cnt++;
		cout<<n<<"=";
		for(int i=1;i<y-1;i++)
		cout<<hans[i]<<"+";
		cout<<hans[y-1]<<endl;
	}
	for(int i=lmt;i<=x;i++){
		hans[y]=i;
		dfs(x-i,y+1,i);
	}
}

int main(){
	cin>>n;
	dfs(n,1,1);
	return 0;
}
