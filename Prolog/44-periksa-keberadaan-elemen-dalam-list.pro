program :- read(E), read(L), ada(E,L), nl.

ada(E,L) :- flatten(L,X), member(E,X).

:- program.