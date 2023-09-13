## Copyright (C) 2021 Andrei
##
## This program is free software: you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
##
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with this program.  If not, see <https://www.gnu.org/licenses/>.

## -*- texinfo -*-
## @deftypefn {} {@var{retval} =} KNN (@var{input1}, @var{input2})
##
## @seealso{}
## @end deftypefn

## Author: Andrei <Andrei@DESKTOP-PK505U9>
## Created: 2021-08-09

function prediction = KNN (labels, Y, test, k)
  % Initialize prediction
  prediction = -1;

  % Initialize distances
  [m, n] = size(Y);
  distance = zeros(m, 1);

  % Calculate the Euclidean distance between each row and the test vector
  for i = 1:m
    distance(i) = norm(Y(i, :) - test);
  end

  % Sort the distances in ascending order and keep the first k values
  [~, indices] = sort(distance);
  k_nearest_labels = labels(indices(1:k));

  % Calculate the prediction as the median of the k nearest labels
  prediction = median(k_nearest_labels);
endfunction
