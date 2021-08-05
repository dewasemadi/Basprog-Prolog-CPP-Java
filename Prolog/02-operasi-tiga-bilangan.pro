program :- read(A), read(B), read(C), operasi(A, B, C, X), write(X), nl.

operasi(A, B, C, X) :- C>0, X is A+B+C; C<0, X is A+B+C; C=:=0, X is A*B.

:- program.