#include <iostream>
#include <vector>
#include <string>
using namespace std;
struct p {
  string name;
  long long stat;
};
void sort(p *a, int size) {
    int i=0, j=size-1, mid=a[size/2].stat;            
    while (i<=j) {                              
        while(a[i].stat < mid) 
            i++;
        while(a[j].stat > mid) 
            j--;
        if (i <= j) {
            swap(a[i], a[j]);
            i++; j--;
        }
    } 
    if(j > 0) 
        sort(a, j + 1);
    if (i < size) 
        sort(&a[i], size - i);
}
int main() {
   int n, k;
   p a[1000000];
   cin>>n>>k;
   for(int i=0; i<n; i++) 
       cin>>a[i].name>>a[i].stat;
   sort(a, n);
   if(k>n) 
        for(int i=n-1; i>=0; i--) {
            cout<<a[i].name<<" "<<a[i].stat<<endl;
        }
   else
        for(int i=n-1; i>=n-k; i--) {
            cout<<a[i].name<<" "<<a[i].stat<<endl;
        }
    
}
