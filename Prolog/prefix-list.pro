program :- read(L1),read(L2),prefix(L1,L2,X),nl.
prefix(L1,L2,X) :- bagian(L1,L1,L2,X).
bagian(_,[],_,X) :- write(1).
bagian(_,_,[],X) :- write(0).
bagian(Z,[H|T],[H|K],X) :- bagian(Z,T,K,X).
bagian(Z,[H|T],[_|K],X) :- bagian(Z,Z,K,X).
:- program.