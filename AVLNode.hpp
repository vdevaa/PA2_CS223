#include <iostream>

using namespace std;

template <class T>
class AVLNode
{
public:

    T data;
    AVLNode* left;
    AVLNode* right;
    int height;

    
    // constructor
    AVLNode(T newData);
    
    //setter
    void setData(T newData);
    void setLeft(AVLNode& newNode);
    void setRight(AVLNode& newNode);
    void setHeight(int newHeight);


    T getData(void);
    
    AVLNode* getRight(void)
    {
        return this->right;
    }
    AVLNode* getLeft(void)
    {
        return this->left;
    }



    T getHeight(void);





private:
    
};

template <class T> AVLNode<T>::AVLNode(T newData)
    {
        this->data = newData;
        this->left = nullptr;
        this->right = nullptr;
        this->height = 0;
    }



//  setters

template <class T> void AVLNode<T>::setData(T newData)
{
    this->data = newData;
}

template <class T> void AVLNode<T>::setLeft(AVLNode& newNode)
{
    this->left = newNode;
}

template <class T> void AVLNode<T>::setRight(AVLNode& newNode)
{
    this->right = newNode;
}

template <class T> void AVLNode<T>::setHeight(int newHeight)
{
    this->height = newHeight;
}

// getters

template <class T> T AVLNode<T>::getData(void)
{
    return this->data;
}

template <class T> T AVLNode<T>::getHeight(void)
{
    return this->height;
}







