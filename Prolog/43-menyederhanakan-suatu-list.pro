flatten([],[]).
flatten([H|T],[H|X]) :- \+ is_list(H), flatten(T,X).
flatten([H|T],X) :- is_list(H), flatten(H,H1), flatten(T,T1), merge(H1,T1,X).

merge([],B,B).
merge(A,[],A).
merge([H|T],B,[H|X]) :- merge(T,B,X).


% Latihan menyederhanakan suatu list
% ?- flatten([[2],3,4,[[a,b]]],X).
% X = [2,3,4,a,b].