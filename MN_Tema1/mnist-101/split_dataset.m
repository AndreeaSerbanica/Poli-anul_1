function [X_train, y_train, X_test, y_test] = split_dataset(X, y, percent)
  % X -> the loaded dataset with all training examples
  % y -> the corresponding labels
  % percent -> fraction of training examples to be put in training dataset

  % X_[train|test] -> the datasets for training and test respectively
  % y_[train|test] -> the corresponding labels

  % Example: [X, y] has 1000 training examples with labels and percent = 0.85
  %           -> X_train will have 850 examples
  %           -> X_test will have the other 150 examples

  % TODO: split_dataset implementation


% shuffle the dataset
  shuffled_indices = randperm(size(X, 1));
  shuffled_X = X(shuffled_indices, :);
  shuffled_y = y(shuffled_indices);

  % calculate the number of examples for training and testing
  num_train = round(size(X, 1) * percent);
  num_test = size(X, 1) - num_train;

  % create training and testing datasets
  X_train = shuffled_X(1:num_train, :);
  X_test = shuffled_X(num_train+1:end, :);
  y_train = shuffled_y(1:num_train);
  y_test = shuffled_y(num_train+1:end);

##endfunction
