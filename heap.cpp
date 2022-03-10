// heap.cpp
// Colin baylis 6061543

#include "heap.h"
#include <iostream>
using std::cout;

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
int Heap::min(int index) const
{
  int left = 2 * index;
  int right = 2 * index + 1;
  int n = vdata.size();
  if (left - 1 < n && right - 1 < n) {
    return vdata[left - 1] > vdata[right - 1] ?
    right - 1 : left - 1;
  }
  if (left - 1 < n) {
    return left - 1;
  }
  if (right - 1 < n) {
    return right - 1;
  }
  return 0;
}
void Heap::push(int value){
  vdata.push_back(value);
  int n = vdata.size();
 for (int i = (n / 2); i >= 1; --i)
 {
    int min = min(i);
    if (vdata[min] < vdata[i - 1])
    {
      std::swap(vdata[i - 1], vdata[min]);
    }
  }
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  if (vdata.size() == 0) {
    return;
  }
  std::swap(vdata[0], vdata[vdata.size() - 1]);
  vdata.pop_back();
  int n = vdata.size();
  for (size_t i = n / 2; i >= 1; --i)
  {
    int min = min(i);
    if (vdata[min] < vdata[i - 1])
    {
      std::swap(vdata[i - 1], vdata[min]);
    }
  }
}

// Returns the minimum element in the heap
int Heap::top(){
  return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  return vdata.size() == 0;
}
    
