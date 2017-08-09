%%% RETURNS cumulants = ARRAY OF CUMULANTS
%%%         z = ARRAY OF CUMULANTS / i! FOR CONTINUED FRACTIONS APPROXIMATION
function [Hcumulants] = calc_cumulant(X, k, n)
%function [D_vect z cumulants] = calc_cumulant(G, W, X, k, x0, n, t0, tf)
    
    %D_vect = zeros(k,1);                % vector of values of D (*1.32)
    [mm nn] = size(X);                  % mm = # rows of X (number of time values computed)
    %cumulants = zeros(k,1);             % vector of cumulants, ith space is ith cumulant
    %z = zeros(k, 1);                    % vector of ki/L!, where ki is the ith cumulant
    %mm = round(mmm/10);
    for i = 1:k
        
        %Htrace = zeros(mm,1);            % initialize Htrace vector
        %H = zeros(n);                   % initialize H matrix
        
        for j = 1:mm
            
            H = matrix_construct(k, n, X(j,:));
            %H = reshape(X(j,(i-1)*n^2+1:i*n*n),n,n);        % reshape H to n x n matrix
            %Htrace(j) = trace(H{i}*G*W*G');  % Htrace(j) = tr[H(j)GWG']
            if j == 1 && i == 1
               Hcumulants = H; 
            end
        end
        
    end
%         TIME = t0:(tf-t0)/(mm-1):tf;
%         %TIME = 0:1/(mm-1):1;
%         Hint = trapz(TIME, Htrace);           % integration approximation of (*1.32)
%         D_vect(i) = Hint;
%         
%         
%         cumulants(i) = x0'*Hcumulants{i}*x0 + D_vect(i);
%         z(i) = cumulants(i)/factorial(i);
%     end
end