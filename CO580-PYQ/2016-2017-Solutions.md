# 2016-2017 Algorithms

## Question 1a

### i.

The formal definition of `O(f(N))`:

`O(f(N)) = g(N)` where there exists a positive `c` and `N0` such that `0 <= g(N) <= c * f(N)` for `N >= N0`

Following the lemma,

`0 <= 100 * N ^ 0.5 + 4 <= c * 2N`

Solving for `c`,

`c >= 50 * N ^ -0.5 + 2`

As `N-> INF`, `c >= 2`

Therefore, there exists a value `c` and `N0` that satisfy the set condition `Tx(N) = O(2N)`

### ii.

Algorithm Y would perform better than Algorithm X.

Although algorithm X has a better tight-bound complexity of `O(N^0.5)` compared to Algorithm Y's `O(N)`, Big-O notation does not account for the size of constants involved.

Using a 144 character case-example, `Tx(144) = 1204` while `Ty(144) = 288`

## Question 1b

Counting sort not part of 2019 syllabus.

## Question 1c

### i.

First find the minimum combined ticket price for every outgoing train. This can be done by comparing every value of `Out` against every valid value of `Rtn`.

- What is the lowest total fare if Mary leaves at `Out[0]`
- What is the lowest total fare if Mary leaves at `Out[1]`
- ...
- What is the lowest total fare if Mary leaves at `Out[N-6]`

Pick again the minimum from this list to obtain the overall lowest fare.

### ii.

Yes.

Working from the back, consider `Out[N-6]`, the minimum return fare corresponding to this outgoing fare is `Rtn[N-1]`.

Now considering `Out[N-7]`, the minimum return fare corresponding to this outgoing fare becomes `min(Rtn[N-2], Rtn[N-1])`, let this value be `m`.

For all outgoing fares `Out[N-i]`, the minimum this becomes `min(Rtn[N-i+5], m)`

Thus by memoising the last minimum fare calculated, the algorithm would not have to loop through the `Rtn` array at each step to determine the minimum return fare, but merely to compare the previous' to the current.

### iii.

```java
public int minFare(int[] Out, int[] Rtn) {
  int minTotalFare = INT_MAX;
  int minReturnFare = INT_MAX;
  for (int i = Out.size() - 6; i >= 0; i--) {
    int outFare = Out[i];
    minReturnFare = min(minReturnFare, Rtn[i + 5]);
    minTotalFare = min(minTotalFare, outFare + minReturnFare);
  }
  return minTotalFare;
}
```

___

## Question 2a

### i.

- **Best case**: O(1)
  - In a linear tree, where all the elements are on one side of the root node, and the key is inserted into the other side
- **Worst case**: O(N)
  - Again, in a linear tree, where the item is inserted to the end of the chain.

### ii.
A RBT has a height of `C log N` (since the constraints of a RBT is not sufficient to have it perfectly balanced), therefore traversing to a leaf node for insertion from root would be an `O(log N)` operation.

### iii.
It would take longer to insert a new key into the RBT compared to the BST.

In addition to inserting the element to the leaf of a tree, a RBT would also need to rearrange and recolour elements to maintain a balanced tree.

However, to maintain `O(log N)` operations for key insertion and retrieval, it is imperative that the rebalancing process to be possible also in `O(log N)` time.

Thus, the extra time taken for a RBT insertion is amortised `O(1)`.

## Question 2b

### i.

Collision resolution is a set of procedures that resolve the scenario where an element that is to be inserted into a hash table hashes identically to another element in the hash table.

To prevent collision is to implement a perfect hash function, where every element is uniquely hashed. This is often not possible, thus collision resolution is imperative to making hash tables work.

### ii.

- **Chaining**: The hash function of returns the *bucket* at which the element is stored

- **Linear probing**: The hash function returns the *starting position* at which the element should be sequentially searched for

### iii.

- **Chaining**
  - Each entry of the hash table is the head of a linked list containing all objects whose keys hash to that entry
  - When a new object is inserted, its key is first hashed. Then the object appended to linked list at corresponding hash table entry
  - Both average and best case is `O(1)`, as hashing and adding to a linked list both run in constant time
- **Probing**
  - When a new object is inserted, its key is first hashed. If there already is an object at the corresponding hash table entry, the table is searched sequentially until the next empty index is found.
  - Worst case is when all `N` elements have to be looped through before an empty space is found - `O(N)`
  - Assuming uniform hashing, average case is amortised `O(1)`

### iv.

If objects can sequentially be retrieved from a hash table, a heap based on object key values could then be simultaneously built in `O(N)` time.

Once a heap is built, objects could then be removed in order to return a sorted list, which is an `O(N log N)` process.

