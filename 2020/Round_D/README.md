# Google Kick Start 2020 Round D

- [x] A
- [x] B
- [x] C
- [x] D

## Problem A - Record Breaker

Implementation. $O(N)$.

## Problem B - Alien Piano

Simple DP. $O(P^2K)$, where $P=4$ in this problem.

## Problem C - Beauty of Tree

Inclusion-exclusion, DFS.

We need to find, for every node, the number of descendants has a distance that can be divided by $A$, and similar for $B$. This can be done during DFS if we keep a record of the current path.

After having $ca[i]$ and $cb[i]$, we can simply calculate how many times the current node will be counted, via inclusion-exclusion:

$$t[i]=(ca[i]+cb[i])\cdot N-ca[i]\cdot cb[i]$$

Then we add up all the results, and divide it by $N^2$.

The total time complexity is $O(N)$.

## Problem D - Locked Doors

I used a rather complicated algorithm leveraging monotonic stack, sparse table and binary search.

For each door, calculate the first door to its left having higher difficulty, and the first door to its right having higher difficulty. For simplicity, a door with infinite difficulty is added at either end. This part is done by monotonic stack in $O(N)$.

Then construct a sparse table for range maximum query in $O(N\log N)$.

In each query, on the $K_i$-th day, there will be $K_i-1$ opened doors. Some are to the left of the $S_i$-th room, while some are to the right. If there are $l$ opened doors on the $K_i$-th day, there needs to be at least $f(l)$ opened doors to the right, so that the highest difficulty among the $f(l)$ doors to the right is higher than the highest difficulty among the $l$ doors to the right. An observation is that $l+f(l)$ is monotonic. So the suitable $l$ can be found via binary search.

The last step is to determine whether we should use the leftmost room, or the rightmost room. This can be done by comparing the highest difficulty of the doors to the left and those to the right. If the highest difficulty is to the left, then on the $K_i$-th day we must be in the leftmost room, otherwise rightmost.

The total time complexity is $O((N+Q)\log N)$.

[Heltion](https://codeforces.com/profile/Heltion) solved this problem via Cartesian tree.
