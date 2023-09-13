function [Y, InitialMatrix] = parse_csv_file(file_path)
  % path -> a relative path to the .csv file

  % Y -> the vector with all actual values
  % InitialMatrix -> the matrix that must be transformed

  % TODO: parse_csv_file implementation

  fid = fopen(file_path, 'r');

  useless_line = fscanf(fid, "%s", 1);
  cont_line = 1;
  while ~feof(fid)
    data  = fscanf(fid, "%s", 1);
    data2 = strsplit(data, ',');
    Y(cont_line) = str2double(data2{1});
    for (i = 1:12)
      InitialMatrix{cont_line, i} = data2{i+1};
    endfor
    cont_line++;
  endwhile

  fclose(fid);

endfunction
