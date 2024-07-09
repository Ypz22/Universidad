function X = gaussJordan(A, B, n)
    Aug = [A B];
    
    for i = 1:n
        Aug(i,:) = Aug(i,:) / Aug(i,i);

        for j = 1:n
            if j ~= i
                Aug(j,:) = Aug(j,:) - Aug(j,i) * Aug(i,:);
            end
        end
    end

    X = Aug(:, end);
end