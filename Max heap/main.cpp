#include <iostream>
#include <algorithm>
using namespace std;

void max_heap(int *a, int m, int n) {
   int j, t;
   t = a[m];
   j = 2 * m;
   while (j <= n) {
      if (j < n && a[j+1] > a[j])
         j = j + 1;
      if (t > a[j])
         break;
      else if (t <= a[j]) {
         a[j / 2] = a[j];
         j = 2 * j;
      }
   }
   a[j/2] = t;
   return;
}

void build_maxheap(int *a,int n) {
   int k;
   for(k = n/2; k >= 1; k--) {
      max_heap(a,k,n);
   }
}

int main() {
    int O;
    
    while (cin >> O) {
        int maxHeap[1000001] = {0};
        int i = 1;
        int size = 0;
        unsigned long sum = 0;
        char o;
        
        while (O--) {
            cin >> o;
            switch (o) {
                case 'a':
                    size++;
                    int num;
                    cin >> num;
                    sum+=num;
                    maxHeap[i] = num;
                    i++;
                    break;
                case 'p':
                    build_maxheap(maxHeap, size);
                    sum -= maxHeap[1];
                    swap(maxHeap[1], maxHeap[size]);
                    size--;
                    i--;
                    build_maxheap(maxHeap, size);
                    break;
                case 'r':
                    cout << sum << endl;
                    break;
                default:
                    break;
            }
        }
//        for (int  i = 1; i <= size; i++){
//            cout << maxHeap[i] << " ";
//        }
//        cout << endl;
    }
}


//3
//a 3
//a 2
//a 1
//3 2 1
//13
//a 61
//a 1
//a 77
//a 19
//a 26
//a 15
//a 59
//a 5
//a 48
//a 11
//p
//p
//r
//8
//a 5
//a 4
//p
//r
//a 2
//a 3
//p
//r
