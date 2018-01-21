clc
clear



N=2; %Number of PUs/Channels

%this works!
%Individiual Buffer


c =1; % Each Consumer(primary)'s Channel capacity
a=1.45; % Each Producer(secondary)'s Channel capacity





p00=0.2; % NO channel
p11=(1-p00); % Channel available

p10=1-p11;
p01=1-p00;


muC=p00;%[.59191 .79191 ];   % PU OFF period Parameter (Consuming)
lambdaC=1-p00;       % PU ON period parameter  (NOT Consuming) 

%Producer (SU)
Pson=0.99999;
muP=1/Pson;       % SU ON period parameter  (Producing)
lambdaP=1/(1-Pson);   % SU OFF period Parameter (NOT Producing)



b=4e2;
epsi=1e-4;

rho=RHO(1, muP,lambdaP, N, muC, lambdaC , a, c);

disp(['rho = ', num2str(rho)])

%-------------------------
%Simulation [4]

alpha= p11-p01;
beta=p01/(p01+p10);

P11=@(k)beta*(1+p10/p01 * alpha^k);
P10=@(k)1-P11(k);

if p11 >= p01
    
    Pl=@(t)(1-p11*exp((a-c)*t))*(exp(a*t)-1)+exp((a-c)*t)*(exp(a*t)-exp(c*t))*P10(N);
    Pu=@(t)(1-p11*exp((a-c)*t))*(exp(a*t)-1)+exp((a-c)*t)*(exp(a*t)-exp(c*t))*beta;
else
    Pl=@(t)exp(a*t)*(exp(a*t)-1)*(1-P11(2))+(exp(a*t)-exp(c*t))*(1-p00*exp(a*t));
    Pu=@(t)exp(a*t)*(exp(a*t)-1)*(1-P11(2*N-1))+(exp(a*t)-exp(c*t))*(1-p00*exp(a*t));
end
    
    
subplot(131)
syms t
ezplot(t, Pl(t), [0  3])
ylabel(['P_l(\theta)'])
xlabel(['\theta'])
title('');
axis square
grid on

subplot(132)
syms t
ezplot(t, Pu(t), [0  5])
ylabel(['P_u(\theta)'])
xlabel(['\theta'])
title('');
axis square
grid on
%------------------------------
%Simuation

[a f1 f2 F1 F2 M1 M2 S1 S2 P0 F0 rho z V c z0 V0 c0 F1temp] =Coef(1, muP,lambdaP, N, muC, lambdaC , a, c);


zl=fzero(Pl, 0.5);
zu=fzero(Pu, 1*abs(z0));

disp(['zl= ', num2str(zl),', zu= ', num2str(zu),', z0= ', num2str(z0),])

fl=-zl+0*t;
fu=-zu+0*t;

tmin=0;
tmax=15;

subplot(133)
%figure
ezplot(t,log(F1(t))/t, [tmin  tmax])
hold on
ezplot(t,fl, [tmin  tmax])
ezplot(t,fu, [tmin  tmax])
hold off
ylabel(['P(Q>x)'])
xlabel(['buffer size, x'])

title(['\rho= ',num2str(rho),', zl= ', num2str(zl),', zu= ', num2str(zu),', z0= ', num2str(z0),]);
axis square
grid on



