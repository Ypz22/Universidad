function [L, U, x] = descomposicionLU(A, b)
    % Verificar si la matriz es cuadrada
    [n, m] = size(A);
    if n ~= m
        error('La matriz A debe ser cuadrada.');
    end

    % Inicializar matrices L y U
    L = zeros(n);
    U = zeros(n);

    % Descomposición LU
    for i = 1:n
        % Verificar si el elemento diagonal es nulo
        if A(i, i) == 0
            error('Elemento nulo en la diagonal. No se puede continuar con la descomposición LU.');
        end

        for j = i:n
            U(i, j) = A(i, j) - sum(L(i, 1:i-1) .* U(1:i-1, j)');
        end

        for j = i:n
            if i == j
                L(i, i) = 1;
            else
                L(j, i) = (A(j, i) - sum(L(j, 1:i-1) .* U(1:i-1, i)')) / U(i, i);
            end
        end
    end

    % Sustitución progresiva para resolver Lc = b
    c = zeros(n, 1);
    for i = 1:n
        c(i) = b(i) - sum(L(i, 1:i-1) .* c(1:i-1)');
    end

    % Sustitución regresiva para resolver Ux = c
    x = zeros(n, 1);
    for i = n:-1:1
        x(i) = (c(i) - sum(U(i, i+1:n) .* x(i+1:n)')) / U(i, i);
    end
end