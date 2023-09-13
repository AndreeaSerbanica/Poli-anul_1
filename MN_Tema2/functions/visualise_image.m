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
## @deftypefn {} {@var{retval} =} visualise_image (@var{input1}, @var{input2})
##
## @seealso{}
## @end deftypefn

## Author: Andrei <Andrei@DESKTOP-PK505U9>
## Created: 2021-09-10

function im = visualise_image (train_mat, number)
    % Initialize the final matrix.
  im = zeros(28, 28);

  % Read the row with the specified number from the training matrix.
  image_row = train_mat(number, :);

  % Reshape the read row into a 28x28 matrix and then transpose it.
  im = reshape(image_row, 28, 28)';

  % Convert the matrix to uint8 to make it a valid image.
  im = uint8(im);

  % Display the image.
  imshow(im);
endfunction
