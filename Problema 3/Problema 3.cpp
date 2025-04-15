#include<iostream>
#include<stack>
#include<vector>

using namespace std;

class Calculadora{
	private:
		vector<string> notacion;
		stack<double> resultado;
		
	public:
		double getResultado();
		int evaluarPrioridad(char op);
		void cambiarNotacion(string expresion);
		void calcular();
		
};

double Calculadora::getResultado(){
	return resultado.top();
}

int Calculadora::evaluarPrioridad(char op){
	if(op == '*' || op == '/'){
		return 2;
	}
	return 1;
}

void Calculadora::cambiarNotacion(string expresion){
	stack<char> operadores;
	string num = "";
	
	for(int i = 0; i < expresion.length(); i++){
		if(expresion[i] != ' '){
			if(isdigit(expresion[i]) || expresion[i] == 'E' || expresion[i] == 'e'){
	            num += expresion[i];
							
			}else if(expresion[i] == '('){
				if(num != ""){
					notacion.push_back(num);
					num = "";
				}
				operadores.push(expresion[i]);
			
			}else if(expresion[i] == '+' || expresion[i] == '-' || expresion[i] == '*' || expresion[i] == '/'){
				if(i != 0 && expresion[i] == '-' && (expresion[i-1] == 'E' || expresion[i-1] == 'e')){
					num += expresion[i];
					
				}else{
					if(num != ""){
						notacion.push_back(num);
						num = "";
					}
					
					while(!operadores.empty() && evaluarPrioridad(expresion[i]) <= evaluarPrioridad(operadores.top()) && operadores.top() != '('){
						notacion.push_back(string(1, operadores.top()));
						operadores.pop();
					}
					operadores.push(expresion[i]);
				}
				
			}else if(expresion[i] == ')'){
				if(num != ""){
					notacion.push_back(num);
					num = "";
				}
				
				while(!operadores.empty() && operadores.top() != '('){
					notacion.push_back(string(1, operadores.top()));
					operadores.pop();
				}
				
				if(!operadores.empty()){
					operadores.pop();
				}
				cout << "Aqui?" << endl;
			}
		}
		
		if(!operadores.empty()){
			cout << "iteracion: " << i << " ultimo operador ingresado: " << operadores.top() << endl;
		}
		
		if(!notacion.empty()){
			cout << "iteracion: " << i << " notacion va: " << notacion.back() << endl;
		}
	}
	
	if(num != ""){
		notacion.push_back(num);
		num = "";
	}
	
	while(!operadores.empty()){
        notacion.push_back(string(1, operadores.top()));
		operadores.pop();
    }
}

void Calculadora::calcular(){
	for(int i = 0; i < notacion.size(); i++){
		if(notacion[i] == "+" || notacion[i] == "-" || notacion[i] == "/" || notacion[i] == "*"){
			double b = resultado.top();
			resultado.pop();
			double a = resultado.top();
			resultado.pop();
			
			if(notacion[i] == "+"){
				resultado.push(a + b);
				
			}else if( notacion[i] == "-"){
				resultado.push(a - b);
				
			}else if( notacion[i] == "/"){
				resultado.push(a / b);
				
			}else if( notacion[i] == "*"){
				resultado.push(a * b);
				
			}

		}else{
			resultado.push(stod(notacion[i]));
			
		}
	}
}

int main(){
	string expresion;
	Calculadora calculadora;
	
	cout << "Ingrese la expresion que desee calcular: ";
	getline(cin, expresion);
	
	calculadora.cambiarNotacion(expresion);
	calculadora.calcular();
	
	cout << "El resultado es: " << calculadora.getResultado() << endl;
	
	return 0;
}