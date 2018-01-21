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

Np=13; % # Producer (SUs)
Nc=3; % # Consumer (PUs)



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
c_c =3.9; % Each Consumer(primary)'s Channel capacity

rho_0=Np*lambdaP_0/(lambdaP_0+muP_0)/(Nc*c_c*lambdaC_0/(lambdaC_0+muC_0));
epsi = 1e-5;

%rho ranges and changes
R_min=0.8;

R_stp=0.2;
R_max=R_min;

    

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
    [a f1 f2 F1 F2 M1 M2 S1 S2 P0 F0]    =Coef(Np, muP_0,lambdaP_0, Nc, muC, lambdaC_0 , c_p, c_c );
    
    F1_t_muC=[F1_t_muC; F1(x)];
    F2_t_muC=[F2_t_muC; F2(x)];
    
    STR=[STR; '\rho = '];
end




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

    [a f1 f2 F1 F2 M1 M2 S1 S2 P0 F0]    =Coef(Np, muP_0,lambdaP, Nc, muC_0, lambdaC_0 , c_p, c_c );
    
    F1_t_lambdaP=[F1_t_lambdaP; F1(x)];
    F2_t_lambdaP=[F2_t_lambdaP; F2(x)];
    
    STR=[STR; '\rho = '];
end

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

    [a f1 f2 F1 F2 M1 M2 S1 S2 P0 F0]    =Coef(Np, muP,lambdaP_0, Nc, muC_0, lambdaC_0 , c_p, c_c );
    
    F1_t_muP=[F1_t_muP; F1(x)];
    F2_t_muP=[F2_t_muP; F2(x)];
    STR=[STR; '\rho = '];

end

%LambdaC Change---------------------------------------------------------

STR=[];
for rho=R_min:R_stp:R_max
    
    t1=Np*c_p*lambdaP_0/(lambdaP_0+muP_0);

    lambdaC=muC_0*t1/(Nc*c_c*rho-t1);
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
semilogy(x,[F2_t_lambdaC;F2_t_lambdaP;F2_t_muC;F2_t_muP]);
xlabel(['\fontname{times}Queueing Delay'])
ylabel(['\fontname{times}Delay Outage Probability'])
legend(['\lambda_c= ', num2str(lambdaC)],['\lambda_p= ', num2str(lambdaP)],...
    ['\mu_c= ',num2str(muC)],['\mu_p= ', num2str(muP)])
title(['\rho= ',num2str(rho)])
ylim([0,1])
axis square
grid on
hold off


