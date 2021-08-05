program :- read(A), jmldigit(A, B), write(B), nl.

jmldigit(Num,Num):- Num < 10.
jmldigit(Num,Sum):- Num >= 10, Digit is mod(Num,10), NewNum is Num // 10, jmldigit(NewNum,TempSum), Sum is TempSum + Digit.

:-program.