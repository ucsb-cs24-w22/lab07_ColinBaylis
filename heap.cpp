// heap.cpp
// Colin Baylis 6061543

#include "heap.h"
#include <iostream>
using std::cout;

// Helper Functions
void Heap::goUp(int index){
  while(index > 0){
    int parInd = (index - 1)/2;
    if(vdata[index] >= vdata[parInd]){
      return;
    }
    else{
      int temp = vdata[index];
      vdata[index] = vdata[parInd];
      vdata[parInd] = temp;
      index = parInd;
    }
  }
}

void Heap::goDown(int index){
  int newIndex = 2 * index + 1;
  int value = vdata[index];
  while(newIndex < vdata.size()){
    int minVal = value;
    int minInd = -1;
    int i = 0;
    while (i < 2 && i + newIndex < vdata.size()) {
      if (vdata[i + newIndex] < minVal){
        minVal = vdata[i + newIndex];
        minInd = i + newIndex;
      }
      i++;
    }
    if(minVal == value){
      return;
    }
    else{
      int temp = vdata[index];
      vdata[index] = vdata[minInd];
      vdata[minInd] = temp;
      index = minInd;
      newIndex = 2 * index + 1;
    }
  }
}

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
  vdata.push_back(value);
  goUp(vdata.size()-1);
}

// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  if(vdata.size() == 0){
    return;
  }
  if(vdata.size() == 1){
    vdata.erase(vdata.begin());
    return;
  }
  int repVal = vdata[vdata.size() - 1];
  vdata[0] = repVal;
  vdata.pop_back();
  goDown(0);
}

// Returns the minimum element in the heap
int Heap::top(){
  if(vdata.size() == 0) {
    return -1;
  }
  return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  vdata.size() == 0;
}
    
