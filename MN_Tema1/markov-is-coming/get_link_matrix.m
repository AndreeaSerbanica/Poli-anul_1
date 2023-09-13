function [Link] = get_link_matrix (Labyrinth)
	% Labyrinth -> the matrix of all encodings

  % Link -> the link matrix associated to the given labyrinth

  % TODO: get_link_matrix implementation

## START OF GET_ADJ_MATRIX


  [rows, cols] = size(Labyrinth);
  N = rows * cols;
  pozLabyrinth = sparse(rows, cols);
  contor = 1;
  for i = 1:rows
    for j = 1:cols
      pozLabyrinth(i, j) = contor;
      contor++;
    endfor
  endfor

  win = N + 1;
  lose = N + 2;
  Adj = sparse(N + 2, N + 2);

  Adj(win, win) = 1;
  Adj(lose, lose) = 1;

  for i = 1:rows
    for j = 1:cols
      if bitget(Labyrinth(i,j), 4) == 0 % VERIFY N BIT
        if i-1 >= 1
          p1 = pozLabyrinth(i,j);
          p2 = pozLabyrinth(i-1, j);
          Adj(p1, p2) = Adj(p2, p1) = 1;
        else
          p = pozLabyrinth(i,j);
          Adj(p, win) = 1;
        endif
      endif

      if bitget(Labyrinth(i,j), 3) == 0 % VERIFY S BIT
        if i+1 <= rows
          p1 = pozLabyrinth(i,j);
          p2 = pozLabyrinth(i+1, j);
          Adj(p1, p2) = Adj(p2, p1) = 1;
        else
          p = pozLabyrinth(i,j);
          Adj(p, win) = 1;;
        endif
      endif

      if bitget(Labyrinth(i,j), 2) == 0 % VERIFY E BIT
        if j+1 <= cols
          p1 = pozLabyrinth(i,j);
          p2 = pozLabyrinth(i, j+1);
          Adj(p1, p2) = Adj(p2, p1) = 1;
        else
          p = pozLabyrinth(i,j);
          Adj(p,lose) = 1;
        endif
      endif

      if bitget(Labyrinth(i,j), 1) == 0 % VERIFY V BIT
        if j-1 >= 1
          p1 = pozLabyrinth(i,j);
          p2 = pozLabyrinth(i, j-1);
          Adj(p1, p2) = Adj(p2, p1) = 1;
        else
          p = pozLabyrinth(i,j);
          Adj(p, lose) = 1;
        endif
      endif

    endfor
  endfor

##END OF GET_ADJ_MATRIX


Link = Adj;
array =[]

for i = 1: (N+2)
contor = 0;
  for j = 1:(N+2)
    if Link(i, j) == 1
      contor++;
    endif
  endfor
array(end+1) = contor;
endfor

for i = 1:(N+2)
  for j = 1:(N+2)
    if Link(i,j) == 1;
      Link(i,j) = 1/array(i);
    endif
  endfor
endfor

endfunction
