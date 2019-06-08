using System;
class HelloWorld {
    
    //Split:
    //purpose of the split method is to copy all the elements from the original
    //list into the new sublists
    static void split(int[] listToSort, int[] listFirstHalf, int[] listSecondHalf){
        int index = 0;
        int secondHalfStartIndex = listFirstHalf.Length;
        foreach (int elements in listToSort){
            if(index < secondHalfStartIndex)
                listFirstHalf[index] = listToSort[index];
            else
                listSecondHalf[index - secondHalfStartIndex] = listToSort[index];
            index++;
        }
    }
    
    //Merge:
    //takes two sorted list and merge them in sorted order
    static void merge(int[] listToSort, int[] listFirstHalf,int[] listSecondHalf){
        int mergeIndex = 0;
        int firstHalfIndex = 0;
        int secondHalfIndex = 0;
        
        //do the comparison and add them to listToSort
        while(firstHalfIndex < listFirstHalf.Length && secondHalfIndex < listSecondHalf.Length){
            if(listFirstHalf[firstHalfIndex] < listSecondHalf[secondHalfIndex]){
                listToSort[mergeIndex] = listFirstHalf[firstHalfIndex];
                firstHalfIndex++;
            } else if (secondHalfIndex < listSecondHalf.Length) {
                listToSort[mergeIndex] = listSecondHalf[secondHalfIndex];
                secondHalfIndex++;
            }
            mergeIndex++;
        }
        
        //after, add anything left over in both lists
        if(firstHalfIndex < listFirstHalf.Length){
            while (mergeIndex < listToSort.Length)
                listToSort[mergeIndex++] = listFirstHalf[firstHalfIndex++];
        }
        if (secondHalfIndex < listSecondHalf.Length) {
            while(mergeIndex < listToSort.Length)
                listToSort[mergeIndex++] = listSecondHalf[secondHalfIndex++];
        }
    }
    
    //Actual recursion function for mergeSort
    static void mergeSort(int[] listToSort) {
        if(listToSort.Length == 1) // this is the base case of the recursion
            return;
        
        int midIndex = (listToSort.Length / 2) + (listToSort.Length % 2);//incase its not even
        int[] listFirstHalf = new int[midIndex];
        int[] listSecondHalf = new int[listToSort.Length - midIndex];
        split(listToSort, listFirstHalf, listSecondHalf);
        
        mergeSort(listFirstHalf);
        mergeSort(listSecondHalf);
        
        merge(listToSort, listFirstHalf, listSecondHalf);
        foreach(int elem in listToSort)
            Console.Write(elem.ToString() + " ");
        Console.Write('\n');
    }
    
    
    
  static void Main() {
    Console.WriteLine("Hello World");
    
    int[] arr = {100,1,-34,5,890,4,23,5,76,43,12,87,66,44,12,33,-37};
    mergeSort(arr);
    
    Console.WriteLine("After Sort");
    foreach(int elem in arr)
            Console.Write(elem.ToString() + " ");
        Console.Write('\n');

  }
}