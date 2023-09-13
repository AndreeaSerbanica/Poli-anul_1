function [Y, InitialMatrix] = parse_data_set_file(file_path)
  % path -> a relative path to the .txt file

  % Y -> the vector with all actual values
  % InitialMatrix -> the matrix that must be transformed

  % TODO: parse_data_set_file implementation

  fid = fopen(file_path, 'r');

  m = fscanf(fid, '%d', 1);
  n = fscanf(fid, '%d', 1);

InitialMatrix = cell(m, n);
for (i = 1:m)
  Y(i) = fscanf(fid, '%ld', 1);
  for (j = 1:n)
    InitialMatrix{i, j} = fscanf(fid, '%s', 1);
  endfor
endfor


fclose(fid);
endfunction
