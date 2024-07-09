function mainTiempos()
    comparar_tiempos();
end

function comparar_tiempos()
    tamanos = [3, 10, 30, 100, 200];
    tiempos_gauss = zeros(length(tamanos), 1);
    tiempos_lu = zeros(length(tamanos), 1);
    tiempos_inversa = zeros(length(tamanos), 1);

    for i = 1:length(tamanos)
        n = tamanos(i);
        A = rand(n, n);
        b = rand(n, 1);
        
        % Tiempo para método de Gauss
        tic;
        gauss(A, b);
        tiempos_gauss(i) = toc;
        
        % Tiempo para método de descomposición LU
        tic;
        [L, U] = lu_decomposition(A);
        solve_lu(L, U, b);
        tiempos_lu(i) = toc;
        
        % Tiempo para método de la inversa
        tic;
        inversa(A, b);
        tiempos_inversa(i) = toc;
    end
    
    % Graficar los resultados
    figure;
    plot(tamanos, tiempos_gauss, '-o', 'DisplayName', 'Método de Gauss');
    hold on;
    plot(tamanos, tiempos_lu, '-x', 'DisplayName', 'Método de descomposición LU');
    plot(tamanos, tiempos_inversa, '-s', 'DisplayName', 'Método de la inversa');
    xlabel('Número de variables');
    ylabel('Tiempo (s)');
    title('Eficiencia de los métodos');
    legend show;
    hold off;
end

function x = gauss(A, b)
    n = length(b);
    % Eliminación Gaussiana
    for k = 1:n-1
        for i = k+1:n
            factor = A(i,k) / A(k,k);
            A(i,k:n) = A(i,k:n) - factor * A(k,k:n);
            b(i) = b(i) - factor * b(k);
        end
    end
    % Sustitución regresiva
    x = zeros(n, 1);
    x(n) = b(n) / A(n,n);
    for i = n-1:-1:1
        x(i) = (b(i) - A(i,i+1:n) * x(i+1:n)) / A(i,i);
    end
end

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

function x = inversa(A, b)
    x = inv(A) * b;
end
