function comparar_tiempos()
    tamanos = [3, 10, 30, 100, 200];
    tiempos_gauss = zeros(length(tamanos), 1);
    tiempos_lu = zeros(length(tamanos), 1);
    tiempos_inversa = zeros(length(tamanos), 1);

    for i = 1:length(tamanos)
        n = tamanos(i);
        A = rand(n, n);
        b = rand(n, 1);
        
        tic;
        gauss(A, b);
        tiempos_gauss(i) = toc;
        
        tic;
        [L, U] = lu_decomposition(A);
        solve_lu(L, U, b);
        tiempos_lu(i) = toc;
        
        tic;
        inversa(A, b);
        tiempos_inversa(i) = toc;
    end
    
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
