# Semaphores
- Both *locks* and *conditional variables*
- Atomic operations:
  - `down(s)`
  - `up(s)`
  - `init(s, i)`

```cpp
class Semaphore {
  int counter;
  Queue queue;
  Semaphore(i): counter(i) {}
};

void init(s, i) {
  s = new Semaphore(i);
}

void down(s) {
  if (s.counter > 0)
    s.counter--;
  else {
    "add P to queue";
    "suspend P";
  }
}

void up(s) {
  if (s.queue.size() > 0)
    resume(s.queue.pop());
  else
    s.counter++;
}
```

- **Mutual Exclusion**: Binary semaphore
- Initial value indicates how many processes can access shared data

## Producer-Consumer
- Always require 3 sempahores:
  1. Space sempahore (N)
  2. Item semaphore (0)
  3. Mutex sempahore (1)


- Always have mutex semaphore in the inner loop
```
Producer:             Consumer:
    down(space)          down(item)
    down(mutex)          down(mutex)
     ...                   ...
    up(mutex)            up(mutex)
    up(item)             up(space)
```

## Reader-Writer
- Always require 2 semaphores
  1. Mutex semaphore (writers)
  2. Semaphore to protect `reader_count`

```
Writer:                Reader:
  down(writer_sem)       down(mutex)
  ...                    reader_count += 1
  up(writer_sem)         if (reader_count == 1)
                            down(writer_sem)
                         up(mutex)
                         ...
                         down(mutex)
                         reader_count -= 1
                         if (reader_count == 0)
                            up(writer_sem)
                         up(mutex)
```
- Note: Too many readers starve the writers

# Monitors

- High-level conditions: *Some space has become available, etc*
- **Atomic** operations:
  1. `wait(c)`: releases monitor lock, waits for condition c
  2. `signal(c)`: wakes up one process waiting for c

- **Hoare monitors**: Signals accumulated, process that signals is swapped out
- **Lampson monitors**: Susceptible to spurious wakeups, hence need to recheck for predicate on wakeup
