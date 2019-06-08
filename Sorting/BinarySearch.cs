using System;
class HelloWorld {
    
    static void printR(int[] sortedList, int min, int max){
        Console.WriteLine("Print Range");
        while(min <= max)
            Console.Write(sortedList[min++] + " ");
        Console.Write("\n");
    }
    
    static int binarySearch(int[] sortedList, int number){
        int min = 0;
        int max = sortedList.Length - 1;
        while(min <= max){
            printR(sortedList, min, max);
            int mid = min + ((max - min) / 2);
            if (sortedList[mid] == number)
                return mid;
            if(sortedList[mid] > number)
                max = mid - 1;
            else
                min = mid + 1;
        }
        return (-1);
    }
    
    
  static void Main() {
    Console.WriteLine("Hello World");
    
    int[] arr = {100,1,-34,5,890,4,23,5,76,43,12,87,66,44,12,33,-37};
    Array.Sort(arr);
    int k = 100;
    
    foreach(int elem in arr)
            Console.Write(elem.ToString() + " ");
        Console.Write('\n');
    Console.WriteLine("Looking for {0} in Array", k);
    int index = binarySearch(arr, k);
    Console.WriteLine("We found {0} at index {1}", arr[index], index );

  }
}
