:- use_module(library(random)).

bubble([], []).
bubble([X], [X]).
bubble([X,Y|T], [Y|R]) :- X > Y, bubble([X|T], R).
bubble([X,Y|T], [X|R]) :- X =< Y, bubble([Y|T], R).

bubble_sort(List, Sorted) :-
    bubble(List, Temp),
    !,
    bubble_sort(Temp, Sorted).
bubble_sort(Sorted, Sorted).

generate_random_list(0, []).
generate_random_list(N, [H|T]) :-
    N > 0,
    random_between(0, 10000, H),
    N1 is N - 1,
    generate_random_list(N1, T).


main :-
    generate_random_list(10, List10),
    %generate_random_list(100, List100),
    %generate_random_list(1000, List1000),
    %generate_random_list(10000, List10000),

    bubble_sort(List10, Result), write(Result), nl.
