program :- read(N), read(M), kelipatan(N,M), nl.

kelipatan(N,M) :- N mod M =:= 0.
kelipatan(N,M) :- T is N mod M, T =:= 0.

:- program.

% apakah 4 kelipatan dari 2?
% output program hanya yes atau no