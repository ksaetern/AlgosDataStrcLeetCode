#include <iostream>
#include <vector>

using namespace std;

void printList(vector<int>& listToSort)
{
    for(const auto& i : listToSort)
        cout << i << ' ';
    cout << endl;
}

void swap(vector<int>& a, vector<int>& b)
{
    vector<int> tmp = a;
    a = b;
    b = tmp;
}

void insertionSort(vector<int>& listToSort){
    int size = listToSort.size() - 1;
    
    for(int i = 0; i < size; i++){
        for(int j = i + 1; j > 0; j--){
            if(listToSort[j] < listToSort[j - 1])
                swap(listToSort[j], listToSort[j - 1]);
            else
                break;
        }
        printList(listToSort);
    }
}

int main()
{
    vector<int> listTS = {55,29, 11, 42, 40, 66,1, 97, 3,11,79,8,2,4,7,100,14,5};
    printList(listTS);
    cout<<"Beginning of list\n" << endl;
    
    insertionSort(listTS);
    
    cout<<"\nAfter Sort"<< endl;
    printList(listTS);

    return 0;
}
