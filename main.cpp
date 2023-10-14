
#include "AVLTree.hpp"

int main(void)
{
    int arr1[50] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25, 27, 29, 31, 33, 35, 37, 39, 41, 43, 45, 47, 49, 51, 53, 55, 57, 59, 61, 63, 65, 67, 69, 71, 73, 75, 77, 79, 81, 83, 85, 87, 89, 91, 93, 95, 97, 99};
    int arr2[50] = {99, 97, 95, 93, 91, 89, 87, 85, 83, 81, 79, 77, 75, 73, 71, 69, 67, 65, 63, 61, 59, 57, 55, 53, 51, 49, 47, 45, 43, 41, 39, 37, 35, 33, 31, 29, 27, 25, 23, 21, 19, 17, 15, 13, 11, 9, 7, 5, 3, 1};
    int arr3[50] = {17, 55, 91, 13, 67, 7, 27, 53, 95, 89, 39, 31, 79, 11, 83, 41, 29, 71, 63, 3, 73, 15, 49, 33, 75, 21, 99, 37, 23, 61, 47, 9, 65, 19, 43, 87, 35, 59, 93, 5, 77, 1, 81, 25, 69, 51, 97, 45, 57, 85};

    AVLTree<int> asc;
    AVLTree<int> desc;
    AVLTree<int> random;

    for (int x = 0; x < 50; x++)
    {
        asc.insert(arr1[x], asc.root);
    }

    for (int k = 0; k < 50; k++)
    {
        desc.insert(arr2[k], desc.root);
    }

    for (int l = 0; l < 50; l++)
    {
        random.insert(arr3[l], random.root);
    }


    int ascValidate = asc.validate(asc.root);
    int descValidate = desc.validate(desc.root);
    int randomValidate = random.validate(random.root);


    


    return 0;
}