function [Error] = lasso_regression_cost_function(Theta, Y, FeatureMatrix, lambda)
  % Theta -> the vector of weights
  % Y -> the vector with all actual values
  % FeatureMatrix -> the matrix with all training examples
  % lambda -> regularization parameter that controls the amount of
  %           shrinkage applied to the regression coefficients

  % Error -> the error of the regularized cost function

  % TODO: lasso_regression_cost_function implementation
  [m, n] = size(FeatureMatrix);
  ssum = 0;
  for i = 1:m
    ssum2 = 0;
    for j = 1:n
      ssum2 += FeatureMatrix(i,j) * Theta(j+1);
    endfor
    ssum += (Y(i) - ssum2).^2;
  endfor
  Error = (1/m) * ssum + lambda * sum(abs(Theta(1:end)));
endfunction
