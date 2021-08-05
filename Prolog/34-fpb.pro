program :- read(A), read(B), gcd(A,B,X), write(X), nl.

gcd(A,B,X) :- A =:= 0, X is B.
gcd(A,B,X) :- T is B mod A, gcd(T, A, X).

:- program.

% int gcd(int a, int b){
%     if(a==0) 
%         return b;
%     return gcd(b % a, a);
% }