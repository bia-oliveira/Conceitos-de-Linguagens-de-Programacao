ms(A11, A12, A13, A14,
   A21, A22, A23, A24,
   A31, A32, A33, A34,
   A41, A42, A43, A44):-
    p(A11, A12, A13, A14, A21, A22, A23, A24, A31, A32, A33, A34, A41, A42, A43, A44),
    A11 + A12 + A13 + A14 =:= 34,
    A21 + A22 + A23 + A24 =:= 34,
    A31 + A32 + A33 + A34 =:= 34,
    A41 + A42 + A43 + A44 =:= 34,
    A11 + A21 + A31 + A41 =:= 34,
    A12 + A22 + A32 + A42 =:= 34,
    A13 + A23 + A33 + A43 =:= 34,
    A14 + A24 + A34 + A44 =:= 34,
    A11 + A22 + A33 + A44 =:= 34,
    A14 + A23 + A32 + A41 =:= 34,
    pr(A11,A12,A13,A14),
    pr(A21,A22,A23,A24),
    pr(A31,A32,A33,A34),
    pr(A41,A42,A43,A44).

p(X1, X2, X3, X4, X5, X6, X7, X8, X9, X10, X11, X12, X13, X14, X15, X16) :-
    neq12(X1, X2, X3, X4, X5, X6, X7, X8, X9, X10, X11, X12, X13, X14, X15, X16).

neq12(X1, X2, X3, X4, X5, X6, X7, X8, X9, X10, X11, X12, X13, X14, X15, X16) :-
    neq(X1, X2),
    neq(X1, X3),
    neq(X1, X4),
    neq(X1, X5),
    neq(X1, X6),
    neq(X1, X7),
    neq(X1, X8),
    neq(X1, X9),
    neq(X1, X10),
    neq(X1, X11),
    neq(X1, X12),
    neq(X1, X13),
    neq(X1, X14),
    neq(X1, X15),
    neq(X1, X16),
    neq(X2, X3),
    neq(X2, X4),
    neq(X2, X5),
    neq(X2, X6),
    neq(X2, X7),
    neq(X2, X8),
    neq(X2, X9),
    neq(X2, X10),
    neq(X2, X11),
    neq(X2, X12),
    neq(X2, X13),
    neq(X2, X14),
    neq(X2, X15),
    neq(X2, X16),
    neq(X3, X4),
    neq(X3, X5),
    neq(X3, X6),
    neq(X3, X7),
    neq(X3, X8),
    neq(X3, X9),
    neq(X3, X10),
    neq(X3, X11),
    neq(X3, X12),
    neq(X3, X13),
    neq(X3, X14),
    neq(X3, X15),
    neq(X3, X16),
    neq(X4, X5),
    neq(X4, X6),
    neq(X4, X7),
    neq(X4, X8),
    neq(X4, X9),
    neq(X4, X10),
    neq(X4, X11),
    neq(X4, X12),
    neq(X4, X13),
    neq(X4, X14),
    neq(X4, X15),
    neq(X4, X16),
    neq(X5, X6),
    neq(X5, X7),
    neq(X5, X8),
    neq(X5, X9),
    neq(X5, X10),
    neq(X5, X11),
    neq(X5, X12),
    neq(X5, X13),
    neq(X5, X14),
    neq(X5, X15),
    neq(X5, X16),
    neq(X6, X7),
    neq(X6, X8),
    neq(X6, X9),
    neq(X6, X10),
    neq(X6, X11),
    neq(X6, X12),
    neq(X6, X13),
    neq(X6, X14),
    neq(X6, X15),
    neq(X6, X16),
    neq(X7, X8),
    neq(X7, X9),
    neq(X7, X10),
    neq(X7, X11),
    neq(X7, X12),
    neq(X7, X13),
    neq(X7, X14),
    neq(X7, X15),
    neq(X7, X16),
    neq(X8, X9),
    neq(X8, X10),
    neq(X8, X11),
    neq(X8, X12),
    neq(X8, X13),
    neq(X8, X14),
    neq(X8, X15),
    neq(X8, X16),
    neq(X9, X10),
    neq(X9, X11),
    neq(X9, X12),
    neq(X9, X13),
    neq(X9, X14),
    neq(X9, X15),
    neq(X9, X16),
    neq(X10, X11),
    neq(X10, X12),
    neq(X10, X13),
    neq(X10, X14),
    neq(X10, X15),
    neq(X10, X16),
    neq(X11, X12),
    neq(X11, X13),
    neq(X11, X14),
    neq(X11, X15),
    neq(X11, X16),
    neq(X12, X13),
    neq(X12, X14),
    neq(X12, X15),
    neq(X12, X16),
    neq(X13, X14),
    neq(X13, X15),
    neq(X13, X16),
    neq(X14, X15),
    neq(X14, X16),
    neq(X15, X16).

