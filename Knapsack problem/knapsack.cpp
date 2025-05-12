//Danil Valiev
#include <iostream>
#include <vector>
using namespace std;
void knapsack(int w, int a[], int v[], int n, vector<int> &ans) {
    vector<vector<int>> K(n + 1, vector<int>(w + 1));
    for (int i = 0; i <= n; i++) 
        for (int j = 0; j <= w; j++) {
            if (i == 0 || j == 0)
                K[i][j] = 0;
            else if (a[i - 1] <= j)
                K[i][j] = max(v[i - 1] + K[i - 1][j - a[i - 1]], K[i - 1][j]);
            else
                K[i][j] = K[i - 1][j];
        }
    int res = K[n][w];
    int j = w;
    for (int i = n; i > 0 && res > 0; i--) {
        if (res == K[i - 1][j])
            continue;
        else {
            ans.push_back(i);
            res -= v[i - 1];
            j -= a[i - 1];
        }
    }
}
int main() {
    int n, w;
    cin >> n >> w;
    int a[n], v[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> v[i];
    vector<int> ans;
    knapsack(w, a, v, n, ans);
    cout << ans.size() << endl;
    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << " ";
    return 0;
}
