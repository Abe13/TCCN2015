function [a f1 f2 F1 F2 M1 M2 S1 S2 P0 F0 rho fl]    =Coef2(Np, muP,lambdaP, Nc, muC, lambdaC , c_p, c_c)
%[a f1 f2 F1 F2 M1 M2 S1 S2 P0 F0 rho]=Coef(Np, muP,lambdaP, Nc, muC, lambdaC , c_p, c_c )
% finds coefficients
%disp([num2str(c0)])

fl=0; % flag to show if min (c_d <epsi)

rho=RHO(Np, muP,lambdaP, Nc, muC, lambdaC , c_p, c_c);
epsi = 1e-3;

A=zeros((Np+1)*(Nc+1));
B=zeros((Np+1)*(Nc+1));

k=0;
d0=0;
d_p=0;
d_n=0;

Sij=[];
for i=0:Np

    for j=0:Nc
        if i==(j*c_c)/c_p
            d0=d0+1;
        end
        if i>(j*c_c)/c_p
            d_p=d_p+1;
            Sij=[Sij; i, j];

        end
        if i<(j*c_c)/c_p
            d_n=d_n+1;
        end

    end

end

%disp(['(d_0= ' ,num2str(d0),', d_p= ' ,num2str(d_p),', d_n= ' ,num2str(d_n),')'])



% Matrix A

k=0;
for i=0:Np

    for j=0:Nc
        A(k+j+1,k+j+1)=i*c_p-(j*c_c); %check if it should be "i*lambdaP"
    end
    k=k+(Nc+1);
end

% Matrix B

Bp=zeros((Np+1));

for i=0:Np
   Bp(i+1,i+1)= -((Np-i)*lambdaP + i*muP);

   if (i>0) 
    Bp(i,i+1)= (Np-i+1)*lambdaP;
   end

   if(i<Np)
    Bp(i+2,i+1)= (i+1)*muP;
   end
end


Bc=zeros((Nc+1));

for i=0:Nc
   Bc(i+1,i+1)= -((Nc-i)*lambdaC + i*muC);

   if (i>0) 
    Bc(i,i+1)= (Nc-i+1)*lambdaC;
   end

   if(i<Nc)
    Bc(i+2,i+1)= (i+1)*muC;
   end
end


I_Np=eye(Np+1);
I_Nc=eye(Nc+1);

B=kron(Bp,I_Nc)+kron(I_Np,Bc);
%---------------------------------------------------------------
In0=(0:Np);
W1=1/(lambdaP+muP)^Np .*factorial(Np)./factorial(Np-In0)./factorial(In0)...
     .*lambdaP.^In0.*muP.^(Np-In0);

In0=(0:Nc);
W2=1/(lambdaC+muC)^Nc .*factorial(Nc)./factorial(Nc-In0)./factorial(In0)...
     .*lambdaC.^In0.*muC.^(Nc-In0);

W=kron(W1,W2);

t1=Np*c_p*lambdaP/(lambdaP+muP);
t2=Nc*(c_c*lambdaC)/(lambdaC+muC);


%disp(['Input Rate = ',num2str(t1)])
%disp(['Capacity= ',num2str(t2)])
if t1>t2 
    disp(['   UNSTABLE'])
end

Lambda=(eig(B',A'));
[V D]=eig(B',A');
%disp(['#Eigenvalues = ',num2str(length(Lambda))])
%disp(['#Non infinity Negative Eigenvalues = ',num2str(sum(~isinf(Lambda')& (Lambda'<-epsi)))])
%disp(['#Positive Eigenvalues = ',num2str(sum(Lambda>epsi))])


L=[];
Da=[];
Va=[];
for l=1:length(D)
    if (~isinf(D(l,l)')&& (D(l,l)<-epsi))

        Da=[Da, D(l,l)];
        Va=[Va V(:,l)];
        L=[L, l];


    end
    J=mod(L-1, Nc+1);
end


% Initial Condition
P0=zeros((Nc+1)*(Np+1),1);

k=0;
K=[];
Ea=[];
Fa=[];
for i=0:Np

    for j=0:Nc

        if i> (j*c_c)/c_p

            P0(k+j+1)=0;
            K=[K, k+j+1];
            Ea=[Ea ; Va(k+j+1,:)];
            Fa=[Fa; -W(k+j+1)];
        else
            P0(k+j+1)=W(k+j+1);
        end
    end
    k=k+Nc+1;
end




%E a= F;
F=zeros(d_p,1);
E=zeros(d_p,d_p);

for k=1:d_p
    F(k)=-W(K(k));
    for l=1:length(L)
        E(k,l)=V(K(k),L(l));
    end
end

a=E^-1*F;

%disp(['Coessicient a= ',num2str(a')])

f1=@(x,l)W(l);
f2=@(t,l)W(l);

m1=@(l)0;
m2=@(l)0;

s1=@(l)0;
s2=@(l)0;



c_d=@(l)abs(mod(l-1,Nc+1)*c_c-floor((l-1)/(Nc+1))*c_p);
%disp(num2str(min(c_d(2:(Np+1)*(Nc+1)))))

if min(c_d(2:(Np+1)*(Nc+1)))<epsi
    disp(['Vaveyla!!'])
end

for k=1:d_p 
    
    
    
    
    f1=@(x,l) f1(x,l)+a(k)*exp(D(L(k),L(k))*x).*V(l,L(k));
    f2=@(t,l) f2(t,l)+a(k)*exp(D(L(k),L(k))*c_d(l)*t).*V(l,L(k));
    
end

f2_1=@(t)(muP/(lambdaP+muP))^Np * (muC/(lambdaC+muC))^Nc *(1-exp(-(Np*muP+Nc*muC)*t));
f2_0=@(t,i,j)choose(Np,i)*muP^(Np-i)*lambdaP^i/(lambdaP+muP)^Np *...
    choose(Nc,j)*muC^(Nc-j)*lambdaC^j/(lambdaC+muC)^Nc *...
    (1-exp(-((Np-i)*muP+i*lambdaP+(Nc-j)*muC+j*lambdaC)*t));
F1=@(x)0;

F2=@(t)0;

M1=0;
M2=0;
S1=0;
S2=0;

F0=[];

for l=1:(Np+1)*(Nc+1)
    F1=@(x)F1(x)+f1(x,l);
    
    
    F0=[F0 f1(0,l)];

%    subplot(121),plot(x,f1(x,l))
%    hold on 
%    grid on

    if c_d(l)<=epsi
        F2=@(t)F2(t)+f2_0(t,floor((l-1)/(Nc+1)), mod(l-1,Nc+1));
        if (l>1)
            fl=1;
        end
    else
        F2=@(t)F2(t)+f2(t,l);
    end


 %   subplot(122),plot(x,f2(x,l))
 %   hold on 
 %   grid on

    M1=M1+m1(l);
    M2=M2+m2(l);

    S1=S1+s1(l);
    S2=S2+s2(l);
end

F1=@(x)1-F1(x);
F2=@(t)1-F2(t);


