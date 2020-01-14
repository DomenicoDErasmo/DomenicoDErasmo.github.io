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
max_runs = size(number_of_points,2);

% Runs the program with different numbers of points
% Constructs a number scheme for -ku" = q by solving kTu = q
for loop_of_program = 1:max_runs

    % Initializing x variable
    num_x = number_of_points(loop_of_program);
    del_x = max_x/num_x;
    x = del_x:del_x:max_x-del_x;
    
    k_vector = zeros(size(x));
    
    % Initialize all k values
    for x_pos = 1:num_x-1
       
        k_vector(x_pos)= k(x(x_pos),k_l);
        
    end
    
    % Setting T up, T = S/(del_x)^2
    S = sparse(num_x-1, num_x-1);
    m = size(S,1);
    S(1:m+1:end) = 2;
    S(2:m+1:end) = -1;
    S(m+1:m+1:end) = -1;

    T = S/(del_x)^2;
    T_inv = T\eye(size(T,1));
 
    q_exact = zeros(size(x.'));
    
    % Initializing q for all x
    for x_pos = 1:num_x-1
        
        q_exact(x_pos) = q_4(x(x_pos));
        
    end

    % Initializing u and a corresponding exact values array
    u = zeros(1,num_x-1);
    u_final = zeros(size(u,2)+2,1);
    temp_exact_values = zeros(size(u,1),1);
    
    % Initializing for all u values, couldn't do without a for loop sadly
    for u_x_pos = 1:num_x-1
        
        q_test = q_exact/k_vector(u_x_pos);
        T_column = T_inv(u_x_pos,:);
        u(u_x_pos) = T_column*q_test;
        temp_exact_values(u_x_pos) = u_exact(x(x_pos),k_vector(u_x_pos));
        
    end
    
    % Expanding previous arrays to accomodate for boundary conditions
    u_final(2:end-1) = u;

    x_final = zeros(size(x,2)+2,1);
    x_final(2:end-1) = x;
    x_final(end) = 10;
    
    k_final = ones(size(k_vector,2)+2,1);
    k_final(2:end-1) = k_vector;
    
    % My exact values seem to be off but I'm not sure where the computation
    % error lies.
    exact_values = zeros(size(u,2)+2,1);
    exact_values(2:end-1) = temp_exact_values;
    
    % Plotting
    plot (x_final,u_final,x_final,exact_values)
    legend("Experimental u", "Exact u")

    pause()
    
end

