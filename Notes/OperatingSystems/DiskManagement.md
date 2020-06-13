# Disk Management

## Scheduling

### First Come First Served (FCFS)
- No ordering of requests
- Poor for heavy loads
- Fair scheduling

### Shortest Seek Time First (SSTF)
- Order according to shortest seek distance from current position
- Discriminates against innermost/outermost tracks
- Unpredictable and unfair performance

### SCAN 
- Order according to shortest seek distance *in preferred direction*
- Only change directions when reaching outer/innermost cylinders
- Most common (Elevator scheduling)
- Long delays at extremes

### C-SCAN
- Service requests in one direction only
- When head reaches innermost request, jump to outermost request
- Lower variance at extremes
- (Still) may delay requests indefinitely

### N-Step SCAN
- Same as SCAN, but services only requests waiting when sweep began
- Requests that arrive during sweep and services during return sweep
- Does not delay requests indefinitely
