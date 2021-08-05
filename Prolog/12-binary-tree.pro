program :- read(Tree), hitung(Tree,X), write(X), nl.	

hitung(tree(_,nil,nil),1) :- !.
hitung(nil, 0).
hitung(tree(_,L,R),N) :- hitung(L, NL), hitung(R, NR), N is NL+NR.

:- program.