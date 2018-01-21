clc
clear


%------------------------------------

%Consumer- Producer model

disp(['Consumer- Producer model'])
disp(['Single SU Multiple channels'])

Pcon=0.99999;

muC=1;%[.59191 .79191 ];   % PU OFF period Parameter (Consuming)
lambdaC=0.7;       % PU ON period parameter  (NOT Consuming) 

%Producer (SU)
muP=1/Pcon;       % SU OFF period parameter
lambdaP=1/(1-Pcon);   % SU ON period Parameter 

Nc=5; % Number of Consumers
Np=1; % Number of Producers

c_c=0.77; % Consumer channel Capacity
c_p=1; % Producer Channel Capacity

q_min=1;
q_stp=0.5;
q_max=1000;

X1=0.0;
DX=.1;
X2=4;
x=X1:DX:X2;

epsi=1e-2;


[a f1 f2 F1 F2 M1 M2 S1 S2 P0 F0 rho z V c z0 V0 c0 F1temp A B]=Coef(Np, muP,lambdaP, Nc, muC, lambdaC , c_p, c_c);

disp(['rho= ', num2str(rho)])

r4=Nc*(Nc*c_c*lambdaC-c_p*(muC+lambdaC))/(c_p*(Nc*c_c-c_p));
r5=Np*(Np*c_p*lambdaP-c_c*(muP+lambdaP))/(c_c*(Np*c_p-c_c));





disp(['z0= ', num2str(z0)])
disp(['r4= ', num2str(r4)])
disp(['z= ', num2str(sort(z))])


EB=@(epsi,q)[Nc/2*(c_c - (lambdaC+muC)*q/log(epsi)-sqrt((c_c - (lambdaC+muC)*q/log(epsi))^2 +4*c_c*lambdaC*q/log(epsi)));...
    Nc*c_c*lambdaC/(lambdaC+muC)];

QB=[];

for q=q_min:q_stp:q_max
    
    b=EB(epsi, q);

    QB=[QB b];

end





subplot(131)
hold on
plot(x,log10(abs(F1(x))), 'r.')
xlabel(['buffer size'])
ylabel(['Log(overflow probability)'])
grid on


subplot(132)
plot(q_min:q_stp:q_max,QB);
ylabel(['Effective Bandwidth'])
xlabel(['\fontname{times}Buffer size, x'])
title(['Single SU Multiple channels'])
legend(['Analytical'], ['Approximation'],['Asymptotic'])
grid on
hold off
axis square
