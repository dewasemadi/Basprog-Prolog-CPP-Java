program :- read(A), read(B), terbesar(A,B,X), write(X), nl.

terbesar(A,B,X) :- A > B, X is A ; X is B.

:- program.