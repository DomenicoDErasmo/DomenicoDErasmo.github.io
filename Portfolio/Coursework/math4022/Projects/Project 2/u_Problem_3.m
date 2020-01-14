function w = u_Problem_3(x,t,L)

w = (5*L/2)*sin((2*pi/L).*x)*exp(-(2*pi/L)^2*t) - (L)*sin((3*pi/L).*x)*exp(-(3*pi/L)^2*t) + (3*L/2)*sin((5*pi/L).*x)*exp(-(5*pi/L)^2*t);

end