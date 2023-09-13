function [decoded_path] = decode_path (path, lines, cols)
	% path -> vector containing the order of the states that arrived
	% 		 to a winning position
	% lines -> numeber of lines
	% cols -> number of columns
	
	% decoded_path -> vector of pairs (line_index, column_index)
  %                 corresponding to path states
  % hint: decoded_path does not contain indices for the WIN state

  % TODO: decode_path implementation 

	contor = 1;
	for i = 1:lines
		for j = 1:cols
		mat_idx(i, j) = contor;
		contor++;
		endfor
	endfor

	sizePath = size(path,1) -1;
	contor = 1;
	idx = zeros(sizePath, 2)
	for i = 1:sizePath
		[r, c] = find(mat_idx == path(i));
		idx(contor,1) = r;
		idx(contor,2) = c;
		contor++;
	endfor
	decoded_path = idx;
endfunction