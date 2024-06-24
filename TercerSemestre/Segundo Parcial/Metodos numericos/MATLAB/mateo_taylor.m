%@authors: Mateo Garcia
func = input('Ingrese una función en términos de x: ', 's');%1) input data
f = str2func(['@(x) ' func]);

a = input('Ingrese el valor de a: '); %2) tomar el valor a

n = input('Ingrese el número de términos para la serie de Taylor: ');%3) tomar el numero de terminos

x_val = input('Ingrese el valor de x: '); %4) valor de x para evaluar

%funcion analitica
syms x
f_sym = str2func(['@(x) ' func]);
taylor_poly = taylor(f_sym(x), x, 'Order', n+1, 'ExpansionPoint', a);

taylor_approx = double(subs(taylor_poly, x, x_val));

% Evaluar la función original en x_val.
func_val = f(x_val);

error_absoluto = abs(func_val - taylor_approx); %valor absoluto
error_relativo = abs((func_val - taylor_approx) / func_val);%valor relativo

fprintf('Polinomio de Taylor: %s\n', char(taylor_poly));
fprintf('Valor teórico de la función en x = %f: %f\n', x_val, func_val);
fprintf('Valor aproximado con la serie de Taylor en x = %f: %f\n', x_val, taylor_approx);
fprintf('Error absoluto: %f\n', error_absoluto);
fprintf('Error relativo: %f\n', error_relativo);

%grafico
fplot(f_sym(x), [-10, 10], 'DisplayName', 'Función original');
hold on;
fplot(taylor_poly, [-10, 10], 'DisplayName', 'Polinomio de Taylor');
legend;
xlabel('x Funcion realizada por Mateo Garcia');
ylabel('y');
title('Comparación entre la función original y el polinomio de Taylor');
grid on;
hold off;