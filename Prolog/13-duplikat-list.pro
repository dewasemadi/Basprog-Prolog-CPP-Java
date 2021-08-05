program :- read(L), read(N), duplikat(L, N, X), write(X), nl.

duplikat([H], 1, [H]) :- !.
duplikat([H], N, [H|X]) :- M is N - 1, M > 0, duplikat([H], M, X).
duplikat([H|T], N, X) :- duplikat([H], N, Y), duplikat(T, N, Z), !, append(Y, Z, X).

:- program.