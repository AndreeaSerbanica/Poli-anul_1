function [G, c] = get_Jacobi_parameters (Link)
	% Link -> the link matrix (edge with probabilities matrix)

  % G -> iteration matrix
	% c -> iteration vector

  % TODO: get_Jacobi_parameters

  [rows, cols] = size(Link);
  N = rows;

  for i = 1:(N-2)
    for j = 1:(N-2)
      G(i,j) = Link(i,j);
    endfor
  endfor


  c = sparse(N-2,1);
  for i = 1:(N-2)
    c(i) = Link(i, N-1);
  endfor


endfunction
