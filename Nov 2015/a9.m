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

muC=0.2/Tp;%[.59191 .79191 ];   % PU OFF period Parameter (Consuming)
lambdaC=0.3/Tp;       % PU ON period parameter  (NOT Consuming) 

%Producer (SU)

Pon=0.99999;
muP=1/Pon/Tp;       % SU ON period parameter  (Producing)
lambdaP=1/(1-Pon)/Tp;   % SU OFF period Parameter (NOT Producing)


c_c =1.; % Each Consumer(primary)'s Channel capacity
c_p =.45;     % C0 is all the time available

epsi=0.001; % \epsilon-Outage probability

[a f1 f2 F1 F2 M1 M2 S1 S2 P0 F0 rho z V c z0 V0 c0 F1temp]    =Coef(Np, muP,lambdaP, Nc, muC, lambdaC , c_p, c_c);

disp(['rho = ', num2str(rho)]);


theta=lambdaC/c_p-muC/(c_c-c_p);
alpha=muC/(muC+lambdaC)*c_c/(c_c-c_p);

subplot(224)
A=[];
q_min=0;
q_stp=0.5;
q_max=100;
for q=q_min:q_stp:q_max
    a=EB1(epsi, q, muC, lambdaC ,  c_c);
    A=[A a'];

end
plot(q_min:q_stp:q_max,c_c*lambdaC/(muC+lambdaC)+0*(q_min:q_stp:q_max),'--');
hold on
plot(q_min:q_stp:q_max,A);
ylabel(['Effective Bandwidth'])
xlabel(['\fontname{times}Buffer size, x'])
legend(['Asymptotic'],['Analytical'], ['Approximation_1'],['Approximation_2' ])
grid on
hold off
axis square



subplot(221)
syms t
ezplot(t,alpha*exp(-theta*t))
hold on
plot(x, F1(x),'r+')

plot(x, F1temp(x),'g+')

ylabel(['\fontname{times}P(Q>x)'])
xlabel(['\fontname{times}Buffer size, x'])
legend(['Analytical'],['Simulation'])
grid on
hold off
axis square

subplot(222)
syms t
ezplot(t,[log(alpha*exp(-theta*t))./t])
%plot(x, [log(alpha*exp(-theta*x))./x])
hold on
plot(x, [z0+0*x],'--g')
plot(x, [log(F1(x))./x],'*r')
hold off

ylabel(['\fontname{times}Log(P(Q>x)/x)'])
xlabel(['\fontname{times}Buffer size, x'])
legend(['Analytical'],['Approximation'], ['Simulation'])
grid on
hold off
axis square

subplot(223)
plot(x, [log(F2(x))./x; z0*c0+0*x])

ylabel(['\fontname{times}Log(P(\tau>x)/x)'])
xlabel(['\fontname{times}Delay size, x'])
legend(['Simulation'], ['Approximation \theta= ', num2str(z0*c0)])
grid on
hold off
axis square
