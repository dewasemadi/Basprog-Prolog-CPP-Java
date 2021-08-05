program :- read(A1), kompres(A1,A2), write(A2), nl.

kompres(A1,A2) :- pack(A1,A), change(A,A2).

pack([X],[[X]]).
pack([N,M|M1],[[N]|PM1]):- N \= M,pack([M|M1], PM1).
pack([N,N|N1],[[N|NN]|M]):- pack([N|N1], [NN|M]).
change([],[]).
change([[X|Xs]|Ys],[[X,N]|Zs]) :- length([X|Xs],N), change(Ys,Zs).

:-program.