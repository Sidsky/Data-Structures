#include <iostream>
#include <iomanip>
using namespace std;

int row[9], a,b, counter;

bool isFeasible(int r, int c){
    for(int prev=0; prev<c; prev++) {
        if(row[prev]==r || abs(row[prev]-r)==abs(prev-c))
            return false;
    }
    return true;
}
void backtrack(int c){
    if(c==8 && row[b]==a){
        cout<<setw(2)<<counter++<<"     ";
        for(int i=0;i<8;i++)cout<<" "<<row[i]+1;
        cout<<endl;
    }
    for (int r=0;r<8;r++) {
        if(isFeasible(r, c)){
            row[c]=r;
            backtrack(c+1);
        }
    }
}
int main (){
    int t; cin>>t;
    while(t--){
        for(int i=0;i<9;i++)row[i]=0;
        counter=1;
        cin.ignore();
        cin>>a>>b;a--;b--;
        cout<<"SOLN       COLUMN"<<endl;
        cout<<" #      1 2 3 4 5 6 7 8"<<endl<<endl;
        backtrack(0);
        if(t)cout<<endl;
    }
}
