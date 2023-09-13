function [FeatureMatrix] = prepare_for_regression(InitialMatrix)
  % InitialMatrix -> the matrix that must be transformed

  % FeatureMatrix -> the matrix with all training examples

  % TODO: prepare_for_regression implementation

  [row, cols] = size(InitialMatrix);

  FeatureMatrix = zeros(row, cols);
  for (i = 1:row)
    jcont = 1;
    for (j = 1:cols)
      if (strcmp(InitialMatrix{i, j},"yes"))
        FeatureMatrix(i, jcont) = 1;
      elseif (strcmp(InitialMatrix{i, j},"no"))
        FeatureMatrix(i, jcont) = 0;
      elseif (strcmp("semi-furnished",InitialMatrix{i, j}))
        FeatureMatrix(i, jcont) = 1;
        FeatureMatrix(i, jcont+1) = 0;
        jcont++;
      elseif (strcmp("unfurnished",InitialMatrix{i, j}))
        FeatureMatrix(i, jcont) = 0;
        FeatureMatrix(i, jcont+1) = 1;
        jcont++;
      elseif (strcmp("furnished",InitialMatrix{i, j}))
        FeatureMatrix(i, jcont) = 0;
        FeatureMatrix(i, jcont+1) = 0;
        jcont++;
      else
        FeatureMatrix(i, jcont) = str2double(InitialMatrix{i, j});
      endif
      jcont++;
    endfor
  endfor

endfunction
