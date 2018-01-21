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
%Ppon=0.1; % The probability that PU is On

muC=@(Ppon)0.2./(1-Ppon);%[.59191 .79191 ];   % PU OFF period Parameter (Consuming)
lambdaC=@(Ppon)0.3./Ppon;       % PU ON period parameter  (NOT Consuming) 

%Producer (SU)

Pson=0.99999;
muP=1/Pson;       % SU ON period parameter  (Producing)
lambdaP=1/(1-Pson);   % SU OFF period Parameter (NOT Producing)


c_c =1.; % Each Consumer(primary)'s Channel capacity
c_p =.45;     % C0 is all the time available

epsi=0.001; % \epsilon-Outage probability

Ppon_min=0.1;
Ppon_stp=0.02;
Ppon_max=0.9;

%[a f1 f2 F1 F2 M1 M2 S1 S2 P0 F0 rho z V c z0 V0 c0 F1temp]    =Coef(Np, muP,lambdaP, Nc, muC, lambdaC , c_p, c_c);

%disp(['rho = ', num2str(rho)]);


theta=@(Ppon)lambdaC(Ppon)/c_p-muC(Ppon)/(c_c-c_p);
alpha=@(Ppon)muC(Ppon)/(muC(Ppon)+lambdaC(Ppon))*c_c/(c_c-c_p);

subplot(131),plot(Ppon_min:Ppon_stp:Ppon_max, theta(Ppon_min:Ppon_stp:Ppon_max))
ylabel(['Decay power, \theta'])
xlabel(['\fontname{times}Primay user activity factor'])
legend(['Analytical'])
grid on
hold off
axis square


subplot(132)
A=[];
q=20;
for Ppon=Ppon_min:Ppon_stp:Ppon_max
    
    a=EB1_1(epsi, q, muC(Ppon), lambdaC(Ppon) ,  c_c);

    A=[A a'];

end

plot(Ppon_min:Ppon_stp:Ppon_max,A);
ylabel(['Effective Bandwidth'])
xlabel(['\fontname{times}Primay user activity factor'])
legend(['Analytical'], ['Upper Case'])
grid on
hold off
axis square

subplot(133),plot(theta(Ppon_min:Ppon_stp:Ppon_max),A)
xlabel(['Decay power, \theta'])
ylabel(['\fontname{times}Effective Bandwidth'])
legend(['Analytical'], ['Upper Case'])
grid on
hold off
axis square
