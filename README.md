# Custom-STL-Like-Library

This project is a hand crafted implementation of key data structures in C++14, built similar to the STL used in C++.
It deepens the understanding of not only using these data structures but also what is happening behind the scenes and how they are built from scratch.

---

## Highlights

-**Fully implemented from scratch** - external libraries are used where absolutely necessary.<br>
-**Modular** design - each structure is self-contained. <br>
-Comes with **comprehensive test files** for every structure. <br>
-Clean, header-based includes for easy integration. <br>

---

## Implemented Data Structures

- `Vector` - Dynamic Array (Linear)
- `Stack` - LIFO Structure (Linear)
- `Queue` - FIFO Structure (Linear)
- `Dequeue` - Doubly-ended queue (Linear)
- `LinkedList` - Singly Linked List (Linear)
- `DoublyLinkedList` - Doubly Linked List (Linear)
- `PriorityQueue` - Min Heap (priority based)
- `BST` - Binary Search Tree (Non-Linear)
- `Set` - Implemented using self balancing BST (Non-Linear)
- `Map` - Implemented using self balancing BST (Non-Linear)
- `HashSet` - Key-Value map with chaining (Hash-Based)
- `HashMap` - Set wiht open addressing (Hsh-Based)
- `Trie` - Prefix Tree for string/prefix search (Non-Linear)
- `Graph` - Directed/Undirected Weighted/Unweighted (Non-Linear)

-> All these data structures are **tested independently** under the `src/tests/` directory.

---

## How To Test And Run

-Make sure you are using a **C++14 compiler**

### Compile And Run (Linux/MacOS)

```bash
g++ -std=c++14 src/tests/graphtest.cpp -o graphtest
./graphtest

```

### Compile And Run (Windows/PowerShell)

```bash
g++ -std=c++14 src\\tests//graphtest.cpp -o graphtest.exe
./graphtest.exe

```

---

-**And if that doesn't work** you can always use a code editor to run this code like VSCode, etc.

---

## Upcoming Features

-CLI or minimal GUI interface.

---

## About The Author

**Name** - Abhimanyu Singh
**LinkedIn** - https://www.linkedin.com/in/abhimanyu-singh-87886b28a?utm_source=share&utm_campaign=share_via&utm_content=profile&utm_medium=android_app

---

## License

This project is licensed under the MIT License - see the [LICENSE](./LICENSE.txt) file for details.

---