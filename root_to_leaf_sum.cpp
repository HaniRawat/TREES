void solve(Node* root, long long& ans, int sum){
    if(root == NULL)
        return;
    
    sum = (sum*10) + root->data;
    solve(root->left,ans, sum);
    solve(root->right,ans, sum);
    
    if(root->left == NULL && root->right == NULL){
        ans += sum;
        sum = 0;
    }
}
long long treePathsSum(Node *root)
{
    long long ans = 0;
    solve(root, ans, 0);
    return ans;
}