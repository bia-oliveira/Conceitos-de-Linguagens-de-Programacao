% Caso base: p = 0
ackermann(M, N, 0, Result) :- 
    Result is M + N.

% Caso base: n = 0, p = 1
ackermann(M, 0, 1, 0).

% Caso base: n = 0, p = 2
ackermann(M, 0, 2, M).

% Caso: p > 2
ackermann(_, _, P, P) :- 
    P > 2.

% Caso recursivo: n > 0, p > 0
ackermann(M, N, P, Result) :- 
    N > 0, P > 0,
    N1 is N - 1,
    P1 is P - 1,
    ackermann(M, N1, P, Temp),
    ackermann(M, Temp, P1, Result).

