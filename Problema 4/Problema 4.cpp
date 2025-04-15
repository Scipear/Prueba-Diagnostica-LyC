#include<iostream>

using namespace std;

class Ocurrencia{
	private:
		int n_ocurrencias;
	public:
		int getOcurrencias();
		void evaluarCadena(string cadena, string palabra);
};

int Ocurrencia::getOcurrencias(){
	return n_ocurrencias;
}

void Ocurrencia::evaluarCadena(string cadena, string palabra){
	string p_aux = "";
	
	for(int i = 0; i < cadena.length(); i++){
		if(cadena[i] == ' ' && p_aux != ""){
			if(p_aux == palabra){
				n_ocurrencias++;
			
			}else{
				p_aux = "";	
			}
		}else{
			p_aux += cadena[i];
		}
	}
	
	if(p_aux == palabra){
        n_ocurrencias++;
    }
}


int main(){
	string cadena;
	string palabra;
	Ocurrencia ocurrencia;
	
	cout << "Ingrese la cadena a evaluar: ";
	getline(cin, cadena);
	
	cout << "Ingrese la palabra que quiere buscar: ";
	getline(cin, palabra);
	
	ocurrencia.evaluarCadena(cadena, palabra);
	
	cout << "La palabra " << palabra << " se repite " << ocurrencia.getOcurrencias() << " veces en la cadena." << endl;
	
}