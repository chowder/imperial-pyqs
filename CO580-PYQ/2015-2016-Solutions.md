# 2015-2016 Algorithms

## Question 1a

### i.

There exist positive and real values for `c0`, `c1`, `N0` such that

`0 <= c0 * g(N) <= Tx(N) <= c1 * g(N)` for all `N >= N0`

### ii.

As the size of the input `N` approaches infinity, the running time complexity of the algorithm is dominated by the `N` term; that is to say it approaches some linear function `T(N) = aN + b`

### iii.

`0 <= c0 * 2N <= 7N + 5 <= c1 * 2N`

*Solving this is trivial.*

## Question 1b

Quicksort sorts an array in-place, thus its space complexity is `O(1)`

Merge sort incrementally sorts a "branch" of an array each time, each with constant height proportional to the input size. Therefore the space complexity is `O(N)`

Counting sort stores a counting table of elements, whose size depends on the maximal range of values in the array (largest - smallest). Since the final step is to loop through this counting table, the time complexity becomes `O(E)` where `E` is the range of values in the array.

## Question 1c

```java
public int maximumSumSubarray(int[] arr) {
  int maxSum = INT_MIN;
  int sum = INT_MIN;
  for (int num: arr) {
    sum = max(num, sum + num);
    maxSum = max(maxSum, sum);
  }
  return maxSum;
}
```

___

## Question 2a

### i.

Hash table. To look for an object in the set, a hash function is applied to the object, and the result is used as an index to the hash table.

Both the hash function and table access (by index) should run in constant time. Thus the overall search time is constant.

### ii.

1. To insert an object, it is first hashed with a hash function.

2. The results of the hash function is used as the index to the hash table.

3. As collision resolution, chaining can be used, where the object is appended to the head of the linked list in the hash table entry.

To ensure that search remains constant, the number of buckets, `m` must grow proportionally with the number of elements `N`.

The time performance of an insert is `O(1)`.

### iii.

If A1 is an anagram of A2, then A2 is an anagram of A1.

All anagrams, when sorted by character, are identical strings.

Thus a hash table can be used, where the keys would be the sorted list of characters of the input strings. Therefore all strings that hash to the same bucket would be anagrams of one another, and chained in a linked list.

To search for all anagrams of a string one would first sort the string, then apply the hash function before performing a lookup into the hash table. The entire linked list containing anagrams of the input string will then be retrieved.

Since one would first have to sort the input strings before performing constant-time insertion and searches, the time-complexity becomes `O(N log N)`

## Question 2b

Simplex algorithm not part of 2019 syllabus.

___

## Question 3a

```
    4
   / \
  2   6
 /   / \
-8  5  23
      /  \
     7   46
         /
       36
```

## Question 3b

### i.

```
procedure Add(Tree T, Node x)
  if T has children:
    if x == T:
      smaller = smallerSubtree(T.right, T.left)
      Add(smaller, x)
    if x > T:
      Add(T.right, x)
    else if x < T:
      Add(T.left, x)
  else:
    if x > T:
      T.right = x
    else:
      T.left = x
```

### ii.
Without duplicate keys, the worst-case runtime runs in `O(N)`, where all elements lie on one branch of the tree, and the element is to be inserted at the end of this chain. The best-case runtime is `O(1)`, when the element to be inserted is on an empty slot at the root node.

With duplicate keys, this problem forces a weak balancing to the tree, since duplicate keys are added to the smaller subtree of the two. Assuming that the size of each subtree can be determined in constant time (subtree length is stored in the information of the root node), then the insertion operation runs in `O(log N)` time.

## Question 3c

KMP algorithms not part of 2019 syllabus.

___

## Question 4a

```java
public int numberOfPaths(Graph G, int s, int t) {
  // base cases
  if (t == s) { return 1; }
  if (memo[t]) { return memo[t]; }

  // else we have to compute
  int sumPaths = 0;
  for (int v: G.adj(t)) {
      sumPaths += numberOfPaths(G, s, v);
  }

  // memoise and return
  memo[t] = sumPaths;
  return memo[t];
}
```

## Question 4b

### i.

1. a, b (1)
2. h, f (1)
3. c, f (2)
4. d, e (2)
5. a, h (3)
6. b, g (4)
7. c, d (7)
8. h, i (10)

Sum = 1 + 1 + 2 + 2 + 3 + 4 + 7 + 10 = 30

### ii.

False.

Consider cycle `B -> G -> F -> B` where edge B, F is the shortest but not part of the final MST.

## Question 4c

Bellman-Ford.

The regular version of the Bellman-Ford algorithm relaxes *every edge* |V|-1 times, as the longest path without a cycle for a graph of V vertices is |V|-1. By modifying this value to Q we can obtain the shortest path containing at most Q edges.

Djikstra's algorithm instead works by greedily choosing the closest vertex that has not been processed, and relaxing all its edges. 
