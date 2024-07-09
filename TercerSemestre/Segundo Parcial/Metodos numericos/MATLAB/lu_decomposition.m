function [L, U] = lu_decomposition(A)
    n = size(A, 1);
    L = eye(n);
    U = zeros(n);
    for j = 1:n
        for i = 1:j
            U(i,j) = A(i,j) - L(i,1:i-1) * U(1:i-1,j);
        end
        for i = j+1:n
            L(i,j) = (A(i,j) - L(i,1:j-1) * U(1:j-1,j)) / U(j,j);
        end
    end
end

function x = solve_lu(L, U, b)
    % Sustitución progresiva para resolver Lc = b
    n = length(b);
    c = zeros(n, 1);
    for i = 1:n
        c(i) = b(i) - L(i, 1:i-1) * c(1:i-1);
    end
    % Sustitución regresiva para resolver Ux = c
    x = zeros(n, 1);
    for i = n:-1:1
        x(i) = (c(i) - U(i, i+1:n) * x(i+1:n)) / U(i, i);
    end
end