neq(1, 2).
neq(1, 3).
neq(1, 4).
neq(1, 5).
neq(1, 6).
neq(1, 7).
neq(1, 8).
neq(1, 9).
neq(1, 10).
neq(1, 11).
neq(1, 12).
neq(1, 13).
neq(1, 14).
neq(1, 15).
neq(1, 16).
neq(2, 1).
neq(2, 3).
neq(2, 4).
neq(2, 5).
neq(2, 6).
neq(2, 7).
neq(2, 8).
neq(2, 9).
neq(2, 10).
neq(2, 11).
neq(2, 12).
neq(2, 13).
neq(2, 14).
neq(2, 15).
neq(2, 16).
neq(3, 1).
neq(3, 2).
neq(3, 4).
neq(3, 5).
neq(3, 6).
neq(3, 7).
neq(3, 8).
neq(3, 9).
neq(3, 10).
neq(3, 11).
neq(3, 12).
neq(3, 13).
neq(3, 14).
neq(3, 15).
neq(3, 16).
neq(4, 1).
neq(4, 2).
neq(4, 3).
neq(4, 5).
neq(4, 6).
neq(4, 7).
neq(4, 8).
neq(4, 9).
neq(4, 10).
neq(4, 11).
neq(4, 12).
neq(4, 13).
neq(4, 14).
neq(4, 15).
neq(4, 16).
neq(5, 1).
neq(5, 2).
neq(5, 3).
neq(5, 4).
neq(5, 6).
neq(5, 7).
neq(5, 8).
neq(5, 9).
neq(5, 10).
neq(5, 11).
neq(5, 12).
neq(5, 13).
neq(5, 14).
neq(5, 15).
neq(5, 16).
neq(6, 1).
neq(6, 2).
neq(6, 3).
neq(6, 4).
neq(6, 5).
neq(6, 7).
neq(6, 8).
neq(6, 9).
neq(6, 10).
neq(6, 11).
neq(6, 12).
neq(6, 13).
neq(6, 14).
neq(6, 15).
neq(6, 16).
neq(7, 1).
neq(7, 2).
neq(7, 3).
neq(7, 4).
neq(7, 5).
neq(7, 6).
neq(7, 8).
neq(7, 9).
neq(7, 10).
neq(7, 11).
neq(7, 12).
neq(7, 13).
neq(7, 14).
neq(7, 15).
neq(7, 16).
neq(8, 1).
neq(8, 2).
neq(8, 3).
neq(8, 4).
neq(8, 5).
neq(8, 6).
neq(8, 7).
neq(8, 9).
neq(8, 10).
neq(8, 11).
neq(8, 12).
neq(8, 13).
neq(8, 14).
neq(8, 15).
neq(8, 16).
neq(9, 1).
neq(9, 2).
neq(9, 3).
neq(9, 4).
neq(9, 5).
neq(9, 6).
neq(9, 7).
neq(9, 8).
neq(9, 10).
neq(9, 11).
neq(9, 12).
neq(9, 13).
neq(9, 14).
neq(9, 15).
neq(9, 16).
neq(10, 1).
neq(10, 2).
neq(10, 3).
neq(10, 4).
neq(10, 5).
neq(10, 6).
neq(10, 7).
neq(10, 8).
neq(10, 9).
neq(10, 11).
neq(10, 12).
neq(10, 13).
neq(10, 14).
neq(10, 15).
neq(10, 16).
neq(11, 1).
neq(11, 2).
neq(11, 3).
neq(11, 4).
neq(11, 5).
neq(11, 6).
neq(11, 7).
neq(11, 8).
neq(11, 9).
neq(11, 10).
neq(11, 12).
neq(11, 13).
neq(11, 14).
neq(11, 15).
neq(11, 16).
neq(12, 1).
neq(12, 2).
neq(12, 3).
neq(12, 4).
neq(12, 5).
neq(12, 6).
neq(12, 7).
neq(12, 8).
neq(12, 9).
neq(12, 10).
neq(12, 11).
neq(12, 13).
neq(12, 14).
neq(12, 15).
neq(12, 16).
neq(13, 1).
neq(13, 2).
neq(13, 3).
neq(13, 4).
neq(13, 5).
neq(13, 6).
neq(13, 7).
neq(13, 8).
neq(13, 9).
neq(13, 10).
neq(13, 11).
neq(13, 12).
neq(13, 14).
neq(13, 15).
neq(13, 16).
neq(14, 1).
neq(14, 2).
neq(14, 3).
neq(14, 4).
neq(14, 5).
neq(14, 6).
neq(14, 7).
neq(14, 8).
neq(14, 9).
neq(14, 10).
neq(14, 11).
neq(14, 12).
neq(14, 13).
neq(14, 15).
neq(14, 16).
neq(15, 1).
neq(15, 2).
neq(15, 3).
neq(15, 4).
neq(15, 5).
neq(15, 6).
neq(15, 7).
neq(15, 8).
neq(15, 9).
neq(15, 10).
neq(15, 11).
neq(15, 12).
neq(15, 13).
neq(15, 14).
neq(15, 16).
neq(16, 1).
neq(16, 2).
neq(16, 3).
neq(16, 4).
neq(16, 5).
neq(16, 6).
neq(16, 7).
neq(16, 8).
neq(16, 9).
neq(16, 10).
neq(16, 11).
neq(16, 12).
neq(16, 13).
neq(16, 14).
neq(16, 15).

pr(A,B,C,D):-write(A),write(' '),
write(B),write(' '),
write(C),write(' '),
write(D),nl.