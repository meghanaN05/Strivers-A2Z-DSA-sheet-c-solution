#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;
class MinHeap
{
private:
  vector<int> heap;

  // Helper to maintain heap property upwards (used in Insertion)
  void heapifyUp(int index)
  {
    while (index > 0 && heap[(index - 1) / 2] > heap[index])
    {
      swap(heap[index], heap[(index - 1) / 2]);
      index = (index - 1) / 2;
    }
  }

  // Helper to maintain heap property downwards (used in Deletion / Pop / Heapify)
  void heapifyDown(int index, int n)
  {
    while (true)
    {
      int leftChild = 2 * index + 1;
      int rightChild = 2 * index + 2;
      int smallest = index;

      if (leftChild < n && heap[leftChild] < heap[smallest])
      {
        smallest = leftChild;
      }
      if (rightChild < n && heap[rightChild] < heap[smallest])
      {
        smallest = rightChild;
      }

      if (smallest != index)
      {
        swap(heap[index], heap[smallest]);
        index = smallest;
      }
      else
      {
        break;
      }
    }
  }

public:
  // Constructor (can initialize with an empty or unsorted array using heapify)
  MinHeap() {}

  MinHeap(const vector<int> &arr)
  {
    heap = arr;
    // Build heap: start from the last non-leaf node down to the root
    int n = heap.size();
    for (int i = (n / 2) - 1; i >= 0; i--)
    {
      heapifyDown(i, n);
    }
  }

  // 1. Insertion - O(log n)
  void insert(int value)
  {
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
  }

  // 2. Peek / Top - O(1)
  int peek() const
  {
    if (heap.empty())
    {
      throw out_of_range("Heap is empty!");
    }
    return heap[0];
  }

  // 3. Pop / Extract Min - O(log n)
  int pop()
  {
    if (heap.empty())
    {
      throw out_of_range("Heap is empty!");
    }

    int minValue = heap[0];

    // Move the last element to the root and shrink the heap
    heap[0] = heap.back();
    heap.pop_back();

    if (!heap.empty())
    {
      heapifyDown(0, heap.size());
    }

    return minValue;
  }

  // 4. Deletion of a specific value - O(n + log n)
  void deleteValue(int value)
  {
    int index = -1;
    for (int i = 0; i < heap.size(); i++)
    {
      if (heap[i] == value)
      {
        index = i;
        break;
      }
    }

    if (index == -1)
      return; // Value not found

    // Replace with the last element and pop
    heap[index] = heap.back();
    heap.pop_back();

    if (index < heap.size())
    {
      heapifyDown(index, heap.size());
      heapifyUp(index); // Just in case it needs to move up instead
    }
  }

  // Utility to print the heap elements
  void printHeap() const
  {
    for (int val : heap)
    {
      cout << val << " ";
    }
    cout << endl;
  }

  bool isEmpty() const
  {
    return heap.empty();
  }
};

int main()
{
  // Testing Heapify with an initial unsorted array
  vector<int> unsorted = {9, 4, 7, 1, 2, 6};
  cout << "Original Unsorted Array: ";
  for (int val : unsorted)
    cout << val << " ";
  cout << endl;

  MinHeap minHeap(unsorted);
  cout << "Min-Heap after Heapify: ";
  minHeap.printHeap();

  // Testing Insertion
  minHeap.insert(3);
  cout << "After inserting 3: ";
  minHeap.printHeap();

  // Testing Peek
  cout << "Peek (Min element): " << minHeap.peek() << endl;

  // Testing Pop (Extract Min)
  cout << "Popped Min element: " << minHeap.pop() << endl;
  cout << "Heap after Pop: ";
  minHeap.printHeap();

  // Testing Deletion of a specific element
  minHeap.deleteValue(7);
  cout << "Heap after deleting 7: ";
  minHeap.printHeap();

  return 0;
}