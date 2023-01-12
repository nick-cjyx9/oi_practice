#include <bits/stdc++.h>
using namespace std;

inline bool dfs(int x,int y,bool s){
	if(x/y>=2)return 1;
	else return !dfs(y,x%y,!s);
}
int main(){
	while(1){
		int a,b;
		cin>>a>>b;
		if(a==0)return 0;
		if(a<b)swap(a,b);
		if(dfs(a,b,1))cout<<"win";
		else cout<<"lose";
		cout<<endl;
	}
}
