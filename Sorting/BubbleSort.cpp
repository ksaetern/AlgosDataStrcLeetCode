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

void bubbleSort(vector<int>& listToSort){
    int size = listToSort.size();
    
    for(int front = 0; front < size; front++){
        bool swapped = false;
        for(int back = size - 1; back > front; back--){
            if(listToSort[back - 1] > listToSort[back]){
                swap(listToSort[back - 1], listToSort[back]);
                swapped = true;
            }
        }
        printList(listToSort);
        if(!swapped)
        {
            cout << "List Sorted Early, Break for loop!" << endl;
            cout << "Front = " << front << " < " << size << endl;
            break;
        }
    }
}

int main()
{
    vector<int> listTS = {55,29, 11, 42, 40, 66,1, 97, 3,11,79,8,2,4,7,100,14,5};
    printList(listTS);
    cout<<"Beginning of list\n" << endl;
    
    bubbleSort(listTS);
    
    cout<<"\nAfter Sort"<< endl;
    printList(listTS);

    return 0;
}
