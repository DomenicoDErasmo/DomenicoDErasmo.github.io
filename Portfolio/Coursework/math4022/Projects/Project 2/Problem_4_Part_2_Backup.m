%{

Section 4.5 #2

Consider the same boundary value problem as above, but with a piecewise
constant diffusion function k = k(x). For example, take k(x) = k_l for
0 <= x < 5 and k(x) = 1 for 5 <= x <= 10, and make k_l an input parameter.
The linear system to solve will use the jump conditions in Section 3.1.

%}

k_l = input("Enter a value for k_l: ");

% Used for any num_x value
max_x = 10;
number_of_points = [5 10 20 40 80];
%errors = zeros(size(number_of_points.'));
max_runs = size(number_of_points,2);
%eigs_of_T = errors;

for loop_of_program = 1:max_runs

    num_x = number_of_points(loop_of_program);
    del_x = max_x/num_x;
    x = del_x:del_x:max_x-del_x;
    k_vector = zeros(size(x,1));
    
    for k_x_pos = 1:num_x-1
       
        k_vector(k_x_pos)= k(x(k_x_pos),k_l);
        
    end
    
    S = sparse(num_x-1, num_x-1);
    m = size(S,1);
    S(1:m+1:end) = 2;
    S(2:m+1:end) = -1;
    S(m+1:m+1:end) = -1;

    T = S/(del_x)^2;
    T_inv = T\eye(size(T,1));
 
    q_exact = zeros(size(x.'));
    
    for x_pos = 1:num_x-1
        
        q_exact(x_pos) = q_4(x(x_pos));
        
    end

    u = zeros(size(T,1));
    q_test = q_exact*(1./k_vector);
    u = T_inv*q_exact/k_vector(:);

    u_final = zeros(size(u,1)+2,1);
    u_final(2:end-1) = u;

    x_final = zeros(size(x,2)+2,1);
    x_final(2:end-1) = x;
    x_final(end) = 10;

    exact_values = u_exact(x_final,k);
    max_error = max(abs(u_final - exact_values));
    errors(loop_of_program) = max_error;
    
    plot (x_final,u_final,x_final,exact_values)
    legend("Experimental u", "Exact u")

    pause()
    
end

%{
 disp("The max error halves and the eigenvalues of T span 4 times the range of numbers when del_x is halved.")
 plot(number_of_points, errors)
 legend("Max error")
 title ("Max Error vs del_x")
 pause()
%}