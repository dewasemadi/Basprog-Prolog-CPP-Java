program :- read(L), urai(L,X), write(X), nl.

urai([],[]).
urai([[H,H1]|T],Y):- new(H,H1,T1), append(T1,T,X), urai(X,Y),!.
urai([H|T],[H|Y]):- urai(T,Y),!.
 
new(H,0,[]) :-!.
new(H,T,[H|Y]):- T1 is T-1, new(H,T1,Y).

:- program.