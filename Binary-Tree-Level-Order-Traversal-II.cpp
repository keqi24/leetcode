/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        stack<vector<int>> resultStack;
        if(root != NULL) {
            
            vector<TreeNode*> *ptrV = new vector<TreeNode*>();
            ptrV->push_back(root);
            
            while(ptrV->size() > 0) {
                vector<TreeNode*> *ptrNextLevel = new vector<TreeNode*>();
                vector<int> resultV;
                for(vector<TreeNode*>::iterator iter = ptrV->begin(); iter!=ptrV->end(); ++iter) {
                    TreeNode *node = *iter;
                    
                    resultV.push_back(node->val);
                    
                    if(node->left != NULL) {
                        ptrNextLevel->push_back(node->left);
                    } 
                    if(node->right != NULL) {
                       ptrNextLevel->push_back(node->right);
                    }
                }
                resultStack.push(resultV);
                ptrV = ptrNextLevel;
            }
            
        }
        return convertStack2Vector(resultStack);
        // return resultVector;
        
    }
    
    vector<vector<int>> convertStack2Vector(stack<vector<int>> stacks) {
        vector<vector<int>> result;
        while(!stacks.empty()) {
            result.push_back(stacks.top());
            stacks.pop();
        }
        
        return result;
    }
};