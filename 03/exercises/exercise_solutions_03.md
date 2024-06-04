# Solutions to chapter 3 exercises
## Exercise 3.01
What output do the following calls of `printf` produce?

(a) `printf("%6d,%4d", 86, 1040);`  
(b) `printf("%12.5e", 30.253);`  
(c) `printf("%.4f", 83.162);`  
(d) `printf("%-6.2g", .0000009979);`

### Solution
(a) `86,1040`  
(b) `3.02530e+01`  
(c) `83.1620`  
(d) `1e-06`


## Exercise 3.02
Write calls of `printf` that display a `float` variable `x` in the following
formats.

(a) Exponential notation; left-justified in a field of size 8: one digit after
the decimal point.  
(b) Exponential notation: right-justified in a field of size 10; six digits
after the decimal point.  
(c) Fixed decimal notation; left-justified in a field of size 8; three digits
after the decimal point.  
(d) Fixed decimal notation; right-justified in a field of size 6; no digits
after the decimal point.

### Solution
(a) `printf("%8.1e", x);`  
(b) `printf("%-10.6e", x);`  
(c) `printf("%8.3f", x);`  
(d) `printf("%-6.0f", x);`


## Exercise 3.03
For each of the following pairs of `scanf` format strings, indicate whether or
not the two strings are equivalent. If they're not, show how they can be
distinguished.

```
(a) "%d"       versus " %d"
(b) "%d-%d-%d" versus "%d -%d -%d"
(c) "%f"       versus "%f "
(d) "%f,%f"    versus "%f, %f"
```

### Solution
(a), (b) and (d) are the same, because `scanf` matches any number (including zero) whitespace characters. In (c) however, `scanf` will look for a non-whitespace character because of the trailing space. This results in the program ´hanging' until the user enters a non-whitespace character.


## Exercise 3.04
Suppose that we call `scanf` as follows:

```c
scanf("%d%f%d", &i, &x, &j);
```

If the user enters

```
10.3 5 6
```

what will be the values of `i`, `x` and `j` after the call? (Assume that `i` and
`j` are `int` variables and `x` is a `float` variable.)

### Solution
```
i = 10
x = 0.3
j = 5
```

Counterintuitively, the decimal will end the input for `i` because `scanf` expects an integer. Next, this decimal point and '3' will next be stored in `x`. Finally, '5' will be stored in `j`. The remaining '6' is then left to be read by another call to `scanf`.


## Exercise 3.05
Suppose that we call `scanf` as follows:

```c
scanf("%f%d%f", &x, &i, &y);
```

If the user enters

```
12.3 45.6 789
```

what will be the values of `x`, `i` and `y` after the call? (Assume that `x` and
`y` are `float` variables and `i` is an `int` variable.)

### Solution
```
x = 12.3
i = 45
y = 0.6
```

`scanf` will store `12.3` in `x`. Next, it will read up until the decimal point. Expecting an `int`, `scanf` stores `45` in `i` and puts back the decimal point in the input string. Finally, it stores `.6` in `y`. The remaining `789` is left for another call to `scanf`.

A word of caution when trying to examine the contents of the variables with `printf`: printing e.g. the contents of `x` will not show `12.3` but a different number entirely, `1095027917`. This is because `scanf` actually stores the following in `x`:

`01000001010001001100110011001101`

This the binary representation of a `float`, but it is stored in `x` which is of type `int`. The binary representation of integers and floating point numbers is not the same. If we were to print the contents of `x`, this would show the 2's complement decimal interpretation of the above binary number, which is `1095027917`.


## Exercise 3.06
Show how to modify the `addfrac.c` program of Section 3.2 so that the user is allowed to enter fractions that contain spaces before and after each `/` character.

### Solution
We simply add a space after the `%d` format specifier for each `scanf` call. This enables `scanf` to match whitespace characters between the two integers and the `/` character.

See `addfrac.c`