# Scheduling

## Multilevel Feedback Queue (MLFQ)
### Rules
1. `If Priority(A) > Priority(B)`: Run A
2. `If Priority(A) == Priority(B)`: Run A and B in Round-Robin fashion using the time slice of the queue
3. `When job enters`: Place job at the highest priority
4. `Once job uses up time allotment`: Reduce its priority
5. `After some time S`: Move all jobs to the topmost queue

## Fair Share Schedulers

### Lottery Scheduling

- Shares CPU in a proportional manner
- Uses tickets to represent percentage share of a resource
- Since its random, it avoids edge cases as seen with other algorithms like LRU

#### Mechanisms
- Ticket currency: Users with tickets can allocate tickets among their own jobs
- Ticket transfer: Can temporarily allocate tickets to another process to boost priority
