# 2017-2018 Algorithms

## Question 1a

### i.

The formal definition of O:

`O(g(N)) = f(N)` where there exists a positive `c` and `N0` such that `0 <= f(N) <= c*g(N)` for all `N >= N0`

Consider,

`f(N) + g(N) = aN^2 + bN + c`

`0 <= aN^2 + bN + d <= c * N^2`

Solving for `c`,

`c >= a + b/N + d/N^2`

as `N -> INF`, `c >= a`

Therefore, there exists a value `c` and `N0` that satisfy the set condition `f(N) + g(N) = O(N^2)`

### ii.

- Complexity of insertion sort is `O(N^2)`.

- Complexity of the loop in the procedure body is `O(N)`

Therefore, as proven in 1a(i), the complexity of `O(N) + O(N^2) = O(N^2)`.

## Question 1b

### i.
Simple Uniform Hashing (SUHA) assumes that the chance of each key landing into any of the `m` buckets in a hash table is `1/m`

In the worst case, all `N` elements are in the same bucket, and the element to search for is at the end of the chain. Thus the worst  search time is `O(N)`.

In the general case, SUHA states that the chain length of each bucket is `N/m`, thus the expected search time becomes `sumOf(i: 1 -> m) N/m * 1/m` which gives `N/m`.

### ii.

The hash function could be `hash(ID) = ID % 10000`, meaning that the IDs of every student from the same year would hash into the same bucket on the hash table.

If there are many students per year, it would result in a long chain that would explain the poor search performance.

### iii.

The problem can be rephrased as: What are the time complexities for a push and get operation for 1. linked lists and 2. arrays.

- Linked lists
  - **GET**: There isn't a shortcut to abuse the ordered aspect of the list, and the program would still have to traverse the entire chain to search for an element, thus the complexity remains `O(N)`
  - **PUT**: Again, there is no way to abuse the ordered aspect of the list, and finding the insertion index would require traversing the list, and remains an `O(N)` operation. (Insertion is `O(1)`)

- Arrays
  - **GET**: A binary search can be used, which is an `O(log N)` operation.
  - **PUT**: A binary search can be used to locate the appropriate insertion index, which is `O(log N)`, but relocating every other element is an `O(N)` operation, so the overall complexity is `O(N)`.

Alternatively an array *can* be used as a heap, which would result in `O(log N)` complexity for both GET and PUT operations even after considering dynamically resizing.

___

## Question 2a

### i.

Without DP (runs in `O(N^S)` time)

```java
public int MinCoins(Array<int> coins, int amount) {
  // base case
  if (amount == 0) return 1;

  // recursive step
  int num = INFINITY;
  for (int coin: coins) {
    if (coin <= amount) {
      int result = MinCoins(coins, amount - coin) + 1;
      num = min(num, result);
    }
  }
  return num;
}
```

With DP (runs in `O(N)` time)

```java
public int MinCoins(int[] coins, int amount, int[] memo) {
  // base cases
  if (amount == 0) return 1;
  if (memo[amount]) return memo[amount];

  // recursive step
  int num = INFINITY;
  for (int coin: coins) {
    if (coin <= amount) {
      int result = MinCoins(coins, amount - coin) + 1;
      num = min(num, result);
    }
  }
  memo[amount] = num;
  return memo[amount];
}
```

### ii.

Consider `V = [1, 3, 97, 98]` and `S = 100`

A greedy algorithm would produce `3` (98, 1, 1) when the optimal solution is `2` (97, 3)

## Question 2b

### i.

By create an array double the size of the previous, when the capacity limit is exceeded.

Consider N number of pushes, and the Nth push causes the array to be copied:

`T(N) = Nc + (10c + 20c + ... (N-1)/2 * c + (N-1) * c)`

Which gives us,

`T(N) = Nc + (2Nc - 2c - 10c) = 3Nc - 8c`

Since the complexity for N pushes is `O(N)`, the compexity for *one* push becomes `O(N) / N = O(1)`

### ii.

The worst case time to push N more objects would be if the last (Nth) push required a new stack.

Therefore,

`g(N) = (N-1)c + (M+N)c` or `(2N + M - 1)c`

### iii.

The worst case time to push N objects would be if the last push required a copying of all objects


`g(N) = Nc + (10 + 20 + (N-11) + (N-1))c`

`g(N) = Nc + (N + 9)c * (N - 1)/10`

___

## Question 3a

### i.

To convert each list into its number format, one could loop through each digit and multiply the old result by 10, and then adding the current number. This would be an O(N) operation for a list of size (N).

Therefore the addition process would be as follows:
1. Convert list A into a number - `O(N)`
2. Convert list B into a number - `O(M)`
3. Add the two numbers - `C`
4. Convert the result into a list - `O(M + N + 1)`

The resulting complexity is `O(M + N + 1)` or succintly `O(M + N)`

### ii.

To divide a number by `10^M`, one simply truncates the list by `M` elements from the back.

Assuming the list is immutable, and has to be copied to a new one, this operation runs in `O(N+M)` complexity, where `N` is the length of the original list.

However if a mutable linked list is used, the operation can be run in `O(M)` time by traversing from the back of the array.


## Question 3b

### i.

`T(N) = 4T(N/2) + f`

For each calculation of `xy`, the algorithm produces 4 more recursive sub-problems:

1. `xAyA`
2. `xAyB`
3. `xByA`
4. `xByB`

By assuming N to be powers of two, we can be assured that each sub-problem is perfectly half of the original problem.

`f` represents the time complexity for the remaining of the arithmetic operations.
1. Multiplication operations run in `O(N)` time
2. Addition operations run in `O(N)` time

Overall,

`T(N) = 4T(N/2) + O(N)`

### ii.

This reduces the number of sub-problems produced to two,

`T(N) = 2T(N/2) + f`

To multiply two N digit numbers, A and B:

1. For each value of B, multiply each value of A
2. Sum all of the values

Step 1 runs in `O(N^2)` time, and step 2 runs in `O(N)` time.

Therefore the complexity of this operation is `O(N^2)`

Overall,

`T(N) = 2T(N/2) + O(N^2) + O(N)`

or

`T(N) = 2T(N/2) + O(N^2)`

___

## Question 4a

### i.

```java
public boolean isBipartite(Vertex[] vertices) {
  int[vertices.size()+1] colors = {0};
  for (Vertex vertex: vertices) {
    if (colors[vertex] == 0 && !canColor(vertex, 1)) {
      return false;
    }
  }
  return true;
}

public boolean canColor(Vertex vertex, int color) {
  if (colors[vertex]) {
    return colors[vertex] == color;
  }
  for (Vertex neighbour: Adjacent(G, vertex)) {
    if (!canColor(neighbour, -color)){
      return false;
    }
  }
  return true;
}
```

### ii.

The DFS search algorithm employed is a flood-fill algorithm, so no two nodes are visited twice. Therefore the worst-case complexity is `O(N)`

## Question 4b

### i.

- Edge 1-2
- Edge 2-6
- Edge 6-5
- Edge 2-3
- Edge 3-4
- Edge 4-9
- Edge 9-8
- Edge 5-7

### ii.

Not part of the course, but good to note that for Prim's, it would run in `O(E)` time and for Kruskal's, `O(E log V) `
