clc
clear

%Multi SUs and Multi PUs all exponential distributed
%Finding Eigenvector and Eigenvalues 
%Making matrices A, B for 
%Given cj=j*c and M and N 
%Making initial Condition P(0)

% plot Overflow probability for buffer and delay vs 
% buffer size and delay threshold
%change of \rho by lambdaP,lambdaC,muP,muC in same plot

%this works!
%Individiual Buffer


x=0:.1:50; %input range

Np=5; % # Producer (SUs)
Nc=2; % # Consumer (PUs)



%mu:      stands for producing/consuming
%lambda:  stands for NOT producing/consuming

% Average ON time= 1/mu
%Average OFF time= 1/lambda

%Consumer (PU) %80 off during time
muC_0=1.090919191;   % PU OFF period Parameter (Consuming)
lambdaC_0=4*muC_0;       % PU ON period parameter  (NOT Consuming) 

%Producer (SU) %60 off during time
muP_0=0.96957;       % SU ON period parameter  (Producing)
lambdaP_0=2/3*muP_0;   % SU OFF period Parameter (NOT Producing)


c_p=1.01; %consumer
%c_c =3.9; % Each Consumer(primary)'s Channel capacity

epsi = 1e-5;

%rho ranges and changes
c_min=3;

c_stp=0.131;
c_max=9.1;


F1_t_C_c=[]; %Overflow probability
F2_t_C_c=[]; %Individual Buffer Overflow probability

%c_c Change---------------------------------------------------------
STR=[];
for c_c=c_min:c_stp:c_max
    
    
    t1=Np*c_p*lambdaP_0/(lambdaP_0+muP_0);
    t2=Nc*(c_c*lambdaC_0)/(lambdaC_0+muC_0);
    
    rho=t1/t2;

    
    if t1>t2 
        disp(['   UNSTABLE'])
    end
    [a f1 f2 F1 F2 M1 M2 S1 S2 P0 F0]=Coef2(Np, muP_0,lambdaP_0, Nc, muC_0, lambdaC_0 , c_p, c_c );
    
    F1_t_C_c=[F1_t_C_c; F1(x)];
    F2_t_C_c=[F2_t_C_c; F2(x)];
    
    STR=[STR; ['\rho = ', num2str(rho,'%1.2f')]];
    disp(['\lambda_c= ', num2str(lambdaC_0),', \lambda_p= ', num2str(lambdaP_0),...
    '\mu_c= ',num2str(muC_0),'\mu_p= ', num2str(muP_0)])
    disp(['\rho = ', num2str(rho,'%1.2f'), ', c_c = ', num2str(c_c)])

end


%subplot(224),
semilogy(x,F2_t_C_c);
xlabel(['\fontname{times}Queueing Delay'])
ylabel(['\fontname{times}Delay Outage Probability'])
legend(STR)

ylim([0,1])
axis square
grid on
hold off


