#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct TreapNode {
    int key, priority, size;
    TreapNode *left, *right;

    TreapNode(int k) : key(k), priority(rand()), size(1), left(nullptr), right(nullptr) {}
};

// Cập nhật kích thước cây
void updateSize(TreapNode* t) {
    if (t) {
        t->size = 1 + (t->left ? t->left->size : 0) + (t->right ? t->right->size : 0);
    }
}

// Chia cây dựa trên khóa key
void split(TreapNode* t, int key, TreapNode*& left, TreapNode*& right) {
    if (!t) {
        left = right = nullptr;
    } else if (key <= (t->left ? t->left->size : 0)) {
        split(t->left, key, left, t->left);
        right = t;
    } else {
        split(t->right, key - (t->left ? t->left->size : 0) - 1, t->right, right);
        left = t;
    }
    updateSize(t);
}

// Hợp hai cây lại với nhau
TreapNode* merge(TreapNode* left, TreapNode* right) {
    if (!left || !right) return left ? left : right;
    if (left->priority > right->priority) {
        left->right = merge(left->right, right);
        updateSize(left);
        return left;
    } else {
        right->left = merge(left, right->left);
        updateSize(right);
        return right;
    }
}

// Thêm phần tử vào cây
TreapNode* insert(TreapNode* t, int key) {
    TreapNode* newNode = new TreapNode(key);
    return merge(t, newNode);
}

// Duyệt cây để in các phần tử
void inOrder(TreapNode* t) {
    if (!t) return;
    inOrder(t->left);
    cout << t->key << " ";
    inOrder(t->right);
}

int main() {
    srand(time(0));

    int n, q;
    cin >> n >> q;

    TreapNode* root = nullptr;
    for (int i = 1; i <= n; i++) {
        root = insert(root, i);  // Khởi tạo cây với các lá bài ban đầu
    }

    while (q--) {
        int l, r;
        cin >> l >> r;
        l--; r--;  // Chuyển về chỉ số 0-based.

        TreapNode *left, *middle, *right;
        split(root, r + 1, root, right);  // Tách phần sau [r, n]
        split(root, l, left, middle);     // Tách đoạn [l, r]

        // Hợp các phần lại: thêm đoạn [l, r] về cuối
        root = merge(left, right);
        root = merge(root, middle);
    }

    inOrder(root);
    cout << endl;

    return 0;
}
