# Exercise 4.23
The following expression fails to compile due to operator precedence. Using Table 4.12 (p. 166), explain why it fails. How would you fix it?

```
string s = "word";
string pl = s + s[s.size() - 1] == 's' ? "" : "s" ;
```

+ has higher precedence than == and ?:. The expression will compute s + s[s.size() - 1] first and compare it with 's'.
Fix: 
```
string pl = s + (s[s.size() - 1] == 's' ? "" : "s") ;
```

# Exercise 4.24
Our program that distinguished between high pass, pass, and fail depended on the fact that the conditional operator is right associative. Describe how that operator would be evaluated if the operator were left associative.

The program 
```
finalgrade = (grade > 90) ? "high pass" : (grade < 60 ) ? "fail" : "pass";
```
would be the same as
```
finalgrade = ((grade > 90) ? "high pass" : (grade < 60 )) ? "fail" : "pass";
```
if grade is higher than 90, the result will be "high pass", which will result finalgrade always fail.

# Exercise 4.25
What is the value of ~'q' << 6 on a machine with 32-bit ints and 8 bit chars, that uses Latin-1 character set in which 'q' has the bit pattern 01110001?

'q': 01110001
~'q': 10001110
~'q'<<6: 00000000 00000000 0100011 10000000

# Exercise 4.26
In our grading example in this section, what would happen if we used unsigned int as the type for quiz1?
The c++ standard doesn't specify the size of integral type in bytes, but it specifies the minimum range they must be able to hold. The minimum range of unsigned int is 16 bits. The result depends on the implementation. If it is implemented only with the 16 bits, the program will have undefined behavior.

# Exercise 4.27
What is the result of each of these expressions?
```
unsigned long ul1 = 3, ul2 = 7;
(a) ul1 & ul2 // == 3
(b) ul1 | ul2 // == 7
(c) ul1 && yl2 // == true
(d) ul1 || ul2 // == true
```

# Exercise 4.29
Predict the output of the following code and explaining your reasoning.
int x[10]; int *p = x;
cout << sizeof(x)/sizeof(*x) << endl;
cout << sizeof(p)/sizeof(*p) << endl;

The first output is 10, which is the number of elements in the array
The second output is 1. The size of a pointer is 4 and the size of int is also 4.

# Exercise 4.30
Parenthesize the following expressions to match the default evaluation.
(a) sizeof (x + y)
(b) sizeof (p->mem[i])
(c) sizeof (a < b)
(d) sizeof f()

# Exercise 4.31
The program in this section used the prefix increment and decrement operators. Explain why we used prefix and not postfix. What changes would have to be made to use the postfix version?

# Exercise 4.32
Explain the following loop
```
constexpr int size = 5;
int ia[size] = {1,2,3,4,5};
for (int *ptr = ia, ix = 0;
     ix != size && ptr != ia+size;
     ++ix, ++ptr) { /* ... */ }

```

ia is an array of 5 ints. ptr is a pointer pointing to the first element in ia. ix is a index starting from 0. The for loop will go through the array from the begining to the end.

# Exercise 4.33
what does the following expression do?
```
someValue? ++x, ++y : --x, --y
```
this expression is a conditional expression. If someValue is not 0, it will be converted to boolean true and increment x and y. otherwise decrement x and y.

# Exercise 4.34
Given the variable definitions in this section, explain what conversions take place in the follwoing expressions:
(a) if (fval) // convert float to boolean
(b) dval = fval + ival // first convert int to float, then convert float to double
(c) dval + ival * cval // first convert char to int, then int to double

# Exercise 4.35
Given the following definitions,
char cval; int ival; unsigned int ui;
float fval; double dval;
identify the implicit type conversions, if any, taking place:
(a) cval = 'a' + 3; // convert char to int, convert int to char
(b) fval = ui - ival * 1.0; // convert int to unsigned int, then convert unsigned int to float
(c) dval = ui * fval; // convert unsigned int to float, then float to double
(d) cval = ival + fval + dval; // convert int to flaot, then float to double, then double to char

# Exercise 4.36
Assuming i is an int and d is double write the expression i *= d so that it does integral, rather than floating-point, multiplication.

i *= static_cast<int>(d)

# Exercise 4.37
Rewrite each of the following old-style casts to use a named cast:
int i; double d; const string *ps; char *pc; void *pv;
(a) pv = (void*)ps => pv = const_cast<string*>(ps)
(b) i = int(*pc) => i = static_cast<int>(*pc)
(c) pv = &d => pv = pv = static_cast<void*>(&d)
(d) pc = (char*) pv; => pc = static_cast<char*>(pv)

# Exercise 4.38
Explain the following expression
double slope = static_cast<double>(j/i); cast the result of j/i to double