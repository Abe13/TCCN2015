%function a=EB2(epsi, q,Np, muP,lambdaP, Nc, muC, lambdaC , c_p, c_c)

clc
clear

%One SU and One PUs
%Finding Eigenvector and Eigenvalues 



%this works!
%Individiual Buffer

x=0.1:.5:10;
Np=2; % # Producer (SUs)
Nc=1; % # Consumer (PUs)



%mu:      stands for producing/consuming
%lambda:  stands for NOT producing/consuming

% Average ON time= 1/mu
%Average OFF time= 1/lambda
%Consumer (PU)
Tp=01;

muC=0.2/Tp;%[.59191 .79191 ];   % PU OFF period Parameter (Consuming)
lambdaC=0.1/Tp;       % PU ON period parameter  (NOT Consuming) 

%Producer (SU)

Pon=0.7;
muP=1/Pon/Tp;       % SU ON period parameter  (Producing)
lambdaP=1/(1-Pon)/Tp;   % SU OFF period Parameter (NOT Producing)


c_c =3; % Each Consumer(primary)'s Channel capacity
c_p =.45;     % C0 is all the time available

epsi=0.001; % \epsilon-Outage probability

q=100;




Q1=@(z)(c_p*z+lambdaP-muP)^2+4*muP*lambdaP;
Q2=@(z)(c_c*z-lambdaC+muC)^2+4*muC*lambdaC;


fc1=@(z,k1,k2)(k1-Np/2)*Q1(z)^0.5+(k2-Nc/2)*Q2(z)^0.5+Np/2*(c_p*z+muP+lambdaP)+Nc/2*(-c_c*z+muC+lambdaC);

fc2=@(z)-Nc*c_c*heaviside(z)*z;
fc3=@(z) Np*c_p*heaviside(-z)*z;

zmin=-2;
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


a0=fzero(@(z)fc1(z,0,0), -1)
%a0=fmincon(f1, -1, 1, -0.1);

[a f1 f2 F1 F2 M1 M2 S1 S2 P0 F0 rho zv V c z0 V0 c0 F1temp]=Coef3(Np, muP,lambdaP, Nc, muC, lambdaC , c_p, c_c);
z0



a=[a0 ];