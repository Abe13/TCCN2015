clc
clear


%When there is just One PUs
N=6;

%this works!
%Individiual Buffer


c =1; % Each Consumer(primary)'s Channel capacity
a=0.3; % Each Producer(secondary)'s Channel capacity



%Case A
p11=0.2;
p00=0.6;

p10=1-p11;
p01=1-p00;


b=4e2;
epsi=1e-4;



alpha= p11-p01;
beta=p01/(p01+p10);

P11=@(k)beta*(1+p10/p01 * alpha^k);
P10=@(k)1-P11(k);

if p11 > p01
    
    Pl=@(t)(1-p11*exp((a-c)*t))*(exp(a*t)-1)+exp((a-c)*t)*(exp(a*t)-exp(c*t))*P10(N);
    Pu=@(t)(1-p11*exp((a-c)*t))*(exp(a*t)-1)+exp((a-c)*t)*(exp(a*t)-exp(c*t))*beta;
else
    Pl=@(t)exp(a*t)*(exp(a*t)-1)*(1-P11(2))+(exp(a*t)-exp(c*t))*(1-p00*exp(a*t));
    Pu=@(t)exp(a*t)*(exp(a*t)-1)*(1-P11(2*N-1))+(exp(a*t)-exp(c*t))*(1-p00*exp(a*t));
end
    
    
subplot(121)
syms t
ezplot(t, Pl(t), [-3  3])
ylabel(['P_l(\theta)'])
xlabel(['\theta'])
title('');
axis square
grid on

subplot(122)
syms t
ezplot(t, Pu(t), [-3  5])
ylabel(['P_u(\theta)'])
xlabel(['\theta'])
title('');
axis square
grid on
