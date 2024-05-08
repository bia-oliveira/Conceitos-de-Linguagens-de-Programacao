perm(X, Y, Z, W, V, U) :-
    neq5(X, Y, Z, W, V, U).

neq5(X, Y, Z, W, V, U) :-
    neq(X, Y),
    neq(X, Z),
    neq(X, W),
    neq(X, V),
    neq(X, U),
    neq(Y, Z),
    neq(Y, W),
    neq(Y, V),
    neq(Y, U),
    neq(Z, W),
    neq(Z, V),
    neq(Z, U),
    neq(W, V),
    neq(W, U),
    neq(V, U).

neq(1, 2).
neq(1, 3).
neq(1, 4).
neq(1, 5).
neq(1, 6).
neq(2, 1).
neq(2, 3).
neq(2, 4).
neq(2, 5).
neq(2, 6).
neq(3, 1).
neq(3, 2).
neq(3, 4).
neq(3, 5).
neq(3, 6).
neq(4, 1).
neq(4, 2).
neq(4, 3).
neq(4, 5).
neq(4, 6).
neq(5, 1).
neq(5, 2).
neq(5, 3).
neq(5, 4).
neq(5, 6).
neq(6, 1).
neq(6, 2).
neq(6, 3).
neq(6, 4).
neq(6, 5).
