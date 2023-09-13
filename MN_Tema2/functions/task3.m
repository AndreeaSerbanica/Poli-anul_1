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
## @deftypefn {} {@var{retval} =} pca_cov (@var{input1}, @var{input2})
##
## @seealso{}
## @end deftypefn

## Author: Andrei <Andrei@DESKTOP-PK505U9>
## Created: 2021-09-06

function new_X = task3 (photo, pcs)
  [m, n] = size (photo);

  % initializare matrice finala.
  new_X = zeros (m, n);

  % TODO: transforma matricea in uint8 pentru a fi o imagine valida.
   [m, n] = size(photo);

  % Initializare matrice finala.
  new_X = zeros(m, n);

  % Cast photo la double.
  photo = double(photo);

  % Calculeaza media fiecarui rand al matricii.
  mu = mean(photo, 2);

  % Normalizeaza matricea initiala scazand din ea media fiecarui rand.
  photo = photo - mu;

  % Calculeaza matricea de covarianta.
  cov_matrix = (photo * photo') / (n - 1);

  % Calculeaza vectorii si valorile proprii ale matricei de covarianta.
  [V, D] = eig(cov_matrix);

  % Ordoneaza descrescator valorile proprii si creeaza matricea V
  % formata din vectorii proprii asezati pe coloane.
  [~, indices] = sort(diag(D), 'descend');
  V = V(:, indices);

  % Pastreaza doar primele pcs coloane din V.
  W = V(:, 1:pcs);

  % Creeaza matricea Y schimband baza matricii initiale.
  Y = W' * photo;

  % Calculeaza matricea new_X care este o aproximatie a matricii initiale.
  new_X = W * Y;

  % Aduna media randurilor scazuta anterior.
  new_X = new_X + mu;

  % Transforma matricea in uint8 pentru a fi o imagine valida.
  new_X = uint8(new_X);
endfunction
