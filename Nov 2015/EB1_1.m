function a=EB1_1(epsi, q, muC, lambdaC ,  c_c, p00,p11 )

options = optimset('TolFun',epsi*1e-2);
epsi1=epsi*(1+lambdaC/muC);

%f1=@(a)log(epsi)*a.^2-(q*lambdaC+q*muC+log(epsi))*a+q*lambdaC*c_c;
%a1=fzero(f1, c_c/2);
%a1=max(roots([log(epsi) -(q*lambdaC+q*muC+log(epsi)) q*lambdaC*c_c]));


f2=@(c_p)q*(lambdaC/c_p-muC/(c_c-c_p))+log(epsi1)+log(1-c_p/c_c); % Exact value
a2=fzero(f2, c_c/2,options);


%f2=@(c_p)-q*lambdaC*c_c+q.*lambdaC.*c_p+q.*muC.*c_p-log(epsi1)*c_c*c_p+log(epsi1)*c_p.^2 ...
%+log(1-c_p/c_c).*c_p.*(c_c-c_p); % Exact value
%a2=fzero(f2, c_c/2,options);

f3=@(c_p)muC/(muC+lambdaC)*c_c/(c_c-c_p)*exp(-(lambdaC/c_p-muC/(c_c-c_p))*q)-epsi; % Exact value
a3=fzero(f3, c_c/2,options); 


%a4=lambdaC*c_c*q/(muC*q-c_c*log(epsi));
a4=lambdaC*c_c/(muC+lambdaC); % Upper bound

%a6=lambdaC*c_c*q/(muC*q-c_c*log(epsi1)); % Approximation

f7=@(c_p)muC/(muC+lambdaC)*exp(-(lambdaC/c_p-muC/(c_c-c_p))*q)-epsi; % Approximate
a7=fzero(f7, c_c/2,options); 

f8=@(c_p)muC/c_p -lambdaC/(c_c -c_p) +log(epsi)/q; %Approximation
a8=fzero(f8, c_c/2,options); 

%-----------------------------------
%From paper [4]

phi1=@(theta)p00+p11*exp(c_c*theta); 
phi2=@(theta)(p00+p11-1)*exp(c_c*theta);
psi_c=@(theta)log((phi1(theta)+sqrt(phi1(theta).^2-4*phi2(theta)))/2);

a=@(epsi,b)b.*psi_c(log(epsi)./b)./log(epsi);

a9=a(epsi,q);

a=[a2 a4 a9];