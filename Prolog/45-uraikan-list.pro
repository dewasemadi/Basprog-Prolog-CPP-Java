program :- read(L), senarai(L, X), merge(A,B,X), write(X), nl.

senarai([E,1],[E]).
senarai([E,N],[E|R]) :- N>1, N1 is N-1, senarai([E,N1],R).
uraikan([H|T],[H|X]) :- \+ is_list(H), uraikan(T,X).         
uraikan([[E,L]|T],X) :- senarai([E,L],R1), uraikan(T,R2), merge(R1,R2,X).

merge([],B,B).
merge(A,[],A).
merge([H|T],B,[H|X)) :- merge(T,B,X).

:- program.
% Latihan uraikan
% ?- uraikan(3,4,[a,3],[9,2]],X).
% X = [3,4,a,a,a,9,9].