function a=EB1(epsi, q, muC, lambdaC ,  c_c)

epsi1=epsi*(1+lambdaC/muC);

%f1=@(a)log(epsi)*a.^2-(q*lambdaC+q*muC+log(epsi))*a+q*lambdaC*c_c;
%a1=fzero(f1, c_c/2);
%a1=max(roots([log(epsi) -(q*lambdaC+q*muC+log(epsi)) q*lambdaC*c_c]));


f2=@(c_p)-q*lambdaC*c_c+q.*lambdaC.*c_p+q.*muC.*c_p-log(epsi1)*c_c*c_p+log(epsi1)*c_p.^2 ...
+log(1-c_p/c_c).*c_p.*(c_c-c_p);

a2=fzero(f2, c_c/2);

%f2=@(c_p)muC/(muC+lambdaC)*c_c/(c_c-c_p)*exp(-(lambdaC/c_p-muC/(c_c-c_p))*q)-epsi;

%a2=fzero(f2, c_c/2);



a3=lambdaC*c_c*q/(muC*q-c_c*log(epsi1));
%a4=lambdaC*c_c*q/(muC*q-c_c*log(epsi));
if a3>c_c*lambdaC/(muC+lambdaC)
    a3=c_c*lambdaC/(muC+lambdaC);
end

a=[a2 a3 ];