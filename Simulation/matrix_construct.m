function [Hmat] = matrix_construct(k, n, X)
    row = X;
    Hmat = cell(1,k);

    for i=1:k
        Hmat{1,i} = zeros(n); 
    end
    j=1;
    for i = 1:k*n

        if mod(i,k) == 0
            H = Hmat{1,k};
            if mod(i,n) == 0
                H(j,:) = row((i-1)*n+1:i*n);
            else 
                H(j,:) = row((i-1)*n+1:i*n);
            end
            Hmat{1,k} = H;
        else
            H = Hmat{1,mod(i,k)};
            if mod(i,n) == 0
                H(j,:) = row((i-1)*n+1:i*n);
            else 
                H(j,:) = row((i-1)*n+1:i*n);
            end
            Hmat{1,mod(i,k)} = H;
        end
        
        if mod(i,k)==0
            j = j+1;
        end
    
    end

end