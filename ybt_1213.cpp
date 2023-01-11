#include <bits/stdc++.h>
using namespace std;
bool vis_c[10],vis_r[16],vis_l[16];
int mp[10][10],n; 
void visset(int x,int y,bool isSet){
    vis_c[y]=isSet;
    vis_r[x-y+8]=isSet;
    vis_l[x+y-1]=isSet;
}
void dfs(int x){
    for(int y=1;y<=8;y++){
        if(vis_c[y]==0&&vis_r[x-y+8]==0&&vis_l[x+y-1]==0){
            mp[x][y]=1;
            visset(x,y,true); 
            if(x==8){
                cout<<"No."<<' '<<++n<<endl;
                for(int j=1;j<=8;j++){
                    for(int i=1;i<=8;i++)
                        cout<<mp[i][j]<<' ';
                    cout<<endl;
                }
            }
            else dfs(x+1);
            visset(x,y,0);
            mp[x][y]=0;
        }
    }
}
int main(){
    dfs(1);
    return 0;
}
