:- use_module(library(random)).

split([], [], []).
split([X], [X], []).
split([X,Y|T], [X|L], [Y|R]) :- split(T, L, R).

merge([], R, R).
merge(L, [], L).
merge([X|T1], [Y|T2], [X|R]) :- X =< Y, merge(T1, [Y|T2], R).
merge([X|T1], [Y|T2], [Y|R]) :- X > Y, merge([X|T1], T2, R).

merge_sort([], []).
merge_sort([X], [X]).
merge_sort(List, Sorted) :-
    split(List, L1, L2),
    merge_sort(L1, Sorted1),
    merge_sort(L2, Sorted2),
    merge(Sorted1, Sorted2, Sorted).

generate_random_list(0, []).
generate_random_list(N, [H|T]) :-
    N > 0,
    random_between(0, 10000, H),
    N1 is N - 1,
    generate_random_list(N1, T).


main :-
    generate_random_list(10, List10),
    generate_random_list(100, List100),
    generate_random_list(1000, List1000),
    %generate_random_list(10000, List10000),

    merge_sort(List1000, Result), write(Result), nl.
