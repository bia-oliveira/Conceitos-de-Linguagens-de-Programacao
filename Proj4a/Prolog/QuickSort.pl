:- use_module(library(random)).

partition(_, [], [], []).
partition(Pivot, [H|T], [H|L], G) :- H =< Pivot, partition(Pivot, T, L, G).
partition(Pivot, [H|T], L, [H|G]) :- H > Pivot, partition(Pivot, T, L, G).

quick_sort([], []).
quick_sort([H|T], Sorted) :-
    partition(H, T, L, G),
    quick_sort(L, SortedL),
    quick_sort(G, SortedG),
    append(SortedL, [H|SortedG], Sorted).


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

    quick_sort(List1000, Result), write(Result), nl.
