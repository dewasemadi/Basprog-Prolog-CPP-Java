program :- read(List), judul(List,X), write(X), nl.

judul([],[]).
judul([book(_,X,_,_)|T],[X|Y]) :- judul(T,Y).

:- program.