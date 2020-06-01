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