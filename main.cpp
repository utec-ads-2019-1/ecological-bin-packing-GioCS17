#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int getrest(int *arr,int pos){
	int acum=0;
	for(int i=0;i<3;i++)
		if(i!=pos)
			acum+=arr[i];
	return acum;
}
int main() {

	int b[3],g[3],c[3];

	while(cin>>b[0]>>g[0]>>c[0]>>b[1]>>g[1]>>c[1]>>b[2]>>g[2]>>c[2]){
		int movb[]={0,0,1,2,1,2};
		int movg[]={2,1,2,1,0,0};
		int movc[]={1,2,0,0,2,1};

		int mini=1<<31-1;
		int aux;
		int pos;
		for(int i=0;i<6;i++){
			aux=getrest(b,movb[i]);
			aux+=getrest(g,movg[i]);
			aux+=getrest(c,movc[i]);
			if(mini>aux){
				mini=aux;
				pos=i;
			}
		}
		vector<pair<int,char>> v;
		v.push_back(make_pair(movb[pos],'B'));
		v.push_back(make_pair(movg[pos],'G'));
		v.push_back(make_pair(movc[pos],'C'));
		sort(v.begin(),v.end());

		for(auto t:v)
			cout<<t.second;
		cout<<" "<<mini<<endl;
	}
	
    return EXIT_SUCCESS;
}
