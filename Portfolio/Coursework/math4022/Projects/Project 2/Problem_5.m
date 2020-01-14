%{

Generate a "movie" of the solution to the problem utt = uxx with u(x,0) = 0
and ut(x,0) = g(x) for -inf<x<inf and 0<t where 

g(x) = {1, |x| < 1
       {0, otherwise

%}

c = 1;

% Intializing x variable
end_x = 20;
del_x = 0.2;
num_x = end_x/del_x;
x = linspace(-end_x, end_x, num_x*2+1);

% Initializing t variable
end_t = 2 * end_x;
del_t = 0.2;
num_t = end_t/del_t;
t = linspace(del_t, end_t, num_t+1);

% Initializes the g function over a vector
g_curve = ones(size(x));
for x_pos = 1:size(x.')
    
    g_curve(x_pos) = g(x(x_pos));
    
end

% Sets up u to be filled later
u = zeros(size(x,2), size(t,2));
for t_step = 1:size(t.')/2
    
    % Sets up each time of u
    u(:,t_step) = zeros(size(x));
    
    % Fills each x in for every t 
    % I hate using nested for loops but I couldn't think of another way to
    % handle g(x)
    for x_step = 1:size(x.')
        
        % Sets up upper and lower bounds
        upper_bound = x(x_step)+c*t(t_step);
        lower_bound = x(x_step)-c*t(t_step);
        
        % Sets up integration domain
        num_integration_x = int32((upper_bound - lower_bound)*5 + 1);
        integration_domain = linspace(lower_bound, upper_bound, num_integration_x);
        number_of_points_to_integrate = size(integration_domain,2);
        
        % Specifies where to integrate within g
        g_curve = ones(size(integration_domain.'));
        
        %
        for integration_pos = 1:number_of_points_to_integrate
    
            g_curve(integration_pos) = g(integration_domain(integration_pos));
    
        end
        
        % Solution of u(x,t)
        % Because u(x,0) = 0, f(x) = 0, meaning we can ignore it
        u(x_step,t_step) = trapz(integration_domain, g_curve)/(2*c);
         
    end
    
    % Plots the current time slice of u(x,t)
    plot(x,u(:,t_step))
    axis ([-end_x end_x -1 2])
    pause(0.1)
    
end
