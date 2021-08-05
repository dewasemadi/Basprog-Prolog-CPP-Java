program :- read(L), ganjil(L, X), write(X), nl.

ganjil([],[]).
ganjil([H], [H]).
ganjil([H1|[_|T]], [H1|X]) :- ganjil(T,X).

:- program.

%1,2,3,4,5

%h1 = 1
%T = 3
