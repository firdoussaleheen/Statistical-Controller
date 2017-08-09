function [eigen,Co, unco,Ob,unob]= chksys(A,B,C) 
%Eigenvalues of the system
disp('Eigenvalues are')
eigen = eig(A);
disp(eigen)

%Controllability Matrix
Co=ctrb(A,B);
% Number of uncontrollable states
disp('Number of uncontrollable states')
unco=length(A)-rank(Co);
disp(unco)
% Observability Matrix
Ob = obsv(A,C);
% Number of unobservable states
disp('Number of unobservable states')
unob = length(A)-rank(Ob);
disp(unob)
end