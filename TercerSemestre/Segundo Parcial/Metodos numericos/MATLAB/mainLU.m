% Prueba del programa con un sistema de 10x10
A = rand(10, 10);
b = rand(10, 1);
disp("A:");
disp(A);
disp("B: ");
disp(b);
[L, U, x] = descomposicionLU(A, b);
disp('Solución x:');
disp(x);

