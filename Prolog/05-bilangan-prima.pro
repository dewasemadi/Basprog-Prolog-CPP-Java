program :- read(A), B is A div 2, prima(A,B), nl.

prima(A,B) :- A == 1, write(0).
prima(A,B) :- B == 1, write(1).
prima(A,B) :- T is A mod B, T == 0, write(0).
prima(A,B) :- T is B-1, prima(A,T).

:-program.

