function [Error] = linear_regression_cost_function(Theta, Y, FeatureMatrix)
  % Theta -> the vector of weights
  % Y -> the vector with all actual values
  % FeatureMatrix -> the matrix with all training examples

  % Error -> the error of the regularized cost function

  % TODO: linear_regression_cost_function implementation

  [m, n] = size(FeatureMatrix);
  ssum = 0;
  for i = 1:m
    ssum2 = 0;
    for j = 1:n
      ssum2 += FeatureMatrix(i,j) * Theta(j+1);
    endfor
    ssum += (ssum2 - Y(i)).^2;
  endfor
  Error = (1/(2*m)) * ssum;
endfunction
