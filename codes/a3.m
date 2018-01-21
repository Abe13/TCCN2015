
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


x=0:.1:15; %input range

Np=13; % # Producer (SUs)
Nc=10; % # Consumer (PUs)



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



epsi = 1e-5;

%rho ranges and changes
R_min=0.7;
R_stp=0.2;
R_max=0.7;

    
F2_1t=[];
F2_2t=[];
F2_3t=[];
F2_4t=[];


c_p1=1.01;
c_p2=1.51;

c_c3=2.5;
c_c4=5;

STR=[];
for rho=R_min:R_stp:R_max
    
    t1=Np*c_p2*lambdaP_0/(lambdaP_0+muP_0);

    %c_c1=t1/rho/(Nc*lambdaC_0/(lambdaC_0+muC_0));
    c_c2=t1/rho/(Nc*lambdaC_0/(lambdaC_0+muC_0));
    c_c1=c_c2;
    
    [a f1 f2 F1 F2_1 M1 M2 S1 S2 P0 F0 r1]=Coef(Np, muP_0,lambdaP_0, Nc, muC_0, lambdaC_0 , c_p1, c_c1);
    [a f1 f2 F1 F2_2 M1 M2 S1 S2 P0 F0 r2]=Coef(Np, muP_0,lambdaP_0, Nc, muC_0, lambdaC_0 , c_p2, c_c2);
    [a f1 f2 F1 F2_3 M1 M2 S1 S2 P0 F0 r3]=Coef(Np, muP_0,lambdaP_0, Nc, muC_0, lambdaC_0 , c_p1, c_c3);
    [a f1 f2 F1 F2_4 M1 M2 S1 S2 P0 F0 r4]=Coef(Np, muP_0,lambdaP_0, Nc, muC_0, lambdaC_0 , c_p1, c_c4);
    
    
    F2_1t=[F2_1t; F2_1(x)];
    F2_2t=[F2_2t; F2_2(x)];
    F2_3t=[F2_3t; F2_3(x)];
    F2_4t=[F2_4t; F2_4(x)];

    
    s1=['\fontname{times}(\rho=',num2str(r1,'%.2f'),',c_p=',num2str(c_p1,'%.2f'),',c_c=', num2str(c_c1,'%.2f'),')'];
    s2=['\fontname{times}(\rho=',num2str(r2,'%.2f'),',c_p=',num2str(c_p2,'%.2f'),',c_c=', num2str(c_c2,'%.2f'),')'];
    s3=['\fontname{times}(\rho=',num2str(r3,'%.2f'),',c_p=',num2str(c_p1,'%.2f'),',c_c=', num2str(c_c3,'%.2f'),')'];
    
 
    STR=[STR ];
end


%subplot(224),
plot(x,[F2_1t;F2_2t;F2_3t]);
xlabel(['\fontname{times}Queueing Delay (s)'])
ylabel(['\fontname{times}Log of Delay Outage Probability'])
legend(s1,s2,s3)
%legend(['\lambda_c= ', num2str(lambdaC)],['\lambda_p= ', num2str(lambdaP)],...
%    ['\mu_c= ',num2str(muC)],['\mu_p= ', num2str(muP)])
%title(['\rho= ',num2str(rho)])
ylim([0,1])
axis square
grid on
hold off


