function [Klqg,eigenlqg] = LQGController(A,B,C,D)
nx = length(A);
[mx my] = size(B);
Q = 1*eye(nx);
R = 1*eye(my);
Rinv = inv(R);
% solve the algebraic Riccati equation
P = care(A,B,Q,R);
%calculate gain matrix
Klqg = Rinv*B'*P;
%eigenvalue of closed loop
eigenlqg = eig(A-B*Klqg);
end


