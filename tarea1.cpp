#include <iostream>
#include <cstring>
#include <list>

using namespace std;
//Procesar es una función que recibe inputs descritos a continuación, para llenar la lista de soluciones (list<string>& soluciones) con soluciones exitosas
//String comandoUsuario es la representación en versión string del input del usuario.
//Int i es la posición del string comandoUsuario que se está evaluando en cada iteración
//String solucion es un string que almacena una solución específica y es capaz de crecer en cada iteración
//Int parentesisEnCola es un contador que representa la cantidad de parentesis '(' que no se han cerrado en el string solucion
//list<string>& soluciones es una lista de strings que se pasa por referencia y almacena todas las soluciones exitosas del algoritmo
//Int parentesisEliminados es un contador que indica cuantos paréntesis se han eliminado en una solución específica
//Int n es un número que determina la cantidad máxima de parentesis eliminados que queremos obtener en las soluciones 
void procesar(string comandoUsuario,int i,string solucion,int parentesisEnCola,list<string>& soluciones,int parentesisEliminados, int n){  
	if(parentesisEliminados>n){return;}
	int     len= comandoUsuario.size();
	if(i >= len){
		if(parentesisEnCola==0){		
			soluciones.push_back(solucion);	
			return;
		}else{return;}}

	if (comandoUsuario.at(i)=='('){
		procesar(comandoUsuario, i+1, solucion.substr(0,i),parentesisEnCola,soluciones,parentesisEliminados+1,n);
		procesar(comandoUsuario, i+1, solucion.substr(0,i) + '(',parentesisEnCola+1,soluciones,parentesisEliminados,n);}

	else if (comandoUsuario.at(i)!='(' && comandoUsuario.at(i)!=')'){procesar(comandoUsuario, i+1, solucion.substr(0,i)+comandoUsuario.at(i),parentesisEnCola,soluciones,parentesisEliminados,n);}

	else if (comandoUsuario.at(i)==')'){
			if (parentesisEnCola>0){	
				procesar(comandoUsuario, i+1, solucion.substr(0,i) + ')',parentesisEnCola-1,soluciones,parentesisEliminados,n);
				procesar(comandoUsuario, i+1, solucion.substr(0,i),parentesisEnCola,soluciones,parentesisEliminados+1,n);}
			else if (parentesisEnCola==0){
				procesar(comandoUsuario, i+1, solucion.substr(0,i),parentesisEnCola,soluciones,parentesisEliminados+1,n);		
				return;
			}else{return;}}}

//Main en donde se recibe el input del usuario, se llama a la función procesar e imprime las soluciones exitosas. 
int main() 
{
	list<string> soluciones;
	string line;
	while (getline(cin, line))
	{
		char    *comandoUsuario = new char[line.size()+1];
		comandoUsuario[line.size()]=0;
		memcpy(comandoUsuario,line.c_str(),line.size());
		string strSComando(comandoUsuario);
		int n=0;
		while (soluciones.size()==0){
			procesar(strSComando,0, "",0,soluciones,0,n);
			n++;
		}

		soluciones.sort();
		soluciones.unique();   
		list<string>::iterator it = soluciones.begin();

		while( it != soluciones.end())
		{
			if(*it != ""){cout << *it++ << endl;}
			else{it++;}
		}

		cout << "" << endl;
		soluciones.clear();
		free(comandoUsuario);
	}return 0;}


