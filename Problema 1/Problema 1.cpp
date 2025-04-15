#include<iostream>
#include<vector>

using namespace std;

class FEN{
	private:
		vector<string> partes;
		vector<string> filas;
	public:
		bool verificarFEN(string cadena);
		bool verificarFilas(string fila);
		bool verificarTurno(string turno);
		bool verificarEnroque(string enroque);
		bool verificarAlPaso(string alPaso);
		bool verificarMovimientos(string movimiento);
		void separarCadena(int modo, string cadena, vector<string> *arreglo);
};

bool FEN::verificarFEN(string cadena){
	
	separarCadena(0, cadena, &partes);
	if(partes.size() != 6){
		return false;
	}
	
	separarCadena(1, partes[0], &filas);
	if(filas.size() != 8){
		return false;
	}
	
	for(int i = 0; i < filas.size(); i++){
		if(!verificarFilas(filas[i])){
			return false;
		}
	}
	
	verificarTurno(partes[1]);
	verificarEnroque(partes[2]);
	verificarAlPaso(partes[3]);
	
	if(!verificarMovimientos(partes[4])){
		return false;
	}
	
	if(!verificarMovimientos(partes[5]) || stoi(partes[5]) < 1){
		return false;
	}

	return true;	
}

bool FEN::verificarFilas(string fila){
	string piezas = "rnbqkpPRNBQK";
	int casillas = 0;
	
	for(int i = 0; i < fila.size(); i++){
		char casilla = fila[i];
		
		if(isdigit(casilla)){
			casillas += casilla - '0';
			
		}else if(piezas.find(casilla) != string::npos){
			casillas += 1;
			
		}else if(casilla == '0'){
			return false;
		}
	}
	
	if(casillas != 8){
		return false;
	}
	
	return true;
}

bool FEN::verificarTurno(string turno){
	if(turno != "w" && turno != "b"){
		return false;
	}
	
	return true;
}

bool FEN::verificarEnroque(string enroque){
	string piezas = "KQkq";
	
	if(enroque == "-"){
		return true;
	}
	
	for(int i = 0; i < enroque.size(); i++){
		char casilla = enroque[i];
		
		if(piezas.find(casilla) == string::npos){
			return false;
		}
	}
	
	for(int i = 0; i < enroque.size(); i++){
        for(int j = i + 1; j < enroque.size(); j++){
            if(enroque[i] == enroque[j]){
            	return false;	
			}
        }
    }
    
    return true;
}

bool FEN::verificarAlPaso(string alPaso){
	if(alPaso == "-"){
		return true;
	}
	
	if(alPaso.size() != 2){
		return false;
	}
	
	if(!((alPaso[0] >= 'a' && alPaso[0] <= 'h') && (alPaso[1] == '3' || alPaso[1] == '6'))){
		return false;
	}
	
	return true;
}

bool FEN::verificarMovimientos(string movimiento){
	for(int i = 0; i < movimiento.size(); i++){
		if(!isdigit(movimiento[i])){
			return false;
		}
	}
	
	return true;
}

void FEN::separarCadena(int modo, string cadena, vector<string> *arreglo){
	string aux;
	
	for(int i = 0; i < cadena.length(); i++){
		if((cadena[i] != ' ' && modo == 0) || (cadena[i] != '/' && modo == 1)){
			aux += cadena[i];
		}else{
			arreglo->push_back(aux);
			aux = "";
		}
	}
	arreglo->push_back(aux);
	aux = "";
}

int main(){
	string cad_C;
	FEN fen;
	
	cout << "Ingrese una cadena de texto: ";
	getline(cin, cad_C);
	
	if(fen.verificarFEN(cad_C)){
		cout << "La cadena dada cumple con el formato FEN." << endl;
	}else{
		cout << "La cadena no cumple con el formato FEN." << endl;
	}
	
	return 0;
}