#include<iostream>
#include <stack>
using namespace std;
typedef long long int bigNumber;
  
bigNumber stockMarket(bigNumber array[], bigNumber n) {
    
    stack<bigNumber> s;
    bigNumber max = 0, top, topArea, i = 0;
    while (i < n) {
        if (s.empty() || array[s.top()] <= array[i])
            s.push(i++);
        else {
            top = s.top();
            s.pop();

            topArea = array[top] * (s.empty() ? i : i - s.top() - 1);
  
            if (max < topArea)
                max = topArea;
        }
    }
    while (s.empty() == false) {
        top = s.top();
        s.pop();
        topArea = array[top] * (s.empty() ? i : i - s.top() - 1);
        if (max < topArea)
            max = topArea;
    }
    return max;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        bigNumber s;
        cin >> s;

        bigNumber *array = new bigNumber[s];

        for (bigNumber i = 0; i < s; i++){
            cin >> array[i];
        }
        cout << stockMarket(array, s) << endl;
    }
    return 0;
}
