# Solutions to chapter 5 exercises
## Exercise 5.01
The following program fragments illustrate the relational and equality
operators. Show the output produced by each, assuming that `i`, `j`, and `k`
are `int` variables.
```
(a) i = 2; j = 3;
    k = i * j == 6;
    printf("%d", k);
(b) i = 5; j = 10; k = 1;
    printf("%d", k > i < j);
(c) i = 3; j = 2; k = 1;
    printf("%d", i < j == j < k);
(d) i = 3; j = 4; k = 5;
    printf("%d", i % j + i < k);
```

### Solution
(a) `1`  
(b) `1`  
(c) `1`  
(d) `0`


## Exercise 5.02
The following program fragments illustrate the relational and equality
operators. Show the output produced by each, assuming that `i`, `j`, and `k`
are `int` variables.
```
(a) i = 10; j = 5;
    printf("%d", !i < j);
(b) i = 2; j = 1;
    printf("%d", !!i + !j);
(c) i = 5; j = 0; k = -5;
    printf("%d", i && j || k);
(d) i = 1; j = 2; k = 3;
    printf("%d", i < j || k);
```

### Solution
(a) `1`  
(b) `1`  
(c) `1`  
(d) `1`  


## Exercise 5.03
The following program fragments illustrate the short-circuit behavior of
logical expressions. Show the output produced by each, assuming that `i`, `j`,
and `k` are `int` variables.
```
(a) i = 3; j = 4; k = 5;
    printf("%d ", i < j || ++j < k);
    printf("%d %d %d ", i, j, k);
(b) i = 7; j = 8; k = 9;
    printf("%d ", i - 7 && j++ < k);
    printf("%d %d %d ", i, j, k);
(c) i = 7; j = 8; k = 9;
    printf("%d ", (i = j) || (j = k));
    printf("%d %d %d ", i, j, k);
(d) i = 1; j = 1; k = 1;
    printf("%d ", ++i || ++j && ++k);
    printf("%d %d %d ", i, j, k);
```

### Solution
```
(a) 1 3 4 5
(b) 0 7 8 9
(c) 1 8 8 9
(d) 1 2 1 1
```

## Exercise 5.04
Write a single expression whose value is either `-1`, `0`, or `+1`, depending
on whether `i` is less than, equal to, or greater than `j`, respectively.

### Solution
(i > j) - (i < j)


## Exercise 5.05
Is the following `if` statement legal?
```c
if (n >= 1 <= 10)
    printf("n is between 1 and 10\n");
```
If so, what does it do when `n` is equal to `0`?

### Solution
The statement is legal, but does not behave as intended. Because the relational
operators are left-associative, the order of evaluation is ((n >= 1) <= 10).
The left term will have truth value 0 or 1, which will always be smaller than
10. Therefore, the `printf` statement is always executed, even when n is 0.
 

## Exercise 5.06
Is the following `if` statement legal?
```c
if (n == 1-10)
    printf("n is between 1 and 10\n");
```
If so, what does it do when `n` is equal to `5`?

### Solution
The statement is legal, but like the previous statement does not behave as
expected. `1-10` was likely intended as a range of values, but it instead
evaluates to `-9`. Thus, the `printf` statement executes only when `n` equals
`-9`. When `n` is `5`, nothing is printed.


## Exercise 5.07
What does the following statement print if `i` has the value `17`? What does it
print if `i` has the value `-17`?
```c
printf("%d\n", i >= 0 ? i : -i);
```

### Solution
The statement always evaluates to a positive value. In both cases, it will
print `17`.


## Exercise 5.08
The following if statement is unnecessarily complicated. Simplify it as much as
possible. (_Hint_: The entire statement can be replaced by a single assignment.)
```c
if (age >= 13 )
    if (age <= 19)
        teenager = true;
    else
        teenager = false;
else if (age < 13)
    teenager = false;
```

### Solution
```c
teenager = (age >= 13 && age <= 19);
```

## Exercise 5.09
Are the following `if` statements equivalent? If not, why not?
```
if (score >= 90)        if (score < 60)
    printf("A");            printf ("F");
else if (score >= 80)   else if (score < 70)
    printf("B");            printf("D");
else if (score >= 70)   else if (score < 80)
    printf("C");            printf("C");
else if (score >= 60)   else if (score < 90)
    printf("D");            printf("B");
else                    else
    printf("F");            printf("A");
```

### Solution
The `if` statements are equivalent.


## Exercise 5.10
What output does the following program fragment produce? (Assume that `i` is an
integer variable.)
```c
i = 1;
switch (i % 3) {
    case 0: printf("zero");
    case 1: printf("one");
    case 2: printf("two");
}
```

### Solution
Because `i % 3` is `1`, the `switch` will hit case `1`. However, because none
of the cases have `break` statements, after printing "one" it will fall through
to case 2 to print also "two". Therefore, the program outputs "onetwo".


## Exercise 5.11
The following table shows telephone area codes in the state of Georgia along
with the largest city in each area:

| *Area code* | *Major city* |
| :---: | :---: |
| 229 | Albany |
| 404 | Atlanta |
| 470 | Atlanta |
| 478 | Macon |
| 678 | Atlanta |
| 706 | Columbus |
| 762 | Columbus |
| 770 | Atlanta |
| 912 | Savannah |

Write a `switch` statement whose controlling expression is the variable
`area_code`. If the value of `area_code` is in the table, the `switch` statement
will print the corresponding city name. Otherwise, the `switch` statement will
display the message "Area code not recognized". Use the techniques discussed in
Section 5.3 to make the switch statement as simple as possible.

### Solution
```c
switch (area_code) {
    case 229:
        printf("Albany\n");
        break;
    case 404: case 470: case 678: case 770:
        printf("Atlanta\n");
        break;
    case 478:
        printf("Macon");
        break;
    case 706: case 762:
        printf("Columbus");
        break;
    case 912:
        printf("Savannah");
        break;
    default:
        printf("Area code not recognized\n");
}
```
