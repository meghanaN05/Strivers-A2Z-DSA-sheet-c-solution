/*
Introduction to Heaps (Binary Heaps)
heaps are a special tree-based data structure that satisfies the heap property. In a binary heap, for any given node, the value of that node is greater than or equal to (in a max heap) or less than or equal to (in a min heap) the values of its children. This property makes heaps useful for implementing priority queues and for efficient sorting algorithms like heapsort.
Key Characteristics of Binary Heaps:
1. Complete Binary Tree: All levels of the tree are fully filled except possibly the last level, which is filled from left to right.
2. Heap Property: For a min heap, the value of each node is less than or equal to the values of its children. For a max heap, the value of each node is greater than or equal to the values of its children.
3. Efficient Operations: Insertion and deletion operations can be performed in O(log n) time, while finding the minimum or maximum element can be done in O(1) time.
Common Operations on Binary Heaps:
1. Insertion: Add a new element to the heap while maintaining the heap property.
2. Deletion: Remove the root element (minimum in a min heap or maximum in a max heap) and reheapify to maintain the heap property.
3. Peek: Retrieve the root element without removing it.
4. Heapify: Convert an arbitrary array into a heap.
time complexity of heap operations:
1. Insertion: O(log n)
2. Deletion: O(log n)
3. Peek: O(1)
4. Heapify: O(n)
5. Building a Heap from an Array: O(n)

*/