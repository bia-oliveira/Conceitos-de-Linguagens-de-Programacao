sudoku9x9(A11,A12,A13,A14,A15,A16,A17,A18,A19,
          A21,A22,A23,A24,A25,A26,A27,A28,A29,
          A31,A32,A33,A34,A35,A36,A37,A38,A39,
          A41,A42,A43,A44,A45,A46,A47,A48,A49,
          A51,A52,A53,A54,A55,A56,A57,A58,A59,
          A61,A62,A63,A64,A65,A66,A67,A68,A69,
          A71,A72,A73,A74,A75,A76,A77,A78,A79,
          A81,A82,A83,A84,A85,A86,A87,A88,A89,
          A91,A92,A93,A94,A95,A96,A97,A98,A99):-
    p9(A11,A12,A13,A14,A15,A16,A17,A18,A19),
    p9(A21,A22,A23,A24,A25,A26,A27,A28,A29),
    p9(A31,A32,A33,A34,A35,A36,A37,A38,A39),
    p9(A41,A42,A43,A44,A45,A46,A47,A48,A49),
    p9(A51,A52,A53,A54,A55,A56,A57,A58,A59),
    p9(A61,A62,A63,A64,A65,A66,A67,A68,A69),
    p9(A71,A72,A73,A74,A75,A76,A77,A78,A79),
    p9(A81,A82,A83,A84,A85,A86,A87,A88,A89),
    p9(A91,A92,A93,A94,A95,A96,A97,A98,A99),
    p9(A11,A12,A13,A21,A22,A23,A31,A32,A33),
    p9(A14,A15,A16,A24,A25,A26,A34,A35,A36),
    p9(A17,A18,A19,A27,A28,A29,A37,A38,A39),
    p9(A41,A42,A43,A51,A52,A53,A61,A62,A63),
    p9(A44,A45,A46,A54,A55,A56,A64,A65,A66),
    p9(A47,A48,A49,A57,A58,A59,A67,A68,A69),
    p9(A71,A72,A73,A81,A82,A83,A91,A92,A93),
    p9(A74,A75,A76,A84,A85,A86,A94,A95,A96).
    %p9(A77,A78,A79,A87,A88,A89,A97,A98,A99),
    %pr9(A11,A12,A13,A14,A15,A16,A17,A18,A19),
    %pr9(A21,A22,A23,A24,A25,A26,A27,A28,A29),
    %pr9(A31,A32,A33,A34,A35,A36,A37,A38,A39),
    %pr9(A41,A42,A43,A44,A45,A46,A47,A48,A49),
    %pr9(A51,A52,A53,A54,A55,A56,A57,A58,A59),
    %pr9(A61,A62,A63,A64,A65,A66,A67,A68,A69),
    %pr9(A71,A72,A73,A74,A75,A76,A77,A78,A79),
    %pr9(A81,A82,A83,A84,A85,A86,A87,A88,A89),
    %pr9(A91,A92,A93,A94,A95,A96,A97,A98,A99).
    

p9(X1, X2, X3, X4, X5, X6, X7, X8, X9) :-
    neq3(X1, X2, X3, X4, X5, X6, X7, X8, X9).

neq3(X1, X2, X3, X4, X5, X6, X7, X8, X9) :-
    neq(X1, X2),
    neq(X1, X3),
    neq(X1, X4),
    neq(X1, X5),
    neq(X1, X6),
    neq(X1, X7),
    neq(X1, X8),
    neq(X1, X9),
    neq(X2, X3),
    neq(X2, X4),
    neq(X2, X5),
    neq(X2, X6),
    neq(X2, X7),
    neq(X2, X8),
    neq(X2, X9),
    neq(X3, X4),
    neq(X3, X5),
    neq(X3, X6),
    neq(X3, X7),
    neq(X3, X8),
    neq(X3, X9),
    neq(X4, X5),
    neq(X4, X6),
    neq(X4, X7),
    neq(X4, X8),
    neq(X4, X9),
    neq(X5, X6),
    neq(X5, X7),
    neq(X5, X8),
    neq(X5, X9),
    neq(X6, X7),
    neq(X6, X8),
    neq(X6, X9),
    neq(X7, X8),
    neq(X7, X9),
    neq(X8, X9).

neq(1, 2).
neq(1, 3).
neq(1, 4).
neq(1, 5).
neq(1, 6).
neq(1, 7).
neq(1, 8).
neq(1, 9).
neq(2, 1).
neq(2, 3).
neq(2, 4).
neq(2, 5).
neq(2, 6).
neq(2, 7).
neq(2, 8).
neq(2, 9).
neq(3, 1).
neq(3, 2).
neq(3, 4).
neq(3, 5).
neq(3, 6).
neq(3, 7).
neq(3, 8).
neq(3, 9).
neq(4, 1).
neq(4, 2).
neq(4, 3).
neq(4, 5).
neq(4, 6).
neq(4, 7).
neq(4, 8).
neq(4, 9).
neq(5, 1).
neq(5, 2).
neq(5, 3).
neq(5, 4).
neq(5, 6).
neq(5, 7).
neq(5, 8).
neq(5, 9).
neq(6, 1).
neq(6, 2).
neq(6, 3).
neq(6, 4).
neq(6, 5).
neq(6, 7).
neq(6, 8).
neq(6, 9).
neq(7, 1).
neq(7, 2).
neq(7, 3).
neq(7, 4).
neq(7, 5).
neq(7, 6).
neq(7, 8).
neq(7, 9).
neq(8, 1).
neq(8, 2).
neq(8, 3).
neq(8, 4).
neq(8, 5).
neq(8, 6).
neq(8, 7).
neq(8, 9).
neq(9, 1).
neq(9, 2).
neq(9, 3).
neq(9, 4).
neq(9, 5).
neq(9, 6).
neq(9, 7).
neq(9, 8).


%pr9(A,B,C,D,E,F,G,H,I):-write(A),write(' '),write(B),write(' '),write(C),write(' '),write(D),write(' '),write(E),write(' '),write(F),write(' '),write(G),write(' '),write(H),write(' '),write(I),nl.
