ls5x5(A11, A12, A13, A14, A15,
      A21, A22, A23, A24, A25,
      A31, A32, A33, A34, A35,
      A41, A42, A43, A44, A45,
      A51, A52, A53, A54, A55):-
    perm(A11, A12, A13, A14, A15), perm(A21, A22, A23, A24, A25),
    perm(A31, A32, A33, A34, A35), perm(A41, A42, A43, A44, A45),
    perm(A51, A52, A53, A54, A55),
    perm(A11, A21, A31, A41, A51), perm(A12, A22, A32, A42, A52),
    perm(A13, A23, A33, A43, A53), perm(A14, A24, A34, A44, A54),
    perm(A15, A25, A35, A45, A55),
    write('fim'),nl.
    %prow(A11, A12, A13, A14, A15), nl,
    %prow(A21, A22, A23, A24, A25), nl,
    %prow(A31, A32, A33, A34, A35), nl,
    %prow(A41, A42, A43, A44, A45), nl,
    %prow(A51, A52, A53, A54, A55), nl.

%prow(X, Y, Z, B, C):- write(X), write(' '), write(Y), write(' '), write(Z), write(' '), write(B), write(' '), write(C), nl.


perm(X, Y, Z, W, V) :-
    neq4(X, Y, Z, W, V).

neq4(X, Y, Z, W, V) :-
    neq(X, Y),
    neq(X, Z),
    neq(X, W),
    neq(X, V),
    neq(Y, Z),
    neq(Y, W),
    neq(Y, V),
    neq(Z, W),
    neq(Z, V),
    neq(W, V).

neq(1, 2).
neq(1, 3).
neq(1, 4).
neq(1, 5).
neq(2, 1).
neq(2, 3).
neq(2, 4).
neq(2, 5).
neq(3, 1).
neq(3, 2).
neq(3, 4).
neq(3, 5).
neq(4, 1).
neq(4, 2).
neq(4, 3).
neq(4, 5).
neq(5, 1).
neq(5, 2).
neq(5, 3).
neq(5, 4).


