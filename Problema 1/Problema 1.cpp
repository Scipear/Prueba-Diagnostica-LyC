#include<iostream>
#include<vector>

using namespace std;

bool verificarFEN(string cadena);
bool verificarFilas(string fila);
bool verificarTurno(string turno);
bool verificarEnroque(string enroque);
bool verificarAlPaso(string alPaso);
bool verificarMovimientos(string movimiento);

int main(){
	string cad_C;
	
	cout << "Ingrese una cadena de texto: ";
	getline(cin, cad_C);
	
	if(verificarFEN(cad_C)){
		cout << "La cadena dada cumple con el formato FEN." << endl;
	}else{
		cout << "La cadena no cumple con el formato FEN." << endl;
	}
	
	return 0;
}

bool verificarFEN(string cadena){
	string aux;
	vector<string> partes;
	vector<string> filas;
	
	for(int i = 0; i < cadena.length(); i++){
		char letra = cadena[i];
		
		if(letra != ' '){
			aux += letra;
		}else{
			partes.push_back(aux);
			aux = "";
		}
	} //Colocar esto como una funcion
	partes.push_back(aux); // Depurar algo aqui
	aux = "";
	
	if(partes.size() != 6){
		return false;
	}
	
	for(int i = 0; i < partes[0].length(); i++){
		char f = partes[0][i];
		
		if(f != '/'){
			aux += f;
		}else{
			filas.push_back(aux);
			aux = "";
		}
	} //Colocar esto como una funcion
	filas.push_back(aux); //Y aqui
	aux = "";
	
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
} //Esto ta como el culo tengo que ponerlo bonito pe

bool verificarFilas(string fila){
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
} // REACOMODAR TODO ESTO

bool verificarTurno(string turno){
	if(turno != "w" && turno != "b"){
		return false;
	}
	
	return true;
}

bool verificarEnroque(string enroque){
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

bool verificarAlPaso(string alPaso){
	if(alPaso == "-"){
		return true;
	}
	
	if(alPaso.size() != 2){
		return false;
	}
	
	if(!((alPaso[0] >= 'a' && alPaso[0] <= 'h') && (alPaso[1] == '3' || alPaso[1] == '6'))){
		return false;
	} // Acomodar esto papito querido
	
	return true;
}

bool verificarMovimientos(string movimiento){
	for(int i = 0; i < movimiento.size(); i++){
		if(!isdigit(movimiento[i])){
			return false;
		}
	}
	
	return true;
}