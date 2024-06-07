% Função A de Peter e Robinson
a(0, N, Result) :- Result is N + 1.
a(M, 0, Result) :-
    M1 is M - 1,
    a(M1, 1, Result).
a(M, N, Result) :-
    M1 is M - 1,
    N1 is N - 1,
    a(M, N1, Temp),
    a(M1, Temp, Result).