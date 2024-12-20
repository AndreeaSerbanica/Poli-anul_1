function [Theta] = gradient_descent(FeatureMatrix, Y, n, m, alpha, iter)
  % FeatureMatrix -> the matrix with all training examples
  % Y -> the vector with all actual values
  % n -> the number of predictors
  % m -> the number of trainings
  % alpha -> the learning rate
  % iter -> the number of iterations

  % Theta -> the vector of weights

  % TODO: gradient_descent implementation

  Theta = zeros(n+1, 1);
  for k = 1:iter
    for j = 1:n
      ssum = 0;
      for i = 1:m
        ssum += (sum(FeatureMatrix(i)*Theta) - Y(i)) * FeatureMatrix(i,j);
      endfor
      Theta(j+1) = Theta(j+1) - alpha * (1/m) * ssum;
    endfor
  endfor
  Theta(1) = 0;
endfunction

