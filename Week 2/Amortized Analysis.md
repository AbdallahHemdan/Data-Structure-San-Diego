# ⚖️Amortized Analysis
```
- Amortized Analysis is used for algorithms where an occasional operation is very slow,
but most of the other operations are faster.
```
```
- In Amortized Analysis, we analyze a sequence of operations and guarantee a worst case average time
which Is lower than the worst case time of a particular expensive operation.
```
```
- The example data structures whose operations are analyzed using Amortized Analysis are Hash Tables,
Disjoint Sets and Splay Trees and Vectors(In C++), ArrayList(Jave)
```
```
In hash table we use Dynamic Table (or Arrays).
The idea is to increase size of table (twice the old size) whenever it becomes full. 
```

```
So when hash table become full
1- We create a new table (twice the old size).
2- Copy the content of the old to the new one.
3- Free the old one. 	
```

![](https://www.geeksforgeeks.org/wp-content/uploads/AmortizedAnalysis.png)
```
1) The above Amortized Analysis done for Dynamic Array example is called Aggregate Method.
```

## Methods
--------
### Aggregate Method
```
It has been discussed in the above part
```
### The accounting (or banker's)
```
banker's method, where we impose an extra charge on inexpensive operations and
use it to pay for expensive operations later on.
```

```
The aggregate method directly seeks a bound on the overall running time of a sequence of operations.
In contrast, the accounting method seeks to find a payment of a number of extra time units charged to
each individual operation such that the sum of the payments is an upper bound on the total actual cost.
```
```
Intuitively, one can think of maintaining a bank account.
Low-cost operations are charged a little bit more than their true cost,
and the surplus is deposited into the bank account for later use. High-cost operations can then be charged
less than their true cost, and the deficit is paid for by the savings in the bank account.
```
```
In that way we spread the cost of high-cost operations over the entire sequence.
The charges to each operation must be set large enough that the balance in the bank account always remains positive,
but small enough that no one operation is charged significantly more than its actual cost.
```
 
``` 
We emphasize that the extra time charged to an operation does not mean that the operation
really takes that much time. It is just a method of accounting that makes the analysis easier.
```

```
If we let c'i be the charge for the i-th operation and ci be the true cost, then we would like
```

__Σ1≤i≤n ci ≤ Σ1≤i≤n c'i__

```
for all n, which says that the amortized time Σ1≤i≤n c'i for that sequence of n operations is a bound
on the true time Σ1≤i≤n ci.
```

```
Back to the example of the extensible array. 
Say it costs 1 unit to insert an element and 1 unit to move it when the table is doubled. 
Clearly a charge of 1 unit per insertion is not enough, because there is nothing left over to pay for the moving.
A charge of 2 units per insertion again is not enough, but a charge of 3 appears to be:
```
| i | si | ci |c'i | bi |
|---|----|----|----|----|
| 1 | 1  | 1  | 3  | 2  |
| 2 | 2  | 2  | 3  | 3  |
| 3 | 4  | 3  | 3  | 3  |
| 4 | 4  | 1  | 3  | 5  |
| 5 | 8  | 5  | 3  | 3  |
| 6 | 8  | 1  | 3  | 5  |
| 7 | 8  | 1  | 3  | 7  |
| 8 | 8  | 1  | 3  | 9  |
| 9 | 16 | 9  | 3  | 3  |
| 10| 16 | 1  | 3  | 4  |
------------------------
```
where bi is the balance after the i-th insertion.
In fact, this is enough in general. Let m refer to the m-th element inserted.
The three units charged to m are spent as follows:
```

- One unit is used to insert m immediately into the table.
- One unit is used to move m the first time the table is grown after m is inserted.
- One unit is donated to element m − 2^k, where 2^k is the largest power of 2 not exceeding m,
and is used to move that element the first time the table is grown after m is inserted. 
### Physicist's Method


