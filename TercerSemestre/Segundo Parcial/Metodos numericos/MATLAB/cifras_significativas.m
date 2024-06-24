function [sf] = cifras_significativas(x)
    x_str = num2str(x);
    dot_idx = strfind(x_str, '.'); 
    if isempty(dot_idx)
        dot_idx = length(x_str) + 1;
    end
    sf = sum(x_str ~= '0' & x_str ~= '.' & x_str ~= '-');
    if x < 0
        sf = sf - 1;
    end
end