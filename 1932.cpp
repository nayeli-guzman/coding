#include <iostream>
#include <unordered_set>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


void merge_aux(TreeNode* node, 
        unordered_map<int,int> &hash,
        vector<TreeNode*> &trees,
        bool conf=false,
        int i=-1
    ) {

    if(node==nullptr) return;

    if(hash.find(node->val)!=hash.end() && hash[node->val]!=-1) {
        node = trees[hash[node->val]];
        hash[node->val] = -1;
        //if(!conf) hash[node->val] = -1;
    } else {
        return;
    }


    int root = node->val;
    int right = node->right==nullptr? -1:node->right->val;
    int left = node->left==nullptr? -1:node->left->val;
    
    if(left!=-1 && hash.find(left)!=hash.end() && hash[left]!=-1) {

        int pos_left = hash[left];

        merge_aux(node->left, hash, trees);

        node->left = trees[pos_left];
        trees[pos_left] = nullptr;
        hash[left] = -1;
    } 
    if(right!=-1 && hash.find(right)!=hash.end() && hash[right]!=-1) {

        int pos_right = hash[right];

        merge_aux(node->right, hash, trees);

        node->right = trees[pos_right];
        trees[pos_right] = nullptr;
        hash[right] = -1;
        
    }

    if(conf) hash[node->val] = i;
    

}

bool is_bst(TreeNode* node, long minVal = INT16_MIN, long maxVal = INT16_MAX) {
    if (node == nullptr) {
        return true;
    }
    
    if (node->val <= minVal || node->val >= maxVal) {
        return false;
    }

    return is_bst(node->left, minVal, node->val) && 
           is_bst(node->right, node->val, maxVal);
}

TreeNode* canMerge(vector<TreeNode*>& trees) {

    unordered_map<int, int> hash; // idx, val

    for(int i=0; i<trees.size(); i++) {
        hash[trees[i]->val] = i;
    }

    for(int i=0; i<trees.size(); i++) {
        merge_aux(trees[i], hash, trees, true, i);    
    }

    for(auto e:trees) {
        if(e==nullptr)
            cout <<0 << endl;
        else
            cout << e->val << endl;
    }

    TreeNode* result = nullptr;
    int cont=0;

    for(int i=0; i<trees.size(); i++) {
        if(trees[i]!=nullptr) {
            cont++;
            result = trees[i];
        }
        if(cont>1) return nullptr;
    } 

    if(is_bst(result))
        return result;
    return nullptr;

}

int main(){

    TreeNode* r1 = new TreeNode(4);
    r1->left = new TreeNode(3);
    // r1->right = new TreeNode(21);

    TreeNode* r2 = new TreeNode(10);
    // r2->right = new TreeNode(1);
    r2->left = new TreeNode(9);

    TreeNode* r3 = new TreeNode(11);
    r3->left = new TreeNode(10);
    // r3->right = new TreeNode(8);

    
    TreeNode* r4 = new TreeNode(5);
    r4->left = new TreeNode(4);
    // r4->right = new TreeNode(7);

    TreeNode* r5 = new TreeNode(9);
    r5->left = new TreeNode(8);
    // r5->right = new TreeNode(11);

    TreeNode* r6 = new TreeNode(6);
    r6->left = new TreeNode(5);
    // r4->right = new TreeNode(7);

    TreeNode* r7 = new TreeNode(7);
    r7->left = new TreeNode(6);
    // r4->right = new TreeNode(7);

    TreeNode* r8 = new TreeNode(8);
    r8->left = new TreeNode(7);
    // r4->right = new TreeNode(7);
    
    vector<TreeNode*> v = {r1,r2,r3,r4,r5};

    canMerge(v);

    return 0;
}