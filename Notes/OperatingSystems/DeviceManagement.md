# Device Management

## Device I/O

### Programmed I/O (PIO)
1. OS constantly **polls** until the device is ready to receive a commands
2. Sends/reads data from/to the device registers
Note: Lots of busy waiting

### Interrupt Driven I/O
1. Issue a request for device, and put process to sleep
2. When device is ready, it issues an **interrupt**, switching back to the process
3. Allows for **overlap** of I/O and computation

If a device does its job very quickly, using interrupts - constantly switching the issuing process may lead to a **livelock**, where the OS spends more time handling interrupts rather than servicing the processes.

### Direct Memory Access (DMA)
Process spends a lot of time copying data from the system to the device, a rather trivial task. A DMA engine is a specific device that can orchestrate these data transfers.

Before:

```
CPU   1 1 C C 2 2 2 2 1 1
DISK          1 1 1 1
```

After:

```
CPU   1 1 2 2 2 2 2 2 1 1
DMA       1 1
DISK          1 1 1 1
```

## Spooling

- Allocation of all interaction with a given device to a single process - *spooler daemon*
- Provides sharing of non-shareable devices
- Processes that want access to the device must go through the daemon
- Frees processes from supervising the printing processes

## Types of I/O

### Synchronous
- Calls return when operation completes
- Process suspended when blocked
- Easy to understand but leads to multi-threaded code


### Asynchronous
- Process executes in parallel to I/O operation
- I/O operation notifies process upon completion
  - Callback functions, signals, etc
- Supports check/wait on condition
- Flexible, efficient, harder to use, not secure
