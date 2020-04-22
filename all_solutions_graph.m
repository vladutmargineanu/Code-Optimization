%To view plots after 'plot' (and other plot-producing commands) this command must follow: 'print -dpng some_unique_plot_name.png;'
%It exports current plot to png image which then is sent to your browser
%GNU Octave 4.0.0

x=[400, 600, 800, 1000, 1200]
y_blas = [0.029415, 0.090737, 0.206641, 0.392481, 0.666339]
y_neopt = [0.922059, 2.968118, 7.064523, 13.203243, 22.888781]
y_opt_m = [0.464267, 1.514952, 3.369658, 5.986207, 10.443977]
y_opt_f = [0.217916, 1.043596, 1.461430, 2.606664, 4.480869]
y_opt_f_extra = [0.188519, 0.516920, 1.224562, 2.320713, 4.087400]

plot(x, y_blas, 'c', x, y_neopt, 'g', x, y_opt_m, 'r', x, y_opt_f, 'b', x, y_opt_f_extra, 'm');
xlabel('Size')
ylabel('Time')
title ("ALL SOLUTIONS");
legend("BLAS SOLVER","NEOPT SOLVER", "OPT M SOLVER", "OPT F SOLVER", "OPT F EXTRA SOLVER");

print -dpng some_name.png;

