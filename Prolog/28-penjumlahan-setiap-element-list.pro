program:- read(L), sum(L,X), write(X), nl.

sum([],0).
sum([H|T], X) :- sum(T,R), X is H+R.

:- program.