#include <iostream>
#include <string>
using namespace std;
const int NFILAS=6;
const int NCOLUMNAS=6;
int leercintaactual(string , int& p );
//int avanzarcinta(string , string , int& p );
int mente(string matriz[NFILAS][NCOLUMNAS], string, int, int& p );


int main(){
	string cinta; //definimos la cinta
	cinta = "000111B"; //relenamos cinta
	cout<<cinta<<endl;
	string matriz[NFILAS][NCOLUMNAS];
	
	matriz[1][0] = "q0";
	matriz[2][0] = "q1";
	matriz[3][0] = "q2";
	matriz[4][0] = "q3";
	matriz[5][0] = "q4";	
	matriz[1][1] = "q1,X,D";
	matriz[2][1] = "q1,0,D";
	matriz[3][1] = "q2,0,I";
	matriz[2][2] = "q2,Y,I";
	matriz[3][3] = "q0,X,D";	
	matriz[1][4] = "q3,Y,D";
	matriz[2][4] = "q1,Y,D";
	matriz[3][4] = "q2,Y,I";
	matriz[4][4] = "q3,Y,D";
	matriz[4][5] = "q4,B,D";
	
		
    int p = 0; // pocicion de la cinta en un inicio
	mente(matriz, cinta, 1, p);
	return 0;
}

int leercintaactual(string cinta, int& p ){
	int n;
	if(p <= cinta.size() ){
		if(cinta[p]=='0'){n=0;}
		if(cinta[p]=='1'){n=1;}
		if(cinta[p]=='X'){n=2;}
		if(cinta[p]=='Y'){n=3;}
		if(cinta[p]=='B'){n=4;}
	}else{ cout<<"error";}
	return n;
}

int mente(string matriz[NFILAS][NCOLUMNAS], string cinta, int x, int& p){
	//lo primero es leer la cinta, y mandar coordenada y de la matriz segun la lectura
	int y;
			if(leercintaactual(cinta, p)==0){y=1;}//si es 0 1 x y b
			if(leercintaactual(cinta, p)==1){y=2;}
			if(leercintaactual(cinta, p)==2){y=3;}
			if(leercintaactual(cinta, p)==3){y=4;}
			if(leercintaactual(cinta, p)==4){y=5;/*cout<<"cinta finalizada con exito"; return 0;*/}
	string temp, tempp, temppp, tempppp; int xx, yy; //variales
	temp = matriz[x][y];
	if (temp==""){
		cout<<" error la cinta esta mal ";
		return 0;
	}
	
	//actualizar subestadoooooooooooooooooooo-------------------------------------------------------
		tempp = temp[1];
		xx = stoi(tempp); 
		x = xx+1; //x actualizado
	//actualizar cinta 
		temppp = temp[3];
		
		if(temppp =="0"){cinta[p] = '0';}
		if(temppp =="X"){cinta[p] = 'X';}
		if(temppp =="Y"){cinta[p] = 'Y';}
		if(temppp =="B"){cinta[p] = 'B'; cout<<"cinta finalizada con exito"; return 0;}//--------------------PENDIENTE
		
		cout<<cinta<<endl;
		
		tempppp = temp[5];
		if(tempppp == "D"){
			p=p+1;
		}
		if(tempppp=="I"){
			p=p-1;
		}
			
	
	return mente(matriz, cinta, x, p);
}

