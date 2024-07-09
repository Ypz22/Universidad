%Autor: Jefferson Yépez
% Solicitar al usuario que ingrese la matriz de coeficientes A
n = input('Ingrese el número de ecuaciones (y variables): ');
A = zeros(n, n);
disp('Ingrese la matriz de coeficientes A:');
for i = 1:n
    for j = 1:n
       A(i, j) = input(sprintf('A(%d,%d): ', i, j));
     end
end
    
% Solicitar al usuario que ingrese la matriz de resultados B
B = zeros(n, 1);
disp('Ingrese la matriz de resultados B:');
for i = 1:n
    B(i) = input(sprintf('B(%d): ', i));
end

X = gaussJordan(A, B, n);
disp('La solución es:');
disp(X);