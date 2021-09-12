#include <iostream>
#include <stack>
#include <string>

using namespace std;

//Shunting Yard Algorithm

typedef stack<char> sc;

bool precedence(char a, char b){
    if(b=='(')return false;
    else if (a=='+'||a=='-')return true;
    else if (a=='*' && (b=='*'||b=='/'))return true;
    else if (a=='/' && (b=='*'||b=='/'))return true;
    else return false;
}

int main(){
    int t;cin>>t;
    cin.ignore();cin.ignore();
    while(t--){
        string s;
        sc e;
        while(1){
            char c;
            if(!getline(cin,s)||s.empty())break;
            sscanf(s.c_str(), "%c",&c);
            if(c=='(')
                e.push(c);
            else if(c==')'){
                while(e.top()!='('){
                    cout<<e.top();
                    e.pop();
                }
                e.pop();
            }
            else if (c=='+'||c=='/'||c=='*'||c=='-'){
                if(e.empty())e.push(c);
                else{
                    if(precedence(c, e.top())){
                        while(!e.empty() && precedence(c, e.top())){
                            cout<<e.top();
                            e.pop();
                        }
                        e.push(c);
                    }
                    else
                        e.push(c);
                }
            }
            
            else
                cout<<c;
        }
        while(!e.empty()){
            cout<<e.top();
            e.pop();
        }
        if(t!=0){
            cout<<endl<<endl;
        }else cout<<endl;
    }
}
