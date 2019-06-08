#include <iostream>
#include <vector>

using namespace std;

void printList(vector<int>& listToSort)
{
    for(const auto& i : listToSort)
        cout << i << ' ';
    cout << endl;
}

void printRange(vector<int>& listToSort, int low, int high)
{
    for(int i = low; i <= high; i++)
        cout << listToSort[i] << ' ';
    cout << endl;
}

void swap(vector<int>& a, vector<int>& b)
{
    vector<int> tmp = a;
    a = b;
    b = tmp;
}

int partition(vector<int>& listToSort, int low, int high){
    
    int pivot = listToSort[low];
    int l = low;
    int h = high;
    cout << "Pivot = " << pivot << endl;
    printRange(listToSort, low, high);
    while(l < h){
        while(listToSort[l] <= pivot && l < h)
            l++;
        while(listToSort[h] > pivot)
            h--;
        if(l < h){
            cout << "Swap(in while loop) " << listToSort[l] << " with " << listToSort[h] << endl;
            swap(listToSort[l], listToSort[h]);
        }
            
    }
    cout << "Swap(pivot) " << listToSort[low] << " with " << listToSort[h] << endl;
    swap(listToSort[low], listToSort[h]);
    printRange(listToSort, low, high);
    cout << endl;
    return h;
}

void quickSort(vector<int>& listToSort, int low, int high){
    
    if(low >= high)
    {
        cout << "End Recursion with " << listToSort[low] << endl;
        return;
    }
        
        
    int pivotIndex = partition(listToSort, low, high);
    cout << "Recursion start:" << endl;
    cout << "Pivot1[" << listToSort[low] << "] and Pivot2[" << listToSort[(pivotIndex + 1)] << "]" << endl;
    printList(listToSort);
    cout<< endl;
    quickSort(listToSort, low, pivotIndex - 1);
    quickSort(listToSort, pivotIndex + 1, high);
    
}

int main()
{
    vector<int> listTS = {55,29, 11, 42, 40, 66,1, 97, 3,11,79,8,2,4,7,100,14,5};
    
    printList(listTS);
    cout<<"Beginning of list\n" << endl;
    quickSort(listTS, 0, listTS.size() - 1);
    
    cout<<"After Sort"<< endl;
    printList(listTS);

    return 0;
}