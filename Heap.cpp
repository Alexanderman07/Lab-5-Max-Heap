#include "Heap.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Heap::Heap()
{
   //PrintJob* arr[MAX_HEAP_SIZE];
   numItems = 0;
}

void Heap::trickleDown(int object) //percolate down
{
  int childIndex = 2 * object + 1;
  //int rightchildIndex = 2 * object +2;
  PrintJob* val = arr[object]; //holds the value of the element passed in

 while(childIndex < numItems)
  {
    int Maxindex = -1;
    PrintJob* maxValue = val;
    for(int i = 0; i < 2 && i + childIndex < numItems; i++) //checks left and right child, first loop checks left child, second loop checks right child
    {
      if(arr[i+childIndex] -> getPriority() > maxValue -> getPriority()) //checks which child has the largest value to swap with the root element
      {
        maxValue = arr[i + childIndex];
        Maxindex = i + childIndex;
      }
    }
    if(maxValue -> getPriority() == val -> getPriority()) //if root is largest value, then don't swap anything and exit
    {
      return;
    }
    else
    {
      swap(arr[object], arr[Maxindex]);
      object = Maxindex;
      childIndex = 2 * object + 1;
    }
  }

}

void Heap::enqueue(PrintJob* Job)
{
  if(numItems < MAX_HEAP_SIZE)
  {
    arr[numItems] = Job;
  int position = numItems;
  if(position > 0)
  {
    while(arr[position] -> getPriority() > arr[(position-1)/2] -> getPriority() && position > 0)
//stop when the parent is larger than the current node or reach up to root
    {
      swap(arr[position], arr[(position-1)/2]);
      position = (position-1)/2;
    }
  }
   numItems = numItems + 1;
  }
}

void Heap::dequeue()
{
  if(numItems > 0)
  {
    int position = numItems -1;
  if(position >= 0)
  {
    swap(arr[position], arr[0]); 
    position = 0;
    numItems--;
    trickleDown(position);
  }
  }
  
}

PrintJob* Heap::highest()
{
  if( numItems > 0)
  {
    return arr[0];
  }
  else
  {
    return 0;
  }
}

void Heap::print()
{
  PrintJob* max = highest();
  if(highest())
  {
    cout << "Priority: " << max -> getPriority () << ", Job Number: " << max -> getJobNumber () << ", Number of Pages: " << max -> getPages () << endl;
  }
}
