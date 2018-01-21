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
%Ppon=0.50; % The probability that PU is On


p00=0.3; % NO channel
p11=(1-p00); % Channel available

muC=p00;%[.59191 .79191 ];   % PU OFF period Parameter (Consuming)
lambdaC=1-p00;       % PU ON period parameter  (NOT Consuming) 

%Producer (SU)

Pson=0.99999;
muP=1/Pson;       % SU ON period parameter  (Producing)
lambdaP=1/(1-Pson);   % SU OFF period Parameter (NOT Producing)


c_c =1.; % Each Consumer(primary)'s Channel capacity
c_p =.35;     % C0 is all the time available

epsi=0.1; % \epsilon-Outage probability

q_min=1;
q_stp=1;
q_max=100;


loge_min=2;
loge_stp=1;
loge_max=80;


%[a f1 f2 F1 F2 M1 M2 S1 S2 P0 F0 rho z V c z0 V0 c0 F1temp]    =Coef(Np, muP,lambdaP, Nc, muC, lambdaC , c_p, c_c);

%disp(['rho = ', num2str(rho)]);


theta=@(Ppon)lambdaC(Ppon)/c_p-muC(Ppon)/(c_c-c_p);
alpha=@(Ppon)muC(Ppon)/(muC(Ppon)+lambdaC(Ppon))*c_c/(c_c-c_p);




A=[];
for q=q_min:q_stp:q_max
    
    a=EB1_1(epsi, q, muC, lambdaC ,  c_c, p00, p11);

    A=[A a'];

end

B=[];
q=30;
for loge=loge_min:loge_stp:loge_max
    
    a=EB1_1(exp(-loge), q, muC, lambdaC ,  c_c, p00, p11);

    B=[B a'];

end

subplot(131)
plot((loge_min:loge_stp:loge_max)/q,B);
ylabel(['Effective Bandwidth'])
xlabel(['\fontname{times}-log\epsilon/q'])
title(['\epsilon changes'])
legend(['Analytical_1'],['Analytical_2'],['Analytical_3'], ['Upper Case'], ['Approximation'],['Result [4]'])
grid on
hold off
axis square


subplot(132)
plot(-log(epsi)./(q_min:q_stp:q_max),A);
ylabel(['Effective Bandwidth'])
xlabel(['\fontname{times}-log\epsilon/q'])
title(['q changes'])
legend(['Analytical_1'],['Analytical_2'],['Analytical_3'], ['Upper Case'], ['Approximation'],['Result [4]'])
grid on
hold off
axis square

subplot(133)
plot(exp(-(loge_min:loge_stp:loge_max)),B);
ylabel(['Effective Bandwidth'])
xlabel(['\fontname{times} -log\epsilon/q'])
title(['\epsilon changes'])
legend(['Analytical_1'],['Analytical_2'],['Analytical_3'], ['Upper Case'], ['Approximation'],['Result [4]'])
grid on
hold off
axis square

