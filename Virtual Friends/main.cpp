#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef pair<string, int> si;
typedef vector<si> vsi;
typedef map<string,int> msi;

int DS[2000001];
int rankk[2000001];
int gSize[2000001];

bool count(vsi map, string name){
    for(int i=0;i<map.size();i++){
        if(map[i].first==name)return true;
    }
    return false;
}
int getID(vsi map, string name){
    for(int i=0;i<map.size();i++){
        if(map[i].first==name)return map[i].second;
    }
    return 0;
}

int parent(int i){
    if(DS[i]!=i){
        DS[i]=parent(DS[i]);
    }
    return DS[i];
}

void unioN(int a, int b){
    int ap= parent(a);
    int bp= parent(b);
    
    if(ap!=bp){
        if(rankk[ap]>rankk[bp]){
            DS[bp]=ap;
            gSize[ap]+=gSize[bp];
        }
        else if(rankk[bp]>rankk[ap]){
            DS[ap]=bp;
            gSize[bp]+=gSize[ap];
        }
        else {
            DS[bp]=ap;
            gSize[ap]+=gSize[bp];
            rankk[ap]+=1;
        }
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int m;
        scanf("%d",&m);
        for(int i=1;i<=2*m;i++){
            DS[i]=i;
            rankk[i]=1;
            gSize[i]=1;
        }
        int id=1;
        msi map;
        
        while(m--){
            string a,b;
            int n1, n2;
            cin>>a>>b;
            if(map.count(a)==0){
                n1 = id;
                map.insert(make_pair(a, id++));
            }
            else{
                n1 = map[a];
            }
            
            if (map.count(b)==0){
                n2 = id;
                map.insert(make_pair(b, id++));
            }
            else{
                n2 = map[b];
            }
            
            unioN(n1,n2);
            cout<<gSize[parent(n1)]<<endl;
        }
    }
}
