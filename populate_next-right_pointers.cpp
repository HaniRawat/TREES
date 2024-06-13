/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
void Solution::connect(TreeLinkNode* A) {

    for (auto level=A;level != NULL;){

        while (level != NULL && level->left == NULL && level->right == NULL)
            level = level->next;

        if (level == NULL)break;

        auto prev = level->left;

        if (prev == NULL)
            prev = level->right;

        for (auto cur = level;cur != NULL; cur=cur->next){

            if (cur->left != NULL){

                if (prev != cur->left){

                    prev->next = cur->left;

                }

                prev = cur->left;

            }

            if (cur->right != NULL){

                if (prev != cur->right){

                    prev->next = cur->right;

                }

                prev = cur->right;

            }

        }

        if (level->left != NULL)
            level = level->left;

        else if (level->right != NULL)
            level = level->right;

    }

}