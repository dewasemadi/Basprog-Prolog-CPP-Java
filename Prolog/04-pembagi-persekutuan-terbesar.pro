program :- read(A), read(B), fpb(A, B, X), write(X), nl.

fpb(A,0,A).
fpb(A,B,X):- B>0, X1 is A mod B, fpb(B,X1,X).

:- program.


