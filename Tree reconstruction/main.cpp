#include <iostream>
using namespace std;

struct TNode
{
    int num;
    TNode* left;
    TNode* right;
};

static int SIZE;
static int* Array;
static int arrayCounter = 0;

int search(int* inOrder, int startIndex, int endIndex, int aData)
{
    for (int i = startIndex; i <= endIndex; i++)
    {
        if (inOrder[i] == aData)
        {
            return i;
        }
    }
    return 0;
}
static int preIndex = 0;

TNode *getLeaf(int data) {
    TNode *leaf = new TNode();
    leaf -> num = data;
    leaf -> left = NULL;
    leaf -> right = NULL;
    return leaf;
}

TNode* buildTree(int *inorder, int *preorder, int startIndex, int endIndex)
{
    if (startIndex > endIndex) {
        return NULL;
    }
    
    TNode* leaf = getLeaf(preorder[preIndex++]);
    
    if (startIndex == endIndex) {
        return leaf;
    }
    
    int inorder_ind = search(inorder, startIndex, endIndex, leaf->num);

    leaf->left = buildTree(inorder, preorder, startIndex, inorder_ind-1);
    leaf->right = buildTree(inorder, preorder, inorder_ind + 1, endIndex);

    return leaf;
}

void Postorder(TNode* ptr)
{
    if (ptr != NULL)
    {
        Postorder(ptr->left);
        Postorder(ptr->right);
        Array[arrayCounter++] = ptr->num;
    }
}

int main()
{
    int T = 0;
    cin >> T;
    
    while (T--) {
        int size;
        cin >> size;
        SIZE = size;
        
        Array = new int[SIZE];
        arrayCounter = 0;
        
        int* preorder = new int[size];
        int* inorder = new int[size];
        
        for (int j = 0; j < size; j++) {
            int temp;
            cin >> temp;
            preorder[j] = temp;
        }
        
        for (int j = 0; j < size; j++) {
            int temp;
            cin >> temp;
            inorder[j] = temp;
        }
        
        TNode* root = buildTree(inorder, preorder, 0, size - 1);
        
        Postorder(root);
        
        root = NULL;
        
        for (int j = 0; j < size; j++)
        {
            if (j < size - 1)
                cout << Array[j] << " ";
            else
                cout << Array[j] << endl;
        }
        preIndex = 0;
    }
    return 0;
}
