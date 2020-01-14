function u = u_exact(x,k)

% Answer when q(x) = sin(pi*x/10)
u = (10/pi).^2.*sin(pi*x/10)/k;

% Answer when q(x) = 1
% u = 0.5.*x.*(10.-x)./k;

end