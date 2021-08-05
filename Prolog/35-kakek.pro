program :- read(A), kakek(A,X), write(X), nl.

ayah(abdul, mukidi).
ayah(mukidi, sinta).
kakek(A,X) :- ayah(A, Y), ayah(Y, X).

:- program.