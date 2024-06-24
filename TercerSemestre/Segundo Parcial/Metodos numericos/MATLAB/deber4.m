funcion_str = input('Ingrese una función en términos de x: ', 's');
f = str2func(['@(x) ' funcion_str]);

a = input('Ingrese el valor de a para la serie de Taylor: ');

n = input('Ingrese el número de términos de la serie de Taylor: ');

valor_x = input('Ingrese el valor de x para evaluar las funciones: ');

syms x;
polinomio_taylor = 0;
for k = 0:n-1
    derivada = diff(f(x), x, k);
    termino = subs(derivada, x, a) / factorial(k) * (x - a)^k;
    polinomio_taylor = polinomio_taylor + termino;
end

polinomio_taylor_func = matlabFunction(polinomio_taylor);

valor_funcion = f(valor_x);
valor_taylor = polinomio_taylor_func(valor_x);

disp('El polinomio de Taylor es: ');
disp(polinomio_taylor);

error_absoluto = abs(valor_funcion - valor_taylor);
error_relativo = error_absoluto / abs(valor_funcion);
disp('Error absoluto: ');
disp(error_absoluto)
disp('Error relativo: ');
disp(error_relativo)

fplot(f, [a-10, a+10], 'LineWidth', 1.5); hold on;
fplot(polinomio_taylor_func, [a-10, a+10], '--', 'LineWidth', 1.5);
legend('Función original', 'Polinomio de Taylor');
xlabel('x Funcion realizada por Jefferson Yépez');
ylabel('y');
title('Comparación entre la función original y el polinomio de Taylor');
grid on;
hold off;
