#include <iostream>
#include <vector>

using namespace std;

typedef unsigned int ui;

ui cache[1000000] = {0};

ui Three (ui n) {
    if (n % 2 == 0) {
        return n/2;
    }
    else {
        return 3 * n + 1;
    }
}

ui cycleLength(ui n) {
    
    if (n == 1)
        return 1;
    
    if (n < 1000000 && cache[n] != 0)
        return cache[n];
    
    int length = 1 + cycleLength (Three(n));

    if (n < 1000000)
        cache[n] = length;

    return length;
}

int main () {

    ui num1, num2;

    while (cin >> num1 >> num2) {

        ui small = num1 < num2 ? num1:num2;
        ui large = num1 > num2 ? num1:num2;
        ui max = 0;
        
        for (ui i = small; i <= large; i++) {
            max = max > cycleLength(i) ? max:cycleLength(i);
        }

        cout << num1 << " " << num2 << " " << max << endl;
    }
    return 22;
}
