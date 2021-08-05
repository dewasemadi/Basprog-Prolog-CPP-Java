program :- read(L), read(N), find(L,N,R), write(R), nl.

find([H|_],1,H).
find([_|T],N,X) :- find(T,N1,X), N is N1+1.

:- program.