#include "AVLNode.hpp"
#include <algorithm>
#include <cstdlib>
using namespace std;

template <class T>
class AVLTree
{
public:

    int getHeight(AVLNode<T>* node)
    {
        return node->getHeight();
    }

    AVLNode<T>* getRoot(void)
    {
        return this->root;
    }

    int getBalance(AVLNode<T>* node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        else
        {
            return getHeight(node->left) - getHeight(node->right);
        }
    }

    void updateHeight(AVLNode<T>* x)
    {
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
    }

    void rightNodeRotate(AVLNode<T>* & r);
    void leftNodeRotate(AVLNode<T>* & r);
    void doubleWithLeftChild(AVLNode<T>* & r);
    void doubleWithRightChild(AVLNode<T>* & r);

    void insert(int x, AVLNode<T>* & t);

    int contains(AVLNode<T>* & r, int searchVal);

    int validate(AVLNode<T>* & r);


    AVLNode<T>* root;
private:
    
};


template <class T> void AVLTree<T>::rightNodeRotate(AVLNode<T>* & r)
{
    // rotation

    AVLNode<T>*k1 = r->right;
    r->right = k1->left;
    k1->left = r;


    // update heights

    updateHeight(r);
    updateHeight(k1);

    r = k1;

}

template <class T> void AVLTree<T>::leftNodeRotate(AVLNode<T>* & r)
{
    // rotation

    AVLNode<T>*k1 = r->left;
    r->left = k1->right;
    k1->right = r;

    // update heights

    updateHeight(r);
    updateHeight(k1);

    r = k1;
    
}

template <class T> void AVLTree<T>::doubleWithLeftChild(AVLNode<T>* & r)
{
    rightNodeRotate(r->left);
    leftNodeRotate(r);
}

template <class T> void AVLTree<T>::doubleWithRightChild(AVLNode<T>* & r)
{
    leftNodeRotate(r->right);
    rightNodeRotate(r);
}

template <class T> void AVLTree<T>::insert(int x, AVLNode<T>* & t)
{
    if (t == NULL)
    {
        t = new AVLNode<T>(x);
    }

    else if(x < t->data)
    {
        insert(x, t->left);
        if (t->left->getHeight() - t->right->getHeight() == 2)
        {
            if (x < t->left->getData())
            {
                leftNodeRotate(t); // case 1
            }
            else
            {
                doubleWithLeftChild(t); // case 2
            }
        }

    }
    else if(t->data < x)
    {
        insert(x, t->right);
        if(t->right->getHeight() - t->left->getHeight() == 2)
        {
            if (t->right->data < x)
            {
                rightNodeRotate(t); // case 4
            }
            else
            {
                doubleWithRightChild(t); // case 3
            }
        }
        
    }
    else
    {
        return;
    }

    updateHeight(t);

}

template <class T> int AVLTree<T>::contains(AVLNode<T>* & r, int searchVal)
{
    if (root == NULL)
        {
            return 0; // base case if key is not found
        }
        if (root->data == searchVal)
        {
            return 1; // base case if key is found
        }
        if (searchVal < root->data)
        {
            return search(r->left, searchVal); // if searchVal is less that the root we know we need to traverse the left subtree
        }
        if (searchVal > root->data)
        {
            return search(r->right, searchVal); // if searchVal is greater than the root we know we need to traverse through the right subtree
        }
}

template <class T> int AVLTree<T>::validate(AVLNode<T>* & r)
{
        if (r == NULL)
        {
            return 1; // tree is balanced isnce it is empty
        }

        int rHeight = r->right->getHeight();
        int lHeight = r->left->getHeight();

        if (abs(lHeight - rHeight) <= 1 && validate(r->left) && validate (r->right))
        {
            return 1;
        }

        return 0; // tree is not balanced
}


