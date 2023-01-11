#include <bits/stdc++.h>
#define ooOO0 int
using namespace std;
char Oo0[114][514];
bool ooo[255];
ooOO0 oo0[5]={0,-1,1,0,0};
ooOO0 o00[5]={0,0,0,-1,1};
ooOO0 O0o,Ooo,oO0=1;
inline void OOO(ooOO0 oo,ooOO0 OO,ooOO0 Oo){
	bool OO0=1;
	for(ooOO0 o=1;o<=4;o++){
		ooOO0 o0o=oo+oo0[o];
		ooOO0 O0O=OO+o00[o];
		if(Oo0[o0o][O0O]!=0&&ooo[Oo0[o0o][O0O]]==0){
			OO0=0;
			ooo[Oo0[o0o][O0O]]=1;
			OOO(o0o,O0O,Oo+1);
			ooo[Oo0[o0o][O0O]]=0;			
		}
	}
	if(OO0){if(Oo>oO0)oO0=Oo;}
}
ooOO0 main(){
	cin>>O0o>>Ooo;
	memset(Oo0,0,sizeof(Oo0));
	memset(ooo,0,sizeof(ooo));
	for(ooOO0 o=1;o<=O0o;o++)
	for(ooOO0 O=1;O<=Ooo;O++) cin>>Oo0[o][O];
	ooo[Oo0[1][1]]=1;
	OOO(1,1,1);
	cout<<oO0;
	return 0;
}
