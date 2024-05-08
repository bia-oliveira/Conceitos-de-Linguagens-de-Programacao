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
