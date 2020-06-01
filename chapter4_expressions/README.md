#Exercise 4.23
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

#Exercise 4.24
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