Thus this overall operation, the sum of these processes, will take `O(N log N)` time.

___

## Question 3a

### i.

Using list `C` as a data structure representing the graph and `ex, ey` as the starting node, Djikstra's algorithm can be applied to obtain a minimum distance graph from every point of the maze to the exit.

From this minimum distance graph, the shortest path to the exit can be obtained from any point in the maze by continuously traversing to a node with a *shorter* minimum distance to the exit.

```
6 - 5
|   |
5 - 4 - 3 - 4
    |   |
    3 - 2 - 1
        |   |
        1 - 0
```

Starting from the top-left most node, any paths travelling from 6 -> 5 -> 4 -> 3 -> 2 -> 1 -> 0 would be the shortest path from the exit.

Traversing this path is proportional to the distance from the starting node to the exit, hence running in `O(s)` time.

### ii.

For Djikstra's algorithm, we are concerned with the following operations:

1. Insertion - Done for every vertex at the start
2. Removing - Every vertex is removed from the priority queue exactly once
3. Updating - For each edge, its priority in the queue needs to be updated, and is done for every edge exactly once

Step 1 runs in `O(N)` time, the time taken to build a heap from scratch.

Step 2 runs in `O(V log V)` time, as each removing operation runs in `O(log V)`, and there are `V` of these operations.

Step 3 runs in `O(E log V)` time, similar to step 2 but done for each edge instead.

Thus the overall complexity is clearly `O((V+E) log V)`.

Assuming a fully connected graph, since it is possible to reach the exit from every point in the maze, `V <= E + 1`, and thus `V = O(E)`, then we can simplify the time complexity to `O(E log V)`

## Question 3b

### i.

Djikstra's is not appropriate for this graph as it contains negative weight edges

Starting with node a,

1. Relaxing adj(A): `D = 10, E = 12`
2. Relaxing adj(D):
`D = 10, E = 12, C = 13`
3. Relaxing adj(E):
`D = 9, E = 12, C = 13`

At this point the minimum distance graph becomes incorrect, as `a->c` should be 12 (`a->e->d->c`)

### ii.

First pass

|Node|
|-|
|a|0  |0  |0  |0  |0  |0  |
|b|INF|INF|INF|INF|INF|INF|
|c|INF|INF|INF|INF|13 |13 |
|d|INF|10 |10 |10 |10 |9  |
|e|INF|12 |12 |12 |12 |12 |

Second pass

|Node|
|-|
|a|0  |0  |0  |0  |0  |0  |
|b|INF|INF|INF|10 |10 |10 |
|c|13 |13 |13 |13 |12 |12 |
|d|9  |9  |9  |9  |9  |9  |
|e|12 |12 |12 |12 |12 |12 |

After this point no more edges will be relaxed, and the algorithm returns true to indicate that no negative weight cycles exist.

### iii.

If edge `(d,c)` is changed to 1, then the algorithm would not work as there exists a negative weight cycle from `b -> e -> d -> c -> b`.

___

## Question 4a

### i.

```
1  procedure heapsort(arr a)
2    for i from (N-1)/2 to 0
3      heapify(a, N, i)
4    for i from N-1 to 0
5      swap(a[0], a[i])
6      heapify(a, i, 0)
```

`heapify(a, b, c)` rearranges array `a` of size `b` into a heap by ensuring the order of node index `c`. Since nodes can only be heapified if and only if its children nodes are valid heaps, then heapify has to be applied from the bottom-up.

Lines 2-3 are to make the array heap-ordered, and lines 4-6 to move values to their correctly sorted positions.

A heap-ordered array is a one-dimension array whose subarrays contain children of a parent node. For a particular index `n`, its children nodes are `2n` and `2n + 1`.

### ii

`heapify` runs in `O(log N)` time, and it is repeated `N` times giving a running complexity of `O(N log N)`

Moving each element into its proper location, following a similar procedure from before, runs in `O(N log N)`.

Thus overall complexity is `O(N log N)`

## Question 4b

### i.

```
procedure Sort(arr a, int l, int r)
  if (l + 2 <= r)
    return
  p = HoarePartition(a)
  Sort(a, l, p)
  Sort(a, p+1, r)
  return
```

### ii.

For an input where the array contains duplicates, Hoare partitioning performs swaps for every element, but the array is also split down the middle every single time. Therefore this gives a running time of `O(N log N)`.

For Lomuto partitioning this performance degrades to `O(N^2)` as the pivot is only moved one index each sorting loop.

### iii.

The worst case input for Hoare partitioning is when the given array is already sorted, in which case the entire array is iterated though (but no swaps are made), and the pivot increments by one, resulting in `O(N^2)` run time.
