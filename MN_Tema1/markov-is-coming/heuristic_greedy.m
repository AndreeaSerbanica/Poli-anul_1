function [path] = heuristic_greedy (start_position, probabilities, Adj)
	% start_position -> the starting point in the labyrinth
	% probabilities -> vector of associated probabilities: including WIN and LOSE
	% Adj -> adjacency matrix
	
	% path -> the states chosen by the algorithm
  
  % TODO: heuristic_greedy implementation

    path = start_position;
    visited = sparse(1, size(probabilities))
    visited(start_position) = 1;
    while path(end) != size(probabilities) - 1
        position = path(end);
        if position == length(probabilities) % WIN state
            break;
        endif
        unvisited_neighbours = find(Adj(position, :) & ~visited);
        if isempty(unvisited_neighbours)
            path = path(1:end-1);
        endif
        [~, idx] = max(probabilities(unvisited_neighbours));
        next_position = unvisited_neighbours(idx);
        visited(next_position) = 1;
        path = [path, next_position];
    endwhile
    path = path';
endfunction
