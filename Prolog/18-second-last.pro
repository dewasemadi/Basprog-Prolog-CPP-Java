program :- read(A), second-last(A,X), write(X), nl.

second-last([H,T], X) :- X is H.
second-last([H|T], X) :- second-last(T, X).

:- program.