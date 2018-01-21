%function a=EB2(epsi, q,Np, muP,lambdaP, Nc, muC, lambdaC , c_p, c_c)

clc
clear

%One SU and One PUs
%Finding Eigenvector and Eigenvalues 



%this works!
%Individiual Buffer

x=0.1:.5:10;
Np=1; % # Producer (SUs)
Nc=1; % # Consumer (PUs)



%mu:      stands for producing/consuming
%lambda:  stands for NOT producing/consuming

% Average ON time= 1/mu
%Average OFF time= 1/lambda
%Consumer (PU)
Tp=01;

Pon=0.999;
muC=1/Pon;%[.59191 .79191 ];   % PU OFF period Parameter (Consuming)
lambdaC=1/(1-Pon);       % PU ON period parameter  (NOT Consuming) 

%Producer (SU)


muP=1;       % SU ON period parameter  (Producing)
lambdaP=1;   % SU OFF period Parameter (NOT Producing)


c_c =1.; % Each Consumer(primary)'s Channel capacity
c_p =.45;     % C0 is all the time available

epsi=0.001; % \epsilon-Outage probability

q=100;

rho=RHO(Np, muP,lambdaP, Nc, muC, lambdaC , c_p, c_c);

disp(['rho= ', num2str(rho)])


Qp=@(z)(c_p*z+lambdaP-muP)^2+4*muP*lambdaP;
Qc=@(z)(c_c*z-lambdaC+muC)^2+4*muC*lambdaC;


fc1=@(z,k1,k2)(k1-Np/2)*Qp(z)^0.5+(k2-Nc/2)*Qc(z)^0.5+Np/2*(c_p*z+muP+lambdaP)+Nc/2*(-c_c*z+muC+lambdaC);

fc2=@(z)-Nc*c_c*heaviside(z)*z;
fc3=@(z) Np*c_p*heaviside(-z)*z;




zmin=0;
zmax=2;
syms z
h=ezplot(z, fc1(z,0,0), [zmin zmax]);
hold on
h=ezplot(z, fc2(z), [zmin zmax]);
set(h, 'Color', 'g','LineStyle',':')
h=ezplot(z, fc3(z), [zmin zmax]);
set(h, 'Color', 'r','LineStyle',':')
hold off



grid on
axis square


[a f1 f2 F1 F2 M1 M2 S1 S2 P0 F0 rho zv V c z0 V0 c0 F1temp]=Coef3(Np, muP,lambdaP, Nc, muC, lambdaC , c_p, c_c);


a0=fzero(@(z)fc1(z,0,0), -z0);
%a0=fmincon(f1, -1, 1, -0.1);


r1=Nc*lambdaC/c_p-muC/(Nc*c_c-c_p);
r2=Nc*lambdaC/c_p-muC/(c_c-c_p);
r3=((muC+lambdaC)*c_p-Nc*lambdaC*c_c)/(Nc*c_c-c_p);

r4=Np*(Np*c_p*muP-c_c*(muP+lambdaP))/(c_c*(Np*c_p-c_c));
r5=Np*(Np*c_p*muP-c_c*(muP+lambdaP))/(c_p*(Np*c_p-c_c));

a=[a0 ];

theta=lambdaC/c_p-muC/(c_c-c_p);

disp(['a0= ', num2str(a0),', z0= ', num2str(z0),', r1= ', num2str(r1),...
    ', theta= ', num2str(theta), ', r2= ', num2str(r2),', r3= ',...
    num2str(r3),', r4= ', num2str(r4),', r5= ', num2str(r5)])
