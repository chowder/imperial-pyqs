# 2014-2015 Algorithms

## Question 1a

### i.

Parent of `H[k]` is `H[k/2]` (integer division)

Left and right children of `H[k]` are `H[2k]` and `H[2k+1]`

### ii.

1. To remove an object at index `k`, we move the last element in the heap, `H[H.size]` to `H[k]`
2. Then we heapify the array starting from the root `H[k]`
3. To heapify, we compare the key of `H[k]` against its children's, and continue to sift `H[k]` down the tree as necessary until the heap is restored.

## Question 1b

### i.

Probe sequence is a method of collision resolution.

For insertion it describes the sequence in which to look for an empty hash table entry in the case where the result of the hash function results in an already-occupied hash table entry.

### ii.

Linear probing does not produce uniform hashing as the range of results from a hash function is often finite, while the space range of an open address hash table is theoretically infinite.

Therefore as the load factor N/m approaches 1, the hash table suffers from clustering, where there exists long runs of filled slots near the hash position of keys, thus uniformity is not ensured.

### iii.

Consider the following hash table that uses probing

| Hash table  |
|-  |
| A |
| B |
| C |

Where A, B and C hash to the same value. If we remove Object B, a search for C (initially starting from A) will now reveal that C is not present.

Therefore we observe that for deletion, it is necessary to shift elements that hash to the same value appropriately to maintain this locality dependency.

### iv.

The load factor reveals the probability, or average number of elements mapped to the same hash table entry. Given by `N/m` where `N` is the number of elements and `m` is the size of the hash table.

When Professor Alfaman reconstructs the larger hash table, he copies the same indexes from the one table into the new one. This maintains the same level of clustering across all tables, and therefore the same level of collisions for all operations.

### v.
When resizing to a larger hash table, all elements in the previous table should be rehashed with a different hash function, with an output range corresponding to the new hash table. This way, the Simple Uniform Hash Assumption (SUHA) can be preserved.

Some insertions would require a new array to be built, each element rehashed and inserted into the new hash table, running in `O(N)` time, however for most this would run in constant time `O(1)`

Analysing a general case of N insertions, with initial hash table size of 1,

`T(N) = Nc + (2c + 4c + 8c ... + (N-1)c)`

*(proof is trivial)*

For N insertions, it is `O(N)`, thus for a single push it is amortised `O(1)`.

___

## Question 2a

### i.

### ii.

`0 <= log(N) + 2 <= c * log(N) / 2`

Solving for `c`,

`log(N) + 2 <= c * log(N) / 2`

`c >= 2 + 4 / log(N)`

As `N -> INF`, `c >= 2`

Therefore there exists a `c` and `N0` where the first equation is valid for `N >= N0`.

## Question 2b

### i.

1. First sort the array, this takes `O(N log N)` time.
2. Now loop through each element if the array, and stop if two consecutive elements have the same value. This takes `O(N)` time.

Thus overall complexity is `O(N log N)`.

### ii.

## Question 2c

### i.

`Increment` runs in `O(k)` time, where `k` is the number of bits in the binary number.

Hence, a series of `N` increments would call this function `N` times, resulting in `N * O(k)` or `O(kN)`.

### ii.

___

## Question 3a

|Node|
|-|
|A   |0  |0  |0  |0  |0  |0  |
|B   |INF|7  |7  |7  |6  |6  |
|C   |INF|2  |2  |2  |2  |2  |
|D   |INF|9  |3  |3  |3  |3  |
|E   |INF|INF|12 |4  |4  |4  |

Order of edges relaxed: `A->`, `C->`, `D->`, `E->`, `B->`

## Question 3b

DFS returns the order in which a branch is backtracked, reversing it returns the order in which a branch is traversed.

Whereas a BFS returns the order of nodes in each layer start from the root tree, reversing returns the order from the bottom.

## Question 3c

### i.

To sort the edges, any `O(E log E)` sorting algorithm can be used - Quicksort or Mergesort.

To verify if tree T is still connected, any flood-fill algorithm can be used, DFS or BFS. This runs in `O(VE)` time.

Since the DFS/BFS step is performed `E` times, the overall complexity becomes `O(VE^2 + E log E)`, which simplifies to `O(VE^2)`

### ii.

If `e` is an edge in graph `G`, and removing `e` from `G` does not result in a disconnected graph, then `e` was part of a cycle in `G`. By iterating through all edges and removing ones that leave `G` connected effectively removes all cycles in `G`. Thus the resulting graph is acyclic.

Since we are only removing edges, and never adding, and that the resultant graph `T` is connected, then it is clear that all of `T` spans all of `G`.

Since edges considered are obtained in descending order, only the highest weighted edges are considered first. Meaning for any cycle, the highest weighted edge will be first considered for removal. Given that the highest weight edge in any cycle is not in any MST, the `Reverse-Delete` algorithm will return a tree that is always minimal.

## Question 4a

```java
public int maximumGain(int[] hours, int[] earned, int time, int[] memo) {
  // base case
  if (time == 0) return 0;
  if (memo[time]) return memo[time];

  int maxGain = INT_MIN;
  for (int i = 0; i < hours.length; i++){
    if (hours[i] <= time) {
      int gain = earned[i] + maximumGain(hours, earned, time - hours[i])
      maxGain = max(maxGain, max);
    }
  }
  memo[time] = maxGain;
  return memo[time];
}

// Then call somewhere
memo[9] = {0};
maximumGain(hours, earned, 8, memo);
```

## Question 4b

### i.

```java
public int fib(int n, int[] memo) {
  if (n == 0) return 0;
  if (n == 1) return 1;
  if (memo[n]) return memo[n];
  memo[n] = fib(n-1) + fib(n-2);
  return memo[n];
}
```

### ii.
```java
public int fib(int n) {
  memo[0] = 0;
  memo[1] = 1;
  for (int i = 2; i <= n; i++) {
    memo[i] = memo[i-1] + memo[i-2];
  }
  return memo[n];
}
```

## Question 4c

No, because merge sort recursively breaks down the array into two halves that do not overlap. At no point does merge sort operate over the same element of the original array twice at any given level of recursion.

Therefore there is no opportunity to reapply previously calculated operations, thus not satisfying the *overlapping sub-problems* requirement of dynamic programming.

## Question 4d
```java
public int Pow(int x, int N) {
  if (N == 1) {
    return x;
  }
  else if (N % 2 == 1) {
    return Pow(x, (N-1)/2) * Pow(x, (N-1)/2) * x;
  }
  else {
    return Pow(x, N/2) * Pow(x, N/2);
  }
}
```
