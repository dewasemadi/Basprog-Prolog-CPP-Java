program :- read(List), read(N), pisah(List, N, X), write(X), nl.

pisah(List, N, [H|[T]]) :- append(H, T, List), length(H, N).

:- program.