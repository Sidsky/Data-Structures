#include <iostream>
#define ll long long
using namespace std;

int adj[513][513], n;

int vis[510];

int tree[510];

void dfs(int u, int id, int p) {
    
    vis[u] = id;
    
    for (int i = 1; i <= n; i++) {
        
        if (i != p && adj[u][i]) {
            
            if (!vis[i])
                dfs(i, id, u);
            else
                tree[id] = 0;
        }
    }
}

int main()
{
  
   int caseNum = 1;
    
   while(1) {
       int m;
       cin >> n >> m;
       
       if(n == 0 && m == 0) break;
       for(int i = 1; i <= n; i++) vis[i] = 0;
       for(int i = 1; i <= n; i++) {
           for(int j = 1; j <= n; j++) adj[i][j] = 0;
       }
       
       for(int i = 1; i <= m; i++) {
           int u,v;
           cin >> u >> v;
           adj[u][v] = 1;
           adj[v][u] = 1;
       }

       for(int i = 1; i <= n; i++) {
           if(!vis[i]) {
               tree[i] = 1;
               dfs(i, i, 0);
           }
       }
       
       int cnt = 0;
       for(int i = 1; i <= n; i++) {
           if(vis[i] == i && tree[i]) cnt++;
       }
       if(cnt > 1) {
           cout << "Case " << caseNum << ": A forest of " << cnt << " trees." << endl;
       } else if(cnt == 1) {
           cout << "Case " << caseNum << ": There is one tree." << endl;
       } else{
            cout << "Case " << caseNum << ": No trees." << endl;
       }
       caseNum++;
   }
}
