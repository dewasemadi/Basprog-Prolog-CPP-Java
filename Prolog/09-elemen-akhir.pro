program :- read(L), akhir(L,X), write(X), nl.

akhir([_|T], X) :- akhir(T,X).
akhir([X], X).

:- program.