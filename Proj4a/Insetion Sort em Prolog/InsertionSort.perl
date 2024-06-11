:- use_module(library(random)).

insert(X, [], [X]).
insert(X, [H|T], [X,H|T]) :- X =< H.
insert(X, [H|T], [H|R]) :- X > H, insert(X, T, R).

insertion_sort([], []).
insertion_sort([H|T], Sorted) :-
    insertion_sort(T, Temp),
    insert(H, Temp, Sorted).

generate_random_list(0, []).
generate_random_list(N, [H|T]) :-
    N > 0,
    random_between(0, 100000, H),
    N1 is N - 1,
    generate_random_list(N1, T).


main :-
    generate_random_list(10, List10),
    generate_random_list(100, List100),
    generate_random_list(1000, List1000),
    generate_random_list(10000, List10000),

    insertion_sort(List1000, Result), write(Result), nl.
