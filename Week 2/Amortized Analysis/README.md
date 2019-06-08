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
The charges to each operation must be set large enough that the balance in the bank 
account always remains positive, but small enough that no one operation is charged
significantly more than its actual cost.
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

```
Above we saw the aggregate method and the banker's method for dealing with extensible arrays.
Now let us look at the physicist's method.
```

```
Suppose we can define a potential function Φ (read "Phi") on states of a data structure with the following properties:
```
- Φ(h0) = 0, where h0 is the initial state of the data structure.
- Φ(ht) ≥ 0 for all states ht of the data structure occurring during the course of the computation.

```
Intuitively, the potential function will keep track of the precharged time at any point in the computation.
It measures how much saved-up time is available to pay for expensive operations.
It is analogous to the bank balance in the banker's method. But interestingly, it depends only
on the current state of the data structure, irrespective of the history of the computation that got it into that state.
```

```
We then define the amortized time of an operation as
```
__c + Φ(h') − Φ(h)__

```
where c is the actual cost of the operation and h and h' are the states of the data
structure before and after the operation, respectively.
```
```
Thus the amortized time is the actual time plus the change in potential. Ideally, Φ should be defined
so that the amortized time of each operation is small.
Thus the change in potential should be positive for low-cost operations and negative for high-cost operations.
```

```
Now consider a sequence of n operations taking actual times c0, c1, c2, ..., cn−1 and
producing data structures h1, h2, ..., hn starting from h0. The total amortized time is the sum of the individual amortized times:

(c0 + Φ(h1) − Φ(h0)) + (c1 + Φ(h2) − Φ(h1)) + ... + (cn−1 + Φ(hn) − Φ(hn−1))
= c0 + c1 + ... + cn−1 + Φ(hn) − Φ(h0)
= c0 + c1 + ... + cn−1 + Φ(hn).
```

```
Therefore the amortized time for a sequence of operations overestimates of the actual time by Φ(hn),
which by assumption is always positive. Thus the total amortized time is always an upper bound on the actual time.

For dynamically resizable arrays with resizing by doubling, we can use the potential function

Φ(h) = 2n − m,
```

```
where n is the current number of elements and m is the current length of the array.
If we start with an array of length 0 and allocate an array of length 1 when the first element is added,
and thereafter double the array size whenever we need more space, we have Φ(h0) = 0 and Φ(ht) ≥ 0 for all t.
```
```
The latter inequality holds because the number of elements is always at least half the size of the array.

Now we would like to show that adding an element takes amortized constant time. There are two cases.
```
```
If n < m, then the actual cost is 1, n increases by 1, and m does not change.
Then the potential increases by 2, so the amortized time is 1 + 2 = 3.
If n = m, then the array is doubled, so the actual time is n + 1.
But the potential drops from n to 2, so amortized time is n + 1 + (2 − n) = 3.
In both cases, the amortized time is O(1).
```
```
The key to amortized analysis with the physicist's method is to define the right potential function.
The potential function needs to save up enough time to be used later when it is needed.
But it cannot save so much time that it causes the amortized time of the current operation to be too high.
```
__Helpful Lecture__
https://www.cs.cornell.edu/courses/cs3110/2013sp/lectures/lec21-amortized/lec21.html
