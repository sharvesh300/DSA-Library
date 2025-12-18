# DSA (Data Structures and Algorithms) Implementation Project

## Overview
This project provides comprehensive implementations of fundamental data structures commonly used in computer science. All implementations are templated C++ classes supporting generic programming. The project includes complete working examples for each data structure.

---

## Table of Contents
1. [Linear Data Structures](#linear-data-structures)
2. [Tree Data Structures](#tree-data-structures)
3. [Advanced Data Structures](#advanced-data-structures)
4. [Sorting Algorithms](#sorting-algorithms)
5. [Utility Data Structures](#utility-data-structures)

---

## Linear Data Structures

### 1. Stack

**File:** `Stack.hpp`

**Description:**
A Last-In-First-Out (LIFO) data structure implemented using a singly linked list. Elements are added and removed from the top of the stack.

**Implementation Details:**
- Uses dynamic memory allocation with nodes
- Head pointer tracks the top of the stack
- Size tracking for efficient operations

**Operations:**

| Operation | Time Complexity | Space Complexity | Description |
|-----------|-----------------|------------------|-------------|
| `push(T data)` | O(1) | O(1) | Insert element at top |
| `pop()` | O(1) | O(1) | Remove and return top element |
| `peek()` | O(1) | O(1) | Return top element without removing |
| `isEmpty()` | O(1) | O(1) | Check if stack is empty |

**Space Complexity:** O(n) where n is the number of elements

**Use Cases:**
- Expression evaluation (infix to postfix conversion)
- Function call stack in programming languages
- Undo/Redo functionality
- Depth-first search (DFS)
- Balanced parentheses checking

**Example Usage:**
```cpp
Stack<int> stack;
stack.push(10);
stack.push(20);
std::cout << stack.pop(); // Output: 20
```

---

### 2. Fixed Stack

**File:** `fixed_stack.hpp`

**Description:**
A Stack implementation with fixed capacity using a dynamic array. Better cache locality than linked list implementation.

**Implementation Details:**
- Array-based storage with fixed capacity
- Capacity must be specified at construction
- Throws exceptions on overflow/underflow

**Operations:**

| Operation | Time Complexity | Space Complexity | Description |
|-----------|-----------------|------------------|-------------|
| `push(T x)` | O(1) | O(1) | Insert element (throws if full) |
| `pop()` | O(1) | O(1) | Remove and return top element |
| `peek()` | O(1) | O(1) | Return top element without removing |
| `isEmpty()` | O(1) | O(1) | Check if empty |
| `size()` | O(1) | O(1) | Return current size |

**Space Complexity:** O(capacity) - fixed at initialization

**Advantages over Linked List Stack:**
- Better cache locality
- No dynamic allocation overhead
- Constant space guarantee

**Disadvantages:**
- Fixed size limitation
- Wasted space if underutilized

---

### 3. Queue

**File:** `queue.hpp`

**Description:**
A First-In-First-Out (FIFO) data structure implemented using a singly linked list with both head and tail pointers for efficiency.

**Implementation Details:**
- Two pointers: `first` (front) and `last` (rear)
- Elements enqueued at rear, dequeued from front
- Dynamic node allocation

**Operations:**

| Operation | Time Complexity | Space Complexity | Description |
|-----------|-----------------|------------------|-------------|
| `enqueue(T data)` | O(1) | O(1) | Insert element at rear |
| `dequeue()` | O(1) | O(1) | Remove and return front element |
| `isEmpty()` | O(1) | O(1) | Check if queue is empty |

**Space Complexity:** O(n) where n is the number of elements

**Use Cases:**
- Task scheduling
- Breadth-first search (BFS)
- Print queue management
- Message queues
- Customer service lines (FIFO order)

**Example Usage:**
```cpp
Queue<int> queue;
queue.enqueue(10);
queue.enqueue(20);
std::cout << queue.dequeue(); // Output: 10
```

---

### 4. Vector

**File:** `Vector.hpp`

**Description:**
A dynamic array implementation similar to `std::vector`. Automatically grows when full using amortized doubling strategy.

**Implementation Details:**
- Dynamic array with capacity tracking
- Automatic resizing: capacity = 2*size + 1
- Supports range-based iteration
- Copy assignment operator included

**Operations:**

| Operation | Time Complexity | Amortized | Space Complexity | Description |
|-----------|-----------------|-----------|------------------|-------------|
| `push_back(element)` | O(1)* | O(1) | O(n) | Insert at end |
| `pop_back()` | O(1) | O(1) | O(1) | Remove last element |
| `back()` | O(1) | O(1) | O(1) | Return last element |
| `operator[]` | O(1) | O(1) | O(1) | Random access |
| `reserve(capacity)` | O(n) | - | O(n) | Allocate new capacity |
| `resize(size)` | O(n) | - | O(n) | Change size |

*O(n) when reallocation occurs, but amortized to O(1)

**Space Complexity:** O(capacity) = O(n) where n is current size

**Advantages:**
- O(1) random access
- Cache-friendly sequential storage
- Iterator support
- Copy semantics

**Disadvantages:**
- Reallocation overhead when growing
- Insertion/deletion in middle is O(n)

---

### 5. LinkedList

**File:** `LinkedList.hpp`

**Description:**
A singly linked list with head and tail pointers. Supports advanced operations like sorting, reversal, and element swapping.

**Implementation Details:**
- Singly linked nodes with data payload
- Maintains both head and tail pointers
- Helper function `findElement(index)` for position access

**Operations:**

| Operation | Time Complexity | Description |
|-----------|-----------------|-------------|
| `insertAtHead(element)` | O(1) | Insert at beginning |
| `insertBySorting(element)` | O(n) | Insert while maintaining sorted order |
| `swap(i, j)` | O(n) | Swap elements at positions i and j |
| `reverseList()` | O(n) | Reverse the entire list |
| `printList()` | O(n) | Print all elements |
| `findElement(index)` | O(n) | Find node at position |

**Space Complexity:** O(n) where n is the number of elements

**Use Cases:**
- Dynamic collections where insertion/deletion at head is frequent
- LRU cache implementation
- Polynomial representation
- Adjacency lists in graphs

---

### 6. List (Doubly Linked List)

**File:** `List.hpp`

**Description:**
A fully-featured doubly linked list with bidirectional iterators and splice operations.

**Implementation Details:**
- Doubly linked nodes with forward and backward pointers
- Head and tail sentinel pointers
- Provides both `iterator` and `const_iterator`
- Supports bidirectional traversal

**Operations:**

| Operation | Time Complexity | Description |
|-----------|-----------------|-------------|
| `add(element)` | O(1) | Insert at end |
| `splice(position, list)` | O(1) | Move all elements from another list |
| `begin()`, `end()` | O(1) | Get iterators |
| `printList()` | O(n) | Print all elements |

**Iterator Operations:**

| Operation | Complexity | Description |
|-----------|-----------|-------------|
| `++` (prefix/postfix) | O(1) | Move forward |
| `--` (prefix/postfix) | O(1) | Move backward |
| `+` | O(k) | Move forward k positions |
| `*` (dereference) | O(1) | Access element |
| `==`, `!=` | O(1) | Compare iterators |

**Space Complexity:** O(n) where n is the number of elements

**Advantages over Singly Linked List:**
- Bidirectional traversal
- Efficient reversal
- Better iterator support

---

## Tree Data Structures

### 1. Binary Search Tree (BST)

**File:** `BST.hpp`

**Description:**
A binary tree where for each node, all elements in the left subtree are smaller and all elements in the right subtree are larger.

**Implementation Details:**
- Stores key-value pairs for dictionary use
- Supports both recursive and iterative insertion
- Uses in-order traversal for sorted output
- Supports key deletion with successor replacement

**Operations:**

| Operation | Best Case | Average Case | Worst Case | Space |
|-----------|-----------|--------------|-----------|-------|
| `insert(key, value)` | O(log n) | O(log n) | O(n) | O(1) |
| `search(key)` | O(log n) | O(log n) | O(n) | O(1) |
| `deleteKey(key)` | O(log n) | O(log n) | O(n) | O(1) |
| `PrintTree()` | O(n) | O(n) | O(n) | O(h) |

**Space Complexity:** O(n) tree storage + O(h) recursion stack

**Deletion Strategy:**
- Node with no children: simply remove
- Node with one child: replace with child
- Node with two children: replace with in-order successor, then delete successor

**Use Cases:**
- Dictionary implementations
- File systems
- Database indexing
- Expression parsing

**Worst Case Analysis:**
When inserting sorted data (1,2,3,4,5...), BST degenerates to a linked list with O(n) height, causing all operations to become O(n).

---

### 2. AVL Tree

**File:** `AVL_Tree.hpp`

**Description:**
A self-balancing binary search tree where the height difference between left and right subtrees is at most 1 for every node.

**Implementation Details:**
- Each node stores explicit height information
- Four rotation types: Left, Right, Left-Right, Right-Left
- Height updated after insertions
- Balance check performed after each insertion

**Operations:**

| Operation | Time Complexity | Space Complexity |
|-----------|-----------------|------------------|
| `insert(data)` | O(log n) | O(1) per node |
| `search(data)` | O(log n) | O(log n) recursion |
| `delete(data)` | O(log n) | O(log n) recursion |

**Height Complexity:** O(log n) guaranteed

**Overall Space:** O(n) tree + O(log n) recursion stack

**Rotation Types:**

1. **Left Rotation:** Right-heavy case
   - Right child becomes new root
   - Original root becomes left child
   - Left subtree of right child becomes right subtree of root

2. **Right Rotation:** Left-heavy case
   - Left child becomes new root
   - Original root becomes right child
   - Right subtree of left child becomes left subtree of root

3. **Left-Right Rotation:** Left child is right-heavy
   - First rotate left child left
   - Then rotate node right

4. **Right-Left Rotation:** Right child is left-heavy
   - First rotate right child right
   - Then rotate node left

**Balancing Condition:** |height(left) - height(right)| ≤ 1

**Use Cases:**
- Database indexing requiring logarithmic guarantees
- Filesystem implementations (NTFS uses B-trees based on AVL concepts)
- In-memory indexing
- Any application requiring worst-case O(log n) operations

---

### 3. Binary Search Tree - Lazy Deletion

**File:** `BST_Lazy.hpp`

**Description:**
BST variant using lazy deletion where nodes are marked as deleted rather than physically removed.

**Implementation Details:**
- Each node has `isDeleted` boolean flag
- Deletion simply sets flag, doesn't restructure tree
- Print operation skips deleted nodes
- Physical cleanup deferred

**Operations:**

| Operation | Time Complexity | Description |
|-----------|-----------------|-------------|
| `Insert(key, value)` | O(log n) avg | Insert normally |
| `Delete(key)` | O(log n) avg | Mark node as deleted |
| `PrintTree()` | O(n) | Print non-deleted nodes |
| `findMin()` | O(log n) avg | Find minimum non-deleted |

**Advantages:**
- No restructuring overhead on deletion
- Faster deletion operations
- Reversible deletion (can un-delete)

**Disadvantages:**
- Tree may accumulate deleted nodes
- Search still traverses deleted nodes
- Requires periodic cleanup

---

## Advanced Data Structures

### 1. Priority Queue (Max Heap)

**File:** `PriorityQueue.hpp`

**Description:**
A max-heap implementation based on array storage. Elements are organized in a complete binary tree structure where parent ≥ children.

**Implementation Details:**
- Array-based complete binary tree
- Fixed capacity specified at construction
- Parent of node i: (i-1)/2
- Left child of node i: 2i+1
- Right child of node i: 2i+2
- Two heap operations: `fixUp()` and `fixDown()`

**Operations:**

| Operation | Time Complexity | Space Complexity |
|-----------|-----------------|------------------|
| `insert(data)` | O(log n) | O(1) |
| `getmax()` | O(log n) | O(1) |
| `changePriority(data, k)` | O(log n) | O(1) |
| `isEmpty()` | O(1) | O(1) |
| `size()` | O(1) | O(1) |

**Space Complexity:** O(capacity) - fixed allocation

**Heap Properties:**
- Max Heap Property: parent ≥ both children
- Complete Binary Tree: all levels filled except last (filled left to right)

**fixUp Operation (Insertion):**
1. Insert element at end
2. Compare with parent
3. If greater than parent, swap and repeat with parent

**fixDown Operation (Deletion):**
1. Replace root with last element
2. Compare with largest child
3. If child is larger, swap and repeat with child

**Use Cases:**
- Priority scheduling
- Huffman coding
- Dijkstra's algorithm
- Heap sort implementation
- Event-driven simulation

---

### 2. Tries (Prefix Trees)

**File:** `tries.hpp`

**Description:**
A tree data structure for storing strings with fast prefix lookup. Each node represents a character, and paths from root represent words.

**Implementation Details:**
- 26 child pointers per node (for lowercase letters)
- Boolean flag `isLeaf` marks word endings
- Automatically filters non-lowercase characters

**Operations:**

| Operation | Time Complexity | Space Complexity |
|-----------|-----------------|------------------|
| `insert(word)` | O(m) | O(m) per word |
| `search(word)` | O(m) | O(1) |
| `isPrefix(prefix)` | O(m) | O(1) |
| `print()` | O(n*m) | O(h) |

Where:
- m = length of word/prefix
- n = number of words
- h = height of trie

**Overall Space:** O(ALPHABET_SIZE * N * M) in worst case, typically much better

**Structure:**
```
Root -> (26 children)
   |
   +-> 'a' -> (26 children) -> leaf if 'a' is a word
   |
   +-> 'b' -> ...
```

**Use Cases:**
- Autocomplete functionality
- Spell checking
- IP routing (routing tables)
- Dictionary implementations
- T9 mobile phone input
- Search engine index

**Advantages:**
- Prefix matching in O(m)
- No collision handling
- Memory efficient for many short strings

---

## Sorting Algorithms

### 1. Heap Sort

**File:** `HeapSort.hpp`

**Description:**
In-place sorting algorithm that uses a max-heap data structure. Divides into heapification and extraction phases.

**Implementation Details:**
- Converts array into max-heap (heapify)
- Repeatedly extracts max and places at end
- Supports both iterative and recursive `fixDown`
- In-place operation (O(1) extra space)

**Algorithm Steps:**
1. **Heapify Phase:** O(n)
   - Convert array into max-heap
   - Start from n/2-1 down to 0
   - Call `fixDown()` for each position

2. **Extraction Phase:** O(n log n)
   - Repeat n-1 times:
     - Swap root (max) with last element
     - Reduce heap size
     - Restore heap property with `fixDown()`

**Operations:**

| Phase | Time Complexity | Description |
|-------|-----------------|-------------|
| `heapify()` | O(n) | Build heap from array |
| `fixDown()` | O(log n) | Restore heap property |
| `sort()` | O(n log n) | Complete sort |

**Complexity Analysis:**

| Metric | Complexity |
|--------|-----------|
| Best Case | O(n log n) |
| Average Case | O(n log n) |
| Worst Case | O(n log n) |
| Space | O(1) - in-place |
| Stability | Not stable |

**Advantages:**
- Guaranteed O(n log n) worst case
- In-place sorting (O(1) extra space)
- No external comparisons needed
- Cache-friendly array access

**Disadvantages:**
- Not stable (equal elements may change order)
- Slower in practice than Quick Sort for large datasets
- Overhead from heap operations

**Use Cases:**
- Real-time systems requiring guaranteed performance
- Embedded systems with memory constraints
- Priority queue-based applications
- When worst-case guarantee is critical

---

## Utility Data Structures

### 1. Dictionary

**File:** `Dictionary.hpp`

**Description:**
Provides a key-value storage interface, typically backed by BST or hash table.

---

### 2. Merge Priority Queue

**File:** `MergePriorityQueue.hpp`

**Description:**
Advanced priority queue supporting merge operations, useful for combining multiple priority queues.

---

### 3. Bit Solver

**File:** `BitsSolver.hpp`

**Description:**
Utility class for bit manipulation operations and bit-related problems.

---

## Application Files

Each data structure has an accompanying `*App.hpp` file with usage examples:

- `StackApp.hpp` - Stack operations including expression conversion
- `QueueApp.hpp` - Queue operations and BFS examples
- `VectorApp.hpp` - Dynamic array usage
- `LinkedListApp.hpp` - LinkedList operations
- `ListApp.hpp` - Doubly linked list with iterators
- `BSTApp.hpp` - Binary search tree operations
- `AVL_TreeApp.hpp` - AVL tree insertion and balancing
- `TriesApp.hpp` - Trie insert and search
- `HeapSortApp.hpp` - Heap sort demonstrations
- `ProrityQueueApp.hpp` - Priority queue operations
- `FixedStackApp.hpp` - Fixed capacity stack
- `BST_Lazy_App.hpp` - Lazy deletion BST

---

## Template-Based Generic Programming

All data structures use C++ templates for type safety and reusability:

```cpp
// Generic instantiation
Stack<int> intStack;
Stack<string> stringStack;
Vector<double> doubleVector;
BST<string, int> dictionary;
```

**Benefits:**
- Type-safe at compile time
- No runtime type checking overhead
- Works with any comparable type
- Code reuse without duplication

---

## Compilation

The project uses CMake for building:

```bash
cmake -B cmake-build-debug
cmake --build cmake-build-debug
./cmake-build-debug/Sharvesh_355
```

---

## Summary Table: Time & Space Complexity

| Data Structure | Insert | Search | Delete | Space | Best Use Case |
|---|---|---|---|---|---|
| Stack | O(1) | O(n) | O(1) | O(n) | LIFO, DFS, expression evaluation |
| Queue | O(1) | O(n) | O(1) | O(n) | FIFO, BFS, scheduling |
| Vector | O(1)* | O(1)** | O(n) | O(n) | Random access, dynamic array |
| LinkedList | O(1) | O(n) | O(n) | O(n) | Head insertion, no reallocation |
| List (DLL) | O(1) | O(n) | O(n) | O(n) | Bidirectional iteration |
| BST | O(log n)*** | O(log n)*** | O(log n)*** | O(n) | Dictionary, ordered data |
| AVL Tree | O(log n) | O(log n) | O(log n) | O(n) | Guaranteed logarithmic |
| Priority Queue | O(log n) | O(1) | O(log n) | O(n) | Heap operations, scheduling |
| Tries | O(m) | O(m) | O(m) | O(ALPHABET*n*m) | Prefix search, autocomplete |
| Heap Sort | - | - | - | O(1) | Guaranteed O(n log n) sort |

*O(n) when reallocation needed, amortized O(1)
**O(n) in middle of array, O(1) at end
***O(n) worst case if unbalanced

---

## Key Learnings & Technical Details

### Memory Management
- All implementations use dynamic memory allocation
- Destructors properly deallocate resources
- No memory leaks in provided implementations

### Generic Programming
- Template specialization for different types
- Compile-time polymorphism
- Type-safe operations

### Algorithm Analysis
- Understanding Big-O notation for informed selection
- Trade-offs between time and space complexity
- Amortized analysis for dynamic operations

### Data Structure Selection
- Balance between operation costs
- Memory constraints
- Real-time requirements
- Worst-case vs. average-case performance

---

## References

- Introduction to Algorithms (CLRS)
- Data Structures and Algorithm Analysis (Mark Allen Weiss)
- C++ STL Design Philosophy and Implementation

