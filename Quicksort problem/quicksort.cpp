#include <iostream>
using namespace std;
void sort(int *a, int size) {
    int i=0, j=size-1, mid=a[size/2];           //quick sort in c++ 
    while (i<=j) {                              
        while(a[i] < mid) 
            i++;
        while(a[j] > mid) 
            j--;
        if (i <= j) {
            int tmp = a[i];
            a[i] = a[j];
            a[j] = tmp;
            i++; j--;
        }
    } 
    if(j > 0) 
        sort(a, j + 1);
    if (i < size) 
        sort(&a[i], size - i);
}
int main() {
   int n, a[1000000];
   cin>>n;
   for(int i=0; i<n; i++) 
       cin>>a[i];
   sort(a, n);
   for(int i=0; i<n; i++) {
       cout<<a[i]<<" ";
   }
    
}
