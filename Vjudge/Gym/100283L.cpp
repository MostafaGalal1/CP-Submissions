// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <algorithm>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890
#define patkan 9
#define tisic 47
#define soclose 10e-7
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define chocolate win
#define ff first
#define ss second
#define abs(x) ((x < 0)?-(x):(x))
// mylittlepony
using namespace std;
	
int main() {
	cin.sync_with_stdio(0);
	freopen("mahdi.in","r",stdin);
	int T;
	cin >> T;

    for(int t =0; t < T; t++) {
    	string S;
    	int L,N;
    	int R[2];
    	cin >> S >> L >> R[0] >> R[1] >> N;
    	
    	vector< vector< pair<int,int> > > A(26);
    	vector<int> last(N);
    	vector<int> Ls(N);
    	vector<int> Rs[2];
    	Rs[0].resize(N); Rs[1].resize(N);

    	for(int i = 0; i < N; i++) {
    		string s;
    		cin >> s >> Ls[i] >> Rs[0][i] >> Rs[1][i];
    		last[i] =s[0]-'a';
    		A[s[0]-'a'].push_back(make_pair(0,i));
	}

    	vector<bool> ans(N,false);
    	for(int i =0; i < L; i++) {
    		vector< pair<int,int> > upd =A[S[i]-'a'];
    		A[S[i]-'a'].clear();
    		for(int i =0; i < upd.size(); i++) {
    			upd[i].ff++;
    			int id =upd[i].ss;
    			if(Ls[id] == upd[i].ff) {
    				ans[id] =true;
    				continue;}
	    		int x =(last[id]*Rs[0][id]+upd[i].ff*Rs[1][id])%26;
    			if(x < 0) x +=26;
    			last[id] =x;
    			A[x].push_back(upd[i]);}

    		if(i == L-1) break;
    		int x =((S[i]-'a')*R[0]+(i+1)*R[1])%26;
    		if(x < 0) x +=26;
    		S +=(char)('a'+x);}

   		cout << "Case " << t+1 << ":\n";
   		for(int i =0; i < N; i++) {
   			if(ans[i]) cout << "BRAVO\n";
   			else cout << "REPEAT\n";
		}
    	}
    return 0;
}