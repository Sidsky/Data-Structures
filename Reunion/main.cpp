#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef queue<int> qi;

vi map[1001];
vi friends; 
vi cities (1001, 0);

void BFS(int src){
    qi Q;
    vi visited(1001, 0);

    Q.push(src);
    visited[src]=1;
    cities[src]++;


    while(!Q.empty()){
        int next=Q.front();
        Q.pop();

        for(int i=0; i<map[next].size(); i++){
            int node = map[next][i];
            
            if(!visited[node]){
                Q.push(node);
                visited[node]=1;
                cities[node]++;
            }
        }
    }

}

void reunite (int n, int k){
    int reunited=0; 

    for (int i =0; i<friends.size(); i++){
        BFS(friends[i]);
    }

    for(int i=1; i<=n; i++){
        if(cities[i]==k){
            reunited++;
        }
    }
    cout<<reunited<<endl;
}

int main(){
    int k, n, m, ki, dep, des;

    while(cin>>k>>n>>m){
        for(int i=0; i<k; i++){
            cin>>ki;
            friends.push_back(ki);
        }

        while (m--){
            cin>>dep>>des;
            map[dep].push_back(des);
        }

        reunite(n, k);

        for(int i=0; i<1001; i++) {
            map[i].clear();
            cities[i]=0;
        }

        friends.clear();

    }
}
