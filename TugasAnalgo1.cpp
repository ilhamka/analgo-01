#include <iostream> 
#include <string.h> 
#include <stdio.h> 
using namespace std; 
#define N 5 

bool pPilihL1dariL(int pilih[2*N][N], int p, int l, int l1) 
{ 
for (int i = 0; i < N; i++) 
{ 
if (pilih[p][i] == l1) 
return true; 

if (pilih[p][i] == l) 
return false; 
} 
} 

void stabil(int pilih[2*N][N]) 
{ 

int pPasangan[N]; 


bool lKosong[N]; 

memset(pPasangan, -1, sizeof(pPasangan)); 
memset(lKosong, false, sizeof(lKosong)); 
int freecount = N; 

while (freecount > 0) 
{ 
int l; 
for (l = 0; l < N; l++) 
if (lKosong[l] == false) 
break; 


for (int i = 0; i < N && lKosong[l] == false; i++) 
{ 
int p = pilih[l][i]; 


if (pPasangan[p-N] == -1) 
{ 
pPasangan[p-N] = l; 
lKosong[l] = true; 
freecount--; 
} 

else 
{ 
int l1 = pPasangan[p-N]; 


if (pPilihL1dariL(pilih, p, l, l1) == false) 
{ 
pPasangan[p-N] = l; 
lKosong[l] = true; 
lKosong[l1] = false; 
} 
} 
} 
}


cout << "Girl Boy" << endl;
string namacowo;
string namacewe;
int a;a=0;
for (int i = 0; i < N; i++) 
{
    if(i==N-1) cout<<a;
if(i<N){
    if(pPasangan[i]==0)
        namacowo="Victor";
    if(pPasangan[i]==1)
        namacowo="Wyatt";
    if(pPasangan[i]==2)
    namacowo="Xavier";
    if(pPasangan[i]==3)
    namacowo="Yancey";
    if(pPasangan[i]==4)
    namacowo="Zeus";
    if(i==0)
    namacewe="Amy";
    if(i==1)
    namacewe="Bertha";
    if(i==2)
    namacewe="Clare";
    if(i==3)
    namacewe="Diane";
    if(i==4)
    namacewe="Erika";
}
    cout << " " << namacewe << "\t" << namacowo << endl;
    a=a+1;
}
} 
int main() 
{ 
int pilih[2*N][N] = { {6,5,8,9,7},
{8,6,5,7,9},
{6,9,7,8,5},
{5,8,7,6,9},
{6,8,5,9,7},
{4,0,1,3,2},
{2,1,3,0,4},
{1,2,3,4,0},
{0,4,3,2,1},
{3,1,4,2,0} 
}; 
stabil(pilih); 

return 0; 
}