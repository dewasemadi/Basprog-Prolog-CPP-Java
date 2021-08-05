program :- read(A), read(B), pangkat(A,B,X), write(X), nl.

pangkat(A,B,X) :- X is round(A**B).

:- program.