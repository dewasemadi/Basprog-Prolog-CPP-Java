program :- read(A), read(B), merge(A,B,X), write(X), nl.

merge([], [], []).
merge(L,[],L).
merge([],B,B).
merge([H1|T1], [H2|T2], [H1|X]) :- H1 < H2, merge(T1,[H2|T2],X).
merge([H1|T1], [H2|T2], [H2|X]) :- H1 >= H2, merge([H1|T1], T2, X).

:- program.