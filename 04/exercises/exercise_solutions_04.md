# Solutions to chapter 4 exercises
## Exercise 4.01
Show the output produced by each of the following program fragments. Assume that `i`, `j`, and `k` are `int` variables.
```
(a) i = 5; j = 3;
    printf("%d %d", i / j, i % j);
(b) i = 2; j = 3;
    printf("%d", (i + 10) % j);
(c) i = 7; j = 8; k = 9;
    printf("%d", (i + 10) % k / j);
(d) i = 1; j = 2; k = 3;
    printf("%d", (i + 5) % (j + 2) / k);
```

### Solution
(a) `1 2`  
(b) `0`  
(c) `1`  
(d) `0`


## Exercise 4.02
If `i` and `j` are positive integers, does `(-i)/j` always have the same value as `-(i/j)`? Justify your answer.

### Solution
No. In C89, if either operand of the `/` operator is negative, the result can be rounded either up or down. Thus, in C89 the result of `-9 / 7` could be `-1` or `-2`. In C99 however, the result of a division is always truncated toward zero, so `-9 / 7` would always be -1.


## Exercise 4.03
What is the value of each of the following expressions in C89? (Give all possible values if an expression may have more than one value.)
```
(a) 8 / 5
(b) -8 / 5
(c) 8 / -5
(d) -8 / -5
```

## Solution
```
(a) 1
(b) -1 or -2
(c) -1 or -2
(d) 1 or 2
```


## Exercise 4.04
Repeat exercise 3 for C99.

## Solution
```
(a) 1
(b) -1
(c) -1
(d) 1
```


## Exercise 4.05
What is the value of each of the following expressions in C89? (Give all possible values if an expression may have more than one value.)
```
(a) 8 % 5
(b) -8 % 5
(c) 8 % -5
(d) -8 % -5
```

## Solution
If `i` or `j` is negative, the sign of `i % j` in C89 depends on the implementation.
```
(a) 3
(b) -3 or 2
(c) -3 or 3
(d) 3
```


## Exercise 4.06
Repeat Exercise 5 for C99.

## Solution
In C99, the value of `i % j` has the same sign as `i`.
```
(a) 3
(b) -3
(c) 3
(d) -3
```


## Exercise 4.07
The algorithm computing the UPC check digit ends with the following steps:

Subtract 1 from the total.
Compute the remainder when the adjusted total is divided by 10.
Subtract the remainder from 9.

It's tempting to try to simplify the algorithm by using these steps instead:
Compute the remainder when the total is divided by 10.
Subtract the remainder from 10.

Why doesn't this technique work?

## Solution
The first algorithm is

`check = 9 - ((total - 1) % 10)`

whereas the 'simplified' algorithm is

`check = 10 - (total % 10)`

Recall that the check digit is a single digit, meaning numbers in the range [0, 9]. The second algorithm can produce the number `10`, which is an invalid check digit. When `total` is `0` or a multiple of `10`, the term `total % 10 = 0` and therefore `check = 10 - 0 = 10`.


## Exercise 4.08
Would the upc.c program still work if the expression `9 - ((total - 1) % 10)` were
replaced by `(10 - (total % 10)) % 10`?


## Solution
Yes. Both solutions would produce (almost) equal answers.

The second solution actually works better in the edge case `total = 0`. The first algorithm would yield an invalid check digit of `10`, because in C99 the result of `i % j` has the sign of `i`:
```
   9 - ((total - 1) % 10)
 = 9 - ((0 - 1) % 10)
 = 9 - (-1 % 10)
 = 9 - -1
 = 10
```
This does not happen with the second algorithm:
```
= (10 - (total % 10)) % 10
= (10 - (0 % 10)) % 10
= (10 - 0) % 10
= 10 % 10
= 0
```


## Exercise 4.09
Show the output produced by each of the following program fragments. Assume that `i`, `j` and `k` are `int` variables.
```
(a) i = 7; j = 8;
    i *= j + 1;
    printf("%d %d", i, j);
(b) i = j = k = 1;
    i += j += k;
    printf("%d %d %d", i, j, k);
(c) i = 1; j = 2; k = 3;
    i -= j -= k;
    printf("%d %d %d", i, j, k);
(d) i = 2; j = 1; k = 0;
    i *= j *= k;
    printf("%d %d %d", i, j, k);
```

## Solution
```
(a) 63 8
    i = (i * (j + 1))
    i = (7 * (8 + 1))
    i = (7 * 9)
    i = 63

(b) 3 2 1
    i = (i + (j = (j + k)))
    i = (1 + (j = (1 + 1)))
    i = (1 + (j = 2))
    i = (1 + 2)
    i = 3

(c) 2 -1 3
    i = (i - (j = (j - k)))
    i = (1 - (j = (2 - 3)))
    i = (1 - (j = -1))
    i = (1 - -1)
    i = 2

(d) 0 0 0
    i = (i * (j = (j * k)))
    i = (2 * (j = (1 * 0)))
    i = (2 * (j = 0))
    i = (2 * 0)
    i = 0
```


## Exercise 4.10
Show the output produced by each of the following program fragments. Assume that `i` and `j` are `int` variables.
```
(a) i = 6;
    j = i += i;
    printf("%d %d", i, j);
(b) i = 5;
    j = (i -= 2) + 1;
    printf("%d %d", i, j);
(c) i = 7;
    j = 6 + (i = 2.5);
    printf("%d %d", i, j);
(d) i = 2; j = 8;
    j = (i = 6) + (j = 3);
    printf("%d %d", i, j);
```


## Solution
```
(a) 12 12
    j = (i = (i + i))
    j = (i = (6 + 6))
    j = (i = 12)
    j = 12

(b) 3 4
    j = ((i = (i - 2)) + 1)
    j = ((i = (5 - 2)) + 1)
    j = ((i = 3) + 1)
    j = (3 + 1)
    j = 4

(c) 2 8
    j = (6 + (i = 2.5))
    j = (6 + (i = 2))
    j = (6 + 2)
    j = 8

(d) 6 9
    j = ((i = 6) + (j = 3))
    j = (6 + 3)
    j = 9
```
At (d), the order in which the sub-expressions `i = 6` and `j = 3` are evaluated is undefined. This does not matter for the final result, however.


## Exercise 4.11
Show the output produced by each of the following program fragments. Assume that `i`, `j` and `k` are `int` variables.
```
(a) i = 1;
    printf("%d ", i++ - 1);
    printf("%d", i);
(b) i = 10; j = 5;
    printf("%d ", i++ - ++j);
    printf("%d %d", i, j);
(c) i = 7; j = 8;
    printf("%d ", i++ - --j);
    printf("%d %d", i, j);
(d) i = 3; j = 4; k = 5;
    printf("%d ", i++ - j++ + --k);
    printf("%d %d %d", i, j, k);
```

## Solution
```
(a) 0 2
(b) 4 11 6
(c) 0 8 7
(d) 3 4 5 4
```


## Exercise 4.12
Show the output produced by each of the following program fragments. Assume that `i`, and `j` are `int` variables.
```
(a) i = 5;
    j = ++i * 3 - 2;
    printf("%d %d", i, j);
(b) i = 5;
    j = 3 - 2 * i++;
    printf("%d %d", i, j);
(c) i = 7;
    j = 3 * i-- + 2;
    printf("%d %d", i, j);
(d) i = 7;
    j = 3 + --i * 2;
    printf("%d %d", i, j);
```

## Solution
```
(a) 6 16
(b) 6 -7
(c) 6 23
(d) 6 15
```

## Exercise 4.13
Only one of the expressions `++i` and `i++` is exactly the same as `(i += 1)`; which is it?
Justify your answer.

## Solution
Only the prefix increment operator `++i` is exactly the same as `(i += 1)` because the assignment immediately evaluates to `i + 1`. The postfix increment operator `i++` also applies the assignment, but does not evaluate to `i + 1` but to `i`.


## Exercise 4.14
Supply parentheses to show how a C compiler would interpret each of the following expressions.
```
(a) a * b - c * d + e
(b) a / b % c / d
(c) - a - b + c - + d
(d) a * - b / c - d
```

## Solution
```
(a) ((a * b) - (c * d)) + e
(b) ((a / b) % c) / d
(c) (((- a) - b) + c) - (+ d)
(d) ((a * (- b)) / c) - d
```


## Exercise 4.15
Give the values of `i` and `j` after each of the following expression statements has been executed. (Assume that `i` has the value `1` initially and `j` has the value `2`.)
```
(a) i += j;
(b) i--;
(c) i * j / i;
(d) j % ++j;
```

## Solution
```
(a) 3 2
(b) 0 2
(c) 1 2
(d) 1 3
```
