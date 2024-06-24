%Problema 1

%a) Método de Newton-Raphson

f = @(x) 2*x^3 - 11.7*x^2 + 17.7*x - 5;
df = @(x) 6*x^2 - 23.4*x + 17.7;
x = 3;
tol = 0.001;
max_iter = 3;
for i = 1:max_iter
    x_nuevo = x - f(x)/df(x);
    if abs(x_nuevo - x) < tol
        break; 
    end
    x = x_nuevo; 
end
fprintf('Raíz encontrada con Newton-Raphson: %f\n', x);

%b) Método de la Secante
x0 = 3;
x1 = 4;
max_iter = 3; 
for i = 1:max_iter
    x2 = x1 - f(x1)*(x1 - x0)/(f(x1) - f(x0));
    x0 = x1; 
    x1 = x2;
end
fprintf('Raíz encontrada con el método de la Secante: %f\n', x2);

%Problema 2

%a) 

f = @(x) sin(x) + cos(1 + x^2) - 1;
x0 = 1.7;
x1 = 2.3;
max_iter = 4; 
for i = 1:max_iter
    x2 = x1 - f(x1)*(x1 - x0)/(f(x1) - f(x0));
    x0 = x1; 
    x1 = x2; 
end
fprintf('Raíz (a) encontrada con el método de la Secante: %f\n', x2);

%b) 
x0 = 1.5;
x1 = 2.5;
max_iter = 4; 
for i = 1:max_iter
    x2 = x1 - f(x1)*(x1 - x0)/(f(x1) - f(x0));
    x0 = x1; 
    x1 = x2;
end
fprintf('Raíz (b) encontrada con el método de la Secante: %f\n', x2);

%c) 
x0 = 1.5;
x1 = 2.5;
max_iter = 4; 
for i = 1:max_iter
    x2 = x1 - f(x1)*(x1 - x0)/(f(x1) - f(x0));
    x0 = x1;
    x1 = x2; 
end
fprintf('Raíz (b) encontrada con el método de la Secante: %f\n', x2);

%Problema 3

f = @(x) -12 - 21*x + 18*x^2 - 2.4*x^3;
x0 = -10;
x1 = -8;  
tol = 1e-5;
max_iter = 100; 
for i = 1:max_iter
    x2 = x1 - f(x1)*(x1 - x0)/(f(x1) - f(x0));
    if abs(x2 - x1) < tol
        break; 
    end
    x0 = x1; 
    x1 = x2; 
end
fprintf('Raíz más pequeña encontrada con el método de la Secante: %f\n', x2);

%Problema 4

%a) Usando el método gráfico
f = @(x) log(x^2 - 2) + 1/exp(-x + 2);
x = linspace(2, 5, 1000);
y = arrayfun(f, x);
plot(x, y);
grid on;
xlabel('x');
ylabel('f(x)');
title('Método gráfico para encontrar la raíz negativa');

%b) Usando el método de Newton-Raphson
f = @(x) log(x^2 - 2) + 1/exp(-x + 2);
df = @(x) (2*x)/(x^2 - 2) - exp(-x + 2);
x = -1;
tol = 0.5;
max_iter = 100; 
for i = 1:max_iter
    x_nuevo = x - f(x)/df(x);
    if abs(x_nuevo - x) < tol
        break;
    end
    x = x_nuevo; 
end
fprintf('Raíz negativa encontrada con Newton-Raphson: %f\n', x);
