program :- read(L1), read(L2), merge(L1, L2, X), write(X), nl.

merge([], L2, L2).
merge(L1, [], L1).
merge([H|T], L2, [H|X]) :- merge(T,L2,X).

:- program.