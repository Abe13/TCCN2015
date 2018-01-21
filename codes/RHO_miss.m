function rho=RHO_miss(Np, muP,lambdaP, Nc, muC, lambdaC , c_p, c_c, Pmiss)


Pdet=Pmiss/(Nc)*(ones(Nc+1)-eye(Nc+1))+(1-Pmiss)*eye(Nc+1);

In0=(0:Np);
W1=1/(lambdaP+muP)^Np .*factorial(Np)./factorial(Np-In0)./factorial(In0)...
     .*lambdaP.^In0.*muP.^(Np-In0);
In0=(0:Nc);
W2=1/(lambdaC+muC)^Nc .*factorial(Nc)./factorial(Nc-In0)./factorial(In0)...
     .*lambdaC.^In0.*muC.^(Nc-In0);
 

Din=0;
for i=0:Np
    Din=Din+c_p *i * W1(i+1);
end


Dout=0;

for j=0:Nc
    for k=0:Nc
        Dout=Dout+c_c*min(j, k) *W2(j+1)*Pdet(j+1, k+1);
    end
end

rho=Din/Dout;
