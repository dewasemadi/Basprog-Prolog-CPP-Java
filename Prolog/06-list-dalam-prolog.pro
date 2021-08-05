program :- read(N), read(L), kelipatan(N, L, X), write(X), nl.

kelipatan(_, [], 0).
kelipatan(N, [H|T], X) :- Y is H mod N, Y =:= 0, kelipatan(N,T,Z), X is Z+1.
kelipatan(N, [H|T], X) :- Y is H mod N, Y =\= 0, kelipatan(N,T,X).

:- program.