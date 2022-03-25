#ifndef __HEAP_H
#define __HEAP_H

#include "PrintJob.h"

const int MAX_HEAP_SIZE = 10;

class Heap {
private:
  PrintJob* arr[MAX_HEAP_SIZE];
  int numItems;

public:
  Heap();
  void enqueue ( PrintJob* Job);
  void dequeue ( );
  PrintJob* highest ( );
  void print ( );

private:
  void trickleDown(int);
};
#endif
