#include <iostream>
#include <algorithm>
using namespace std;

class DisjointSet {
private:
    int size;
    int *rank;
    int *Friend;
    int *counter;
    
public:
    DisjointSet(int n) {
        this -> rank = new int[n+1];
        this -> Friend = new int [n+1];
        this -> counter = new int[n+1];
        this -> size = n;
        makeSet();
    }
    
    void makeSet() {
        for (int i = 1; i <= size; i++){
            rank[i] = 0;
            Friend[i] = i;
            counter[i] = 1;
        }
    }
    
    int find(int i) {
        if (Friend[i] != i) {
            Friend[i] = find(Friend[i]);
        }
        return Friend[i];
    }
    
    void Union (int i, int j) {
        int parentI = find(i);
        int parentJ = find(j);
        
        if (parentI != parentJ) {
            if (rank[parentI] > rank[parentJ]) {
                Friend[parentJ] = parentI;
                counter[parentI] += counter[parentJ];
            }
            else if (rank[parentI] < rank[parentJ]) {
                Friend[parentI] = parentJ;
                counter[parentJ] += counter[parentI];
            }
            else {
                Friend[parentJ] = parentI;
                counter[parentI] += counter[parentJ];
                rank[parentI] = rank[parentI] + 1;
            }
        }
    }
    
    int getBiggestGroup() {
        return *max_element(counter, counter+size);
    }
};

int main () {
    int T;
    cin >> T;
    
    while (T--) {
        int N, M;
        cin >> N >> M;
        
        DisjointSet friends(N);
        
        while(M--) {
            int i, j;
            cin >> i >> j;
            friends.Union(i,j);
        }
        cout << friends.getBiggestGroup() << endl;
    }
}
//1
//10 12
//1 2
//3 1
//3 4
//5 4
//3 5
//4 6
//5 2
//2 1
//7 10
//1 2
//9 10
//8 9
