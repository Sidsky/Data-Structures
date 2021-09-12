#include <iostream>
#include <map>
using namespace std;

map<string, bool> sb;
map<string, bool> :: iterator it;

int main(){
    string word;
    string line;
    while(getline(cin, line)){
        line+=" ";
        for(int i=0; i<line.length(); i++){
            if((i < (line.length()-1)) && (int(line[i])>=65 && int(line[i]<=90)) || (int(line[i])>=97 && int(line[i]<=122))) {
                if (int(line[i])>=65 && int(line[i]<=90)){
                    word+=(char(int(line[i])+32));
                }
                else 
                    word+=line[i];
            } else {
                if (word.length()!=0){
                    if(sb[word]==false)
                        sb[word]=true;
                }
                word = "";
            }
        }
        word="";
    }
    
    for(it=sb.begin(); it!=sb.end(); it++){
            cout<<it->first<<endl;
    }
    return 0;
}

// Adventures in Disneyland

// Two blondes were going to Disneyland when they came to a fork in the road. The sign read: "Disneyland Left."

// So they went home.
