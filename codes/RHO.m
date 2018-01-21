function y=RHO(Np, muP,lambdaP, Nc, muC, lambdaC , c_p, c_c)


t1=Np*c_p*lambdaP/(lambdaP+muP);
t2=Nc*(c_c*lambdaC)/(lambdaC+muC);
y=t1/t2;

