//Danil Valiev
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int max(int a, int b) {
    if(a>b) return a;
    else return b;
}
template<typename T>
vector<vector<T>> DanilValiev_count_srt(vector<vector<T>>&a, T& n, T exponent, T column, string direction) {
    vector<vector<T>> data(n, vector<T>(3)), ans(n, vector<T>(3));
    vector<T> number(10, 0);
    for(int i=0; i<n; i++)
        data[i][column]=a[i][column]/exponent % 10;
    for(int i=0; i<n; i++)
        number[data[i][column]]++;
    if(direction=="common")
        for(int i=1; i<=9; i++)
            number[i]+=number[i-1];
    else
        for(int i=8; i>=0; i--)
            number[i]+=number[i+1];
    for(int i=n-1; i>=0; i--) {
        int current=data[i][column];
        ans[number[current]-1][0]=a[i][0];
        ans[number[current]-1][1]=a[i][1];
        ans[number[current]-1][2]=a[i][2];
        number[current]--;
    }
    a=ans;
    return a;
}
template<typename T>
vector<vector<T>> DanilValiev_radix_srt(vector<vector<T>>& a, T& n) {
    int max1=-1, max2=-1;
    for(int i=0; i<n; i++) {
        max1=max(max1, a[i][1]);
        max2=max(max2, a[i][2]);
    }
    for(int i=1; max2/i>0; i*=10)
        a=DanilValiev_count_srt(a, n,i,2,"common");
    for(int i=1; max1/i>0; i*=10)
        a=DanilValiev_count_srt(a, n,i,1,"reverse");
    return a;
}
int main() {
    int n;
    cin>>n;
    vector<vector<int>> a(n, vector<int>(3));
    for(int i=0; i<n; i++) {
        a[i][0]=i+1;
        cin>>a[i][1]>>a[i][2];
    }
    a= DanilValiev_radix_srt<int>(a,n);
    for(auto i: a) cout<<i[0]<<" ";
}
