#include <iostream>

using namespace std;

int parent(int i, int *array){
    if(array[i]!=i){
        array[i]=parent(array[i], array);
    }
    return array[i];
}
void unioN(int *array, const int i, const int j, int *rank){
    int a= parent(i, array);
    int b= parent(j, array);
    
    if (a!=b){
        if(rank[a] > rank[b]){
            array[b]=a;
        }
        else if (rank[b] > rank[a]){
            array[a]=b;
        }
        else {
            array[b]=a;
            rank[a]+=1;
        }
    }
}
bool connected(int *array, int c1, int c2){
    return (parent(c1, array)==parent(c2, array));
}

int main(){
    int t,count=0; cin>>t;
    cin.ignore();
    while(t--){
        count++;
        int n;
        scanf("\n%d\n",&n);
        int *array= new int[n+1];
        int *rank = new int[n+1];
        for(int i=0;i<=n;i++){
            array[i]=i;
            rank[i]=1;
        }
        int success=0,failure=0;
        int x,y;char c;
        string s;
        while(true){
            if(!getline(cin,s) || s.empty()) break;
            sscanf(s.c_str(),"%c %d %d",&c,&x,&y);
            if (c=='c'){
                unioN(array, x, y, rank);
            }
            if(c=='q'){
                if(connected(array, x, y))
                    success++;
                else
                    failure++;
            }
        }
        if(count!=1)cout<<endl;
        cout<<success<<","<<failure<<endl;
    }
}
//2
//
//10
//c 1 5
//c 2 7
//q 7 1
//c 3 9
//q 9 6
//c 2 5
//q 7 5
//
//1
//q 1 1
//c 1 1
//q 1 1



//9
//c 3 9
//c 1 6
//c 4 8
//c 3 2
//c 3 8
//c 5 7
//c 6 2
//c 5 4
//q 9 1
//q 4 8
