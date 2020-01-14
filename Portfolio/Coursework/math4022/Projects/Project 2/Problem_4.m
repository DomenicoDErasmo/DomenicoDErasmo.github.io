%{

Section 4.5 #1

Consider the boundary value problem for steady-state heat flow on the
interval [0,10] with a source q(x):

-ku"(x)=q(x), u(0) = u(10) = 0.

The goal is to write a MATLAB program to solve this problem numerically for
given data q. Make mesh poiints xj = j*del(x, j = 1, ... ,J where del_x =
10/J. Then write a finite difference scheme by replacing the second
derivative by a centered difference.

-k*((u(x(j) + del(x)) - 2*u(x(j)) + u*(x(j) - del_x)/(del_x)^2) ~= q(x(j)),

j = 1, ... ,J-1. Taking into account the boundary conditions, we arrive at
the (J-1) x (J-1) system

    kTu = q.

where u = [u_1, ... , u_(J-1)] is the vector of unknowns, q = [q(x(1), ...,
q(x(J-1))] and T = (del_x)^-2S where S is the sparse matrix

    S =  2 -1  0  0  0
        -1  2 -1  0  0
         0 -1  2 -1  0
         .  .  .  .  .
         .  .  .  .  .
         0  0  0 -1  2

You will need to write a function mfile q.m for q. Then use the sparse
matrix operations of MATLAB to enter the matrix S. For information enter
help sparse.

To see if your program works correctly, try q(x) = 1. The exact solution of
the BVP is u(x) = 0.5*x*(10-x)/k. The centered difference formula for u" is
exact on quadratic polynomials. Thus the vector of values u should agree
exactly with the values of u at the grid points. Try J = 5 to begin. When
you have gotten your program working correctly, try several different
choices of q with J = 100. Plot q and the solution together on the interval
[0, 10]. The vector of values u, which you get from solving (4.54), does
not include the zero values at the end points x = 0 and x = 10. You must
add these values to make a vector of (J + 1) components for plotting.

Next determine the reate of convergence of the computed solution values to
the values of an exact solution. Take q(x) = sin(pi*x/10). q is the first
eigenfunction phi_1(x) of this BVP. Hence the exact solution of -ku" = q =
phi_1 is given by

    u(x) = (1/k*lambda_1) * phi_1(x) = (1/k)*(10/pi)^2*sin(pi*x/10).

Now take the number of intervals to be J = 5, 10, 20, 40, 80. For each
value of J, find the maximum error between the calculated values and the
values of the exact solution at the grid points. What happens to this error
when J is doubled (that is, del_x is halved)?

The matrix operator T is an approximation to the differential operator Mu =
-u" with the boundary conditions u(0) = u(10) = 0. You can find the
eigenvalues of the matrix T with the single MATLAB command eig(T). Put them
in order of increasing size and compare with the eigenvalues of M. What do
you see happening as J gets larger?

%}

% Used for any num_x value
max_x = 10;
k = 1;
number_of_points = [5 10 20 40 80];
errors = zeros(size(number_of_points.'));
max_runs = size(number_of_points,2);
eigs_of_T = errors;

% Used a for loop instead of pasting code to make it cleaner
for loop_of_program = 1:max_runs

    % Initializing x variable
    num_x = number_of_points(loop_of_program);
    del_x = max_x/num_x;
    x = del_x:del_x:max_x-del_x;

    % Initializing S and T matrices
    S = sparse(num_x-1, num_x-1);
    m = size(S,1);
    S(1:m+1:end) = 2;
    S(2:m+1:end) = -1;
    S(m+1:m+1:end) = -1;
    T = S/(del_x)^2;
    T_inv = T\eye(size(T,1));

    % Showing eigenvalues
    current_eigs_of_T = eig(T)
    
    % Initializing the q solution
    q_exact = zeros(size(x.'));
    for x_pos = 1:num_x-1
        
        q_exact(x_pos) = q_4(x(x_pos));
        
    end

    % Initializing and solving u
    u = zeros(size(T,1));
    u = T_inv*(1/k)*q_exact;

    % Appending the boundary conditions for u and x to get a 
    % J+1 x J+1 matrix
    u_final = zeros(size(u,1)+2,1);
    u_final(2:end-1) = u;

    x_final = zeros(size(x,2)+2,1);
    x_final(2:end-1) = x;
    x_final(end) = 10;

    % Calculates error
    exact_values = u_exact(x_final,k);
    max_error = max(abs(u_final - exact_values));
    errors(loop_of_program) = max_error;
    
    % Plots numerical solution for u and actual solution for u
    plot (x_final,u_final,x_final,exact_values)
    legend("Experimental u", "Exact u")

    pause()
    
end

% Plots error over number of x and describes relation of eigenvalues and
% error to the number of x
disp("The max error halves and the eigenvalues of T span 4 times the range of numbers when del_x is halved.")
plot(number_of_points, errors)
legend("Max error")
title ("Max Error vs del_x")
pause()