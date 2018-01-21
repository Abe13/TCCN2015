%plot Fig 4

clc
clear

%Multi SUs and Multi PUs all exponential distributed
%Finding Eigenvector and Eigenvalues 
%Making matrices A, B for 
%Given cj=j*c and M and N 
%Making initial Condition P(0)

% plot Overflow probability for buffer and delay vs 
% buffer size and delay threshold
%change of \rho by lambdaP,lambdaC,muP,muC in different plots

%this works!
%Individiual Buffer

x=0:.5:300;
Np=9; % # Producer (SUs)
Nc=3; % # Consumer (PUs)



%mu:      stands for producing/consuming
%lambda:  stands for NOT producing/consuming

% Average ON time= 1/mu
%Average OFF time= 1/lambda

%Consumer (PU)
muC_0=1.919191;   % PU OFF period Parameter (Consuming)
lambdaC_0=4*muC_0;       % PU ON period parameter  (NOT Consuming) 

%Producer (SU)
muP_0=1.013;       % SU ON period parameter  (Producing)
lambdaP_0=1/4*muP_0;   % SU OFF period Parameter (NOT Producing)


c_c =2.5; % Each Consumer(primary)'s Channel capacity
c_p=1.1; % Each Producer(secondary)'s Channel capacity


epsi = 1e-5;

%rho ranges and changes
R_min=0.3;
R_stp=0.2;
R_max=0.95;

x=[0:0.1:2, 2:0.5:5, 5:1:8 , 8:2:50];
%x=0:1.5:50; %input range

    

F1_t_lambdaP=[]; %Overflow probability
F2_t_lambdaP=[]; %Individual Buffer Overflow probability

F1_t_lambdaC=[]; %Overflow probability
F2_t_lambdaC=[]; %Individual Buffer Overflow probability

F1_t_muP=[]; %Overflow probability
F2_t_muP=[]; %Individual Buffer Overflow probability

F1_t_muC=[]; %Overflow probability
F2_t_muC=[]; %Individual Buffer Overflow probability

%MuC Change---------------------------------------------------------
STR=[];
for rho=R_min:R_stp:R_max
    
    
    t1=Np*c_p*lambdaP_0/(lambdaP_0+muP_0);
    muC=lambdaC_0*(Nc*c_c*rho/(t1)-1);
    t2=Nc*(c_c*lambdaC_0)/(lambdaC_0+muC);
    
    if muC<0
        continue
    end

    
    if t1>t2 
        disp(['   UNSTABLE'])
    end
    
    [a f1 f2 F1 F2 M1 M2 S1 S2 P0 F0]=Coef(Np, muP_0,lambdaP_0, Nc, muC, lambdaC_0 , c_p, c_c );
    
    F1_t_muC=[F1_t_muC; F1(x)];
    F2_t_muC=[F2_t_muC; F2(x)];
    
    STR=[STR; '\rho = '];
end


semilogy(x,(F2_t_muC));
xlabel(['\fontname{times}Queueing Delay (s)'])
ylabel(['\fontname{times}Log of Delay Outage Probability'])
legend([STR,num2str((R_min:R_stp:R_max)',2)])
%title(['change of \rho by \mu_c'])
ylim([0,1])
axis square
grid on
hold off


%LambdaP Change---------------------------------------------------------
STR=[];
for rho=R_min:R_stp:R_max
    
    
    t2=Nc*(c_c*lambdaC_0)/(lambdaC_0+muC_0);
    lambdaP=rho*muP_0*t2/(Np-rho*t2); % SU OFF period Parameter (NOT Producing)
    if lambdaP<0
        continue;
    end
        
    t1=Np*c_p*lambdaP/(lambdaP+muP_0);
    
    if t1>t2 
        disp(['   UNSTABLE'])
    end
    
    [a f1 f2 F1 F2 M1 M2 S1 S2 P0 F0]=Coef(Np, muP_0,lambdaP, Nc, muC_0, lambdaC_0 , c_p, c_c );
    
    F1_t_lambdaP=[F1_t_lambdaP; F1(x)];
    F2_t_lambdaP=[F2_t_lambdaP; F2(x)];
    
    STR=[STR; '\rho = '];
end

figure
semilogy(x,(F2_t_lambdaP));
xlabel(['\fontname{times}Queueing Delay (s)'])
ylabel(['\fontname{times}Log of Delay Outage Probability'])
legend([STR,num2str((R_min:R_stp:R_max)',2)])
%title(['change of \rho by \lambda_p'])
ylim([0,1])
axis square
grid on
hold off

%MuP Change---------------------------------------------------------
STR=[];
for rho=R_min:R_stp:R_max
    
    t2=Nc*(c_c*lambdaC_0)/(lambdaC_0+muC_0);
    muP=lambdaP_0*(Np/rho/t2-1);
    if muP<0
        continue;
    end
    t1=Np*c_p*lambdaP_0/(lambdaP_0+muP);
    
    if t1>t2 
        disp(['   UNSTABLE'])
    end
    
    [a f1 f2 F1 F2 M1 M2 S1 S2 P0 F0]=Coef(Np, muP,lambdaP_0, Nc, muC_0, lambdaC_0 , c_p, c_c );
    
    F1_t_muP=[F1_t_muP; F1(x)];
    F2_t_muP=[F2_t_muP; F2(x)];
    STR=[STR; '\rho = '];

end

figure
semilogy(x,(F2_t_muP));
xlabel(['\fontname{times}Queueing Delay (s)'])
ylabel(['\fontname{times}Log of Delay Outage Probability'])
legend([STR,num2str((R_min:R_stp:R_max)',2)])
%title(['change of \rho by \mu_p'])
ylim([0,1])
axis square
grid on
hold off


%LambdaC Change---------------------------------------------------------

STR=[];
for rho=R_min:R_stp:R_max
    
    t1=Np*c_p*lambdaP_0/(lambdaP_0+muP_0);

    lambdaC=muC_0*t1/(Nc*c_c*rho+-t1);
    if lambdaC<0
        continue;
    end

    t2=Nc*(c_c*lambdaC)/(lambdaC+muC_0);
    
    if t1>t2 
        disp(['   UNSTABLE'])
    end
    
    [a f1 f2 F1 F2 M1 M2 S1 S2 P0 F0]=Coef(Np, muP_0,lambdaP_0, Nc, muC_0, lambdaC , c_p, c_c );
    
    F1_t_lambdaC=[F1_t_lambdaC; F1(x)];
    F2_t_lambdaC=[F2_t_lambdaC; F2(x)];

    STR=[STR; '\rho = '];
end


%subplot(224),
figure
semilogy(x,(F2_t_lambdaC));
xlabel(['\fontname{times}Queueing Delay (s)'])
ylabel(['\fontname{times}Log of Delay Outage Probability'])
legend([STR,num2str((R_min:R_stp:R_max)',2)])
%title(['change of \rho by \lambda_c'])
ylim([0,1])
axis square
grid on
hold off


