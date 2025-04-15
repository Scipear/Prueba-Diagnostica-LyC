#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

class Polinomio{
	private:
		vector<vector<int>> coeficientes;
		vector<int> terminos;
		int resultado;
	public:
		Polinomio();
		int getResultado();
		int combinatoria(int n, int k);
		int factorial(int n);
		void generarCoeficientes(int n);
		void calcularPolinomio(int n, int x);
		void imprimirPolinomios();
		void imprimirResultado();
};

Polinomio::Polinomio(){
	resultado = 0;
}

void Polinomio::generarCoeficientes(int n){
	coeficientes.resize(n + 1);
	for(int i = 0; i <= n; i++){
		coeficientes[i].resize(i + 1);
		for(int j = 0; j <= i; j++){
			coeficientes[i][j] = combinatoria(i, j);
			cout << coeficientes[i][j] << " ";
		}
		cout << endl;
	}
}

int Polinomio::combinatoria(int n, int k){
	return factorial(n) / (factorial(k) * factorial(n - k));
}

int Polinomio::factorial(int n){
	int fac = 1;
	
	for(int i = 2; i <= n; i++){
		fac *= i;                  
	}
	
	return fac;
}


void Polinomio::calcularPolinomio(int n, int x){
	for(int i = 0; i < coeficientes[n].size(); i++){
		int xValor = pow(x, n - i);
		int termino = coeficientes[n][i] * xValor;
		terminos.push_back(termino);
		
		if(i != n){
			cout << "Paso " << i+1 << ": " << coeficientes[n][i] << " * " << x << "^" << (n - i) << " = " << termino << endl;
		}
	
		resultado += termino;
	}
	
	imprimirResultado();
}

void Polinomio::imprimirPolinomios(){
	for(int i = 0; i < coeficientes.size(); i++){
		cout << "(x + 1)^" << i << " = ";
		for(int j = 0; j < coeficientes[i].size(); j++){
			cout << coeficientes[i][j];
			
			if(i > 0 && j != coeficientes[i].size() - 1){
				cout << "x";
				if(i-j != 1){
					cout << "^" << i - j;
				}
				cout << " + ";
			}
		}
		cout << endl;
	}
}

void Polinomio::imprimirResultado(){
	cout << "\n\n (x + 1)^" << terminos.size()-1 << " = ";
	for(int i = 0; i < terminos.size(); i++){
		cout << terminos[i];
		if(i != terminos.size() - 1){
			cout << " + ";
		}
	}
	
	cout << " = " << resultado;
}

int main(){
	int n, x;
	Polinomio polinomio;
	
	cout << "Ingrese el valor del numero n: ";
	cin >> n;
	
	cout << "\nTriangulo de Pascal: " << endl;
	polinomio.generarCoeficientes(n);
	
	cout << "\n\nPolinomios de " << n << "" << endl << endl;
	polinomio.imprimirPolinomios();
	
	cout << "\n\nIngrese el valor de x para resolver el polinomio: ";
	cin >> x;
	
	polinomio.calcularPolinomio(n, x);
}