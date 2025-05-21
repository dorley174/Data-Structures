//Danil Valiev, DSAI-03
#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;
template<typename T>
class AVLTree {
public:
    struct node {
        T info;
        T index;
        node *left;
        node *right;
        T balance;
    };
    node *root;
    AVLTree() : root(NULL) {}

    T Height(node *root) {
        if(root == NULL) return 0;
        int hLeft = Height(root->left), hRight = Height(root->right);
        return max(hLeft, hRight) + 1;
    }

    void SetBalance(node *(&root)){
        if(root != 0)
            root->balance = Height(root->right) - Height(root->left);
    }

    void TurnLeft(node *(&root)) {
        node *rightSubtree, *rightSubtreeLeftSubtree;
        rightSubtree = root->right;
        rightSubtreeLeftSubtree = rightSubtree->left;

        rightSubtree->left = root;
        root->right = rightSubtreeLeftSubtree;
        root=rightSubtree;
        SetBalance(root->left);
        SetBalance(root);
    }

    void TurnRight(node *(&root)) {
        node *leftSubtree, *leftSubtreeRightSubtree;
        leftSubtree = root->left;
        leftSubtreeRightSubtree = leftSubtree->right;

        leftSubtree->right = root;
        root->left = leftSubtreeRightSubtree;
        root=leftSubtree;
        SetBalance(root->right);
        SetBalance(root);
    }

    void insert(node *(&root), T d) {
        if(root == NULL) {
            root = new node;
            root->info = d;
            root->left = NULL;
            root->right = NULL;
        }
        else {
            if(d > root->info) {
                insert(root->right, d);
                if(Height(root->right) - Height(root->left) > 1) {
                    if(Height(root->right->right) < Height(root->right->left))
                        TurnRight(root->right);
                    TurnLeft(root);
                }
            }
            else {
                if(d < root->info) {
                    insert(root->left, d);
                    if(Height(root->left) - Height(root->right) > 1) {
                        if(Height(root->left->left) < Height(root->left->right))
                            TurnLeft(root->left);
                        TurnRight(root);
                    }
                }
            }
            SetBalance(root);
        }
    }

    void giveindex(node *p, T ind) {
        if(p != NULL) {
            p->index = ind;
            (p->left != NULL && p->right != NULL) ? giveindex(p->left, 2*ind) : giveindex(p->left, ind+1);
            (p->right != NULL && p->left != NULL) ? giveindex(p->right, 2*ind+1) : giveindex(p->right, ind+1);
        }
    }

    void output(node *p) {
        if (p != NULL) {
            output(p->left);
            cout << p->info << "-" << p->index << " ";
            output(p->right);
        }
    }

    void pushChildren(node *p, vector<T>& a, vector<T>& l, vector<T>& r ) {
        if (p != NULL) {
            int leftChildren = (p->left != NULL) ? p->left->info : -1;
            int rightChildren = (p->right != NULL) ? p->right->info : -1;
            a.push_back(p->info); l.push_back(leftChildren); r.push_back(rightChildren);
            pushChildren(p->left, a, l, r);
            pushChildren(p->right, a, l, r);
        }
    }

    void clear(node *(&root)) {
        if (root != NULL) {
            clear(root->left);
            clear(root->right);
            delete root;
            root = NULL;
        }
    }

    void print(T n, vector<T>& a, vector<T>& l, vector<T>& r ) {
        cout<<n<<endl;
        for(int i=0; i<n; i++) {
            auto left = find(a.begin(), a.end(), l[i]),
                    right = find(a.begin(), a.end(), r[i]);
            cout<<a[i]<<" ";

            if(left - a.begin() +1 >n) cout<<-1<<" ";
            else cout<<left - a.begin()+1<<" ";

            if(right - a.begin() +1 >n) cout<<-1<<" ";
            else cout<<right - a.begin()+1<<" ";

            cout<<endl;
        }
        cout<<root->index;
    }
};
vector<int> sort(int n, vector<int>& b) {
    int M = 0;
    for (int i = 0; i < n; i++)
        M = max(M, b[i]);
    vector<int> countArray(M + 1, 0);
    for (int i = 0; i < n; i++)
        countArray[b[i]]++;
    for (int i = 1; i <= M; i++)
        countArray[i] += countArray[i - 1];
    vector<int> outputArray(n);
    for (int i = n - 1; i >= 0; i--)
    {
        outputArray[countArray[b[i]] - 1]= b[i];
        countArray[b[i]]--;
    }
    return outputArray;
}

int main() {
    int n;
    AVLTree<int> tree;
    cin >> n;
    vector<int> b(n), a, l, r ;
    for (auto &i : b) cin >> i;
    vector<int> ans=sort(n, b);
    for(auto i:ans)
        tree.insert(tree.root, i);
    tree.giveindex(tree.root, 1);
    tree.pushChildren(tree.root, a, l, r);
    tree.print(n, a, l, r);
    tree.clear(tree.root);
    return 0;
}
