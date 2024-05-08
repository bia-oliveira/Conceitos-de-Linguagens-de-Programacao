perm(X, Y, Z, W) :-
    neq3(X, Y, Z, W).

neq3(X, Y, Z, W) :-
    neq(X, Y),
    neq(X, Z),
    neq(X, W),
    neq(Y, Z),
    neq(Y, W),
    neq(Z, W).

neq(1, 2).
neq(1, 3).
neq(1, 4).
neq(2, 1).
neq(2, 3).
neq(2, 4).
neq(3, 1).
neq(3, 2).
neq(3, 4).
neq(4, 1).
neq(4, 2).
neq(4, 3).

