program :- read(N), read(L), count(L,N,X), write(X), nl.

count([],_,0).
count([X|T],X,N):- !, count(T,X,Y), N is Y+1.
count([_|T],X,Y):- count(T,X,Y).

:- program.

