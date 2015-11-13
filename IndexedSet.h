// ----------------------------------------------------------------------------
// IndexedSet.h
//
//
// Authors:
// Peter Polidoro polidorop@janelia.hhmi.org
// ----------------------------------------------------------------------------
#ifndef INDEXED_SET_H
#define INDEXED_SET_H
#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif
#include "Array.h"


template <typename T, int max_size_>
class IndexedSet
{
public:
  IndexedSet();
  T& operator[](const int i);
  T& at(const int i);
  void clear();
  int findIndex(const T &value);
  int add(const T &value);
  void removeUsingIndex(const int index);
  void removeUsingValue(const T &value);
  bool indexHasValue(const int index);
  int size();
  int max_size();
  bool empty();
  bool full();

private:
  Array<T,max_size_> values_;
  Array<bool,max_size_> available_;
  int size_;
};
#include "IndexedSetDefinitions.h"

#endif
