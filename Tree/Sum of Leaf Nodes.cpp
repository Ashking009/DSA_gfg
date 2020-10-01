int sumLeaf(Node* root)
{
    int sumleft=0,sumright = 0;
    if(root==NULL)
    return 0;
    if(root->left == NULL && root->right==NULL)
    {
        return root->data;
    }
    sumleft = sumLeaf(root->left);
    sumright = sumLeaf(root->right);
    return sumleft + sumright;
}