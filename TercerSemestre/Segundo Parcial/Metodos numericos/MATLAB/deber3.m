x_real = 3.141592;
X_aproximado = 3.14;
error_absoluto_x =  abs(x_real - X_aproximado);
error_relativo_x = abs(error_absoluto_x/x_real);
disp("Error absoluto x: ")
disp(error_absoluto_x)
disp("Error relativo x: ")
disp(error_relativo_x)

y_real = 1000000;
y_aproximado = 999996;
error_absoluto_y =  abs(y_real - y_aproximado);
error_relativo_y = abs(error_absoluto_y/y_real);
disp("Error absoluto y: ")
disp(error_absoluto_y)
disp("Error relativo y: ")
disp(error_relativo_y)

z_real = 0.000012;
z_aproximado = 0.000009;
error_absoluto_z =  abs(z_real - z_aproximado);
error_relativo_z = abs(error_absoluto_z/z_real);
disp("Error real z: ")
disp(error_absoluto_z)
disp("Error absoluto z: ")
disp(error_relativo_z)

cifras_sig_x_real = numel(num2str(x_real)) - 2; % excluyendo "0."
cifras_sig_x_aprox = numel(num2str(X_aproximado)) - 1; % excluyendo "0."
disp("Numero de cifras significativas para x real: ");
disp(cifras_sig_x_real)
disp("Numero de cifras significativas para x aproximado: ");
disp(cifras_sig_x_aprox)

cifras_sig_y_real = numel(num2str(y_real));
cifras_sig_y_aprox = numel(num2str(y_aproximado));
disp("Numero de cifras significativas para y real: ");
disp(cifras_sig_y_real)
disp("Numero de cifras significativas para y aproximado: ");
disp(cifras_sig_y_aprox)

cifras_sig_z_real = numel(num2str(z_real)) - 2; % excluyendo "0."
cifras_sig_z_aprox = numel(num2str(z_aproximado)) - 2; % excluyendo "0."
disp("Numero de cifras significativas para z real: ");
disp(z_real)
disp("Numero de cifras significativas para z aproximado: ");
disp(z_aproximado)

x = 10^-10;

y = sqrt(x^2+1)-1;

disp("Valor de la funcion:")
disp(y)

funcion = @(x) exp(x.^2);
I_aprox = integral(funcion,0,0.5);
I_real = 0.544987104184;

error_absoluto = abs(I_real - I_aprox);
error_relativo = abs(error_absoluto/I_real);

cifras_significativas = floor(-log10(error_absoluto)) + 1;

disp("Valor aproximado de la funcion:")
disp(I_aprox)
disp("Valor exacto de la integral: ")
disp(I_real)
disp("Error absoluto:")
disp(error_absoluto)
disp("Error relativo:")
disp(error_relativo)
disp("Numero de cifras significativas:")
disp(cifras_significativas)

syms h;

serie_taylor_exp = taylor(exp(h), 'Order', 5);
serie_taylor_cos = taylor(cos(h), 'Order', 7);

disp('Serie de Taylor para e^h:');
disp(serie_taylor_exp);
disp('Serie de Taylor para cos(h):');
disp(serie_taylor_cos);

suma_combinada = serie_taylor_exp + serie_taylor_cos;
disp('Serie de Taylor para e^h + cos(h):');
disp(suma_combinada);

producto_combinado = taylor(exp(h)*cos(h), 'Order', 7);
disp('Serie de Taylor para e^h * cos(h):');
disp(producto_combinado);

orden_suma = feval(symengine, 'degree', suma_combinada, h);
orden_producto = feval(symengine, 'degree', producto_combinado, h);

fprintf('Orden de aproximación para e^h + cos(h): O(h^%d)\n', orden_suma + 1);
fprintf('Orden de aproximación para e^h * cos(h): O(h^%d)\n', orden_producto + 1);
