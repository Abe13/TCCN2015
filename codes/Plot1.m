clc
clear

%One SU and One PUs
%Finding Eigenvector and Eigenvalues 



%this works!
%Individiual Buffer

x=0.0:.5:10;
Np=1; % # Producer (SUs)
Nc=1; % # Consumer (PUs)



%mu:      stands for producing/consuming
%lambda:  stands for NOT producing/consuming

% Average ON time= 1/mu
%Average OFF time= 1/lambda
%Consumer (PU)

p00=0.35; % NO channel
p11=(1-p00); % Channel available

muC=p00;%[.59191 .79191 ];   % PU OFF period Parameter (Consuming)
lambdaC=1-p00;       % PU ON period parameter  (NOT Consuming) 

%Producer (SU)

Pon=0.99999;
muP=1/Pon;       % SU ON period parameter  (Producing)
lambdaP=1/(1-Pon);   % SU OFF period Parameter (NOT Producing)


c_c =1; % Each Consumer(primary)'s Channel capacity
c_p =.45;     % C0 is all the time available

epsi=0.001; % \epsilon-Outage probability

[a f1 f2 F1 F2 M1 M2 S1 S2 P0 F0 rho z V c z0 V0 c0 F1temp]    =Coef(Np, muP,lambdaP, Nc, muC, lambdaC , c_p, c_c);

disp(['rho = ', num2str(rho)]);


theta=lambdaC/c_p-muC/(c_c-c_p);
alpha=muC/(muC+lambdaC)*c_c/(c_c-c_p);


A=[];
q_min=1;
q_stp=0.5;
q_max=100;

for q=q_min:q_stp:q_max
    a=EB1(epsi, q, muC, lambdaC ,  c_c);
    A=[A a'];

end

B=[];
for q=q_min:q_stp:q_max
    
    b=EB1_1(epsi, q, muC, lambdaC ,  c_c, p00, p11);

    B=[B b'];

end

%subplot(221)
plot(q_min:q_stp:q_max,A);
hold on
plot(q_min:q_stp:q_max,c_c*lambdaC/(muC+lambdaC)+0*(q_min:q_stp:q_max),'-.');
ylabel(['\fontname{times}Effective Bandwidth'])
xlabel(['\fontname{times}Buffer size, x'])
title('')
legend(['Analytical'], ['Approximation'],['Asymptotic'])
grid on
hold off
axis square



%subplot(222)
figure
syms t
ezplot(t,alpha*exp(-theta*t), [min(x), max(x)])
hold on
plot(x, F1(x),'r+')

%plot(x, F1temp(x),'g+')

ylabel(['\fontname{times}P(Q>x)'])
xlabel(['\fontname{times}Buffer size, x'])
title('')
legend(['Analytical'],['Simulation'])
grid on
hold off
axis square

%subplot(223)
figure
syms t
ezplot(t,[log(alpha*exp(-theta*t))./t], [min(x), max(x)])
%plot(x, [log(alpha*exp(-theta*x))./x])
hold on
plot(x, [log(F1(x))./x],'+r')
plot(x, [z0+0*x],'--g')
hold off

ylabel(['\fontname{times}Log P(Q>x)/x'])
xlabel(['\fontname{times}Buffer size, x'])
title('')
legend(['Analytical'], ['Simulation'],['Results in [4]'])
grid on
hold off
axis square

%subplot(224)
figure
plot(-log(epsi)./(q_min:q_stp:q_max),B);
ylabel(['\fontname{times}Effective Bandwidth'])
xlabel(['\fontname{times}QoS exponent'])
title('')
legend(['Analytical'],['Asymptotic'],['Approximation in [4]'])
grid on
hold off
axis square


figure
plot(-log(epsi)./(q_min:q_stp:q_max),100*abs(B(1,:)-B(3,:))./B(1,:));
ylabel(['\fontname{times}Error (%)'])
xlabel(['\fontname{times}QoS exponent'])
title('')
legend(['Approximation in [4]'])
grid on
hold off
axis square

