// Bruno Ramos Jiménez A01701464


#include <iostream>
#include <string>
#include <sstream>
using namespace std;

// Clase Padre
// ===============================

class Bebida{
	public:
	
	void set_tamano(string tam);
	double get_precio();
	Bebida(string tama){
		tamano = tama;
	
	}
	Bebida(){}
	
	protected:
	string tamano = "pequeno";
	int precio;
	
};


void Bebida :: set_tamano(string tam){
	tamano = tam;
}

double Bebida :: get_precio(){
	return precio;
}
// Clase hijo
// ================================
class Cafe : public Bebida{
	public:
		int get_precio();
		Cafe(string temp, string tama): Bebida(tama){
			
			
			temperatura = temp;
		}
		Cafe(){}
		void set_temperatura(string t);
	protected:
		string temperatura;
		int precio_pequeno = 30;
		int precio_mediano = 45;
		int precio_grande = 60;
		
		
};

void Cafe :: set_temperatura(string t){
	temperatura = t;
}

// Prueba de la sub-clase Cafe
	// Cafe caf1;
	// caf1.set_tamano("pequeno") 
	// cout << caf1.get_precio() << endl; --> 30

int Cafe :: get_precio(){
	if (tamano == "pequeno"){
		if(temperatura == "caliente"){
			return precio_pequeno + 5;
		}
		return precio_pequeno;
	}
	else if (tamano == "mediano"){
		if(temperatura == "caliente"){
			return precio_mediano + 5;
		}
		return precio_mediano;
	}
	else if (tamano == "grande"){
		if(temperatura == "caliente"){
			return precio_grande + 5;
		}
		return precio_grande;
	} else {
		return 0;
	}
	
}
// Clase hijo
class Jugo : public Bebida{
	public:
		int get_precio();
		Jugo(string tama): Bebida(tama){}
		Jugo(){}
	protected:
		int precio_pequeno = 15;
		int precio_mediano = 30;
		int precio_grande = 40;
};

// Prueba de la subclase Jugo
	// Jugo jug1;
	// jug1.set_tamano("pequeno") 
	//cout << jug1.get_precio() << endl; --> 15

int Jugo :: get_precio(){
	if (tamano == "pequeno"){
		return precio_pequeno;
	}
	else if (tamano == "mediano"){
		return precio_mediano;
	}
	else if (tamano == "grande"){
		return precio_grande;
	} else {
		return 0;
	}
	
}
// La clase Bebida esta unida por composicion a esta clase
class Consumo{
	public:
		//void set_consumo_total(string elec);
		void set_cuenta();
		int get_consumo_total();
		Consumo(){}
		Consumo(Bebida beb);
	private:
		int consumo_total = 0;
		
};

// No quito esto de programa debido a que planeo utilizarlo más tarde. No me dio tiempo de hacer que 
// funcionara con la nueva versión del programa. 

//void Consumo :: set_consumo_total(string elec){
//	if (elec == "cafe"){
//		
//		cout << "Que tamano?" << endl;
//		string tamano;
//		cin >> tamano;
//		cout << "Que temperatura? (caliente/frio)" << endl;
//		string tempera;
//		cin >> tempera;
//		Cafe caf1(tempera, tamano);
//		consumo_total += caf1.get_precio();
//	}
//	else if (elec == "jugo"){
//		cout << "Que tamano?" << endl;
//		string tamano;
//		cin >> tamano;
//		Jugo jug1(tamano);
//		consumo_total += jug1.get_precio();
//	}
//}

// En esta parte se crea una lista para todos los objetos cafe que ordeno un cliente y otra lista para
// todos los objetos jugo
void Consumo :: set_cuenta(){
	cout << "Tipo de bebida" << endl;
	string bebi;
	cin >> bebi;
	if(bebi == "cafe"){
	cout << "ingrese el numero de cafes" << endl;
	int prd;
	cin >> prd;
	Cafe *s = new Cafe[prd];
	for(int i = 0; i < prd; i++){
		cout << "tamano (grande,mediano,pequeno)" << endl;
		string ele1;
		cin >> ele1;
		s[i].set_tamano(ele1);
		cout << "temperatura? (caliente/frio)" << endl;
		string ele2;
		cin >> ele2;
		s[i].set_temperatura(ele2);
		consumo_total += s[i].get_precio();
	}
	} else if(bebi == "jugo"){
	cout << "ingrese el numero de jugos" << endl;
	int prd1;
	cin >> prd1;
	Jugo *s = new Jugo[prd1];
	for(int i = 0; i < prd1; i++){
		cout << "tamano (grande,mediano,pequeno)" << endl;
		string ele2;
		cin >> ele2;
		s[i].set_tamano(ele2);
		consumo_total += s[i].get_precio();
	}
	}
	
}

int Consumo :: get_consumo_total(){
	return consumo_total;
}

class Cliente{
	public:
		Cliente(string nomb, string asie, Consumo con){
			nombre = nomb;
			asiento = asie;
			cons = con;
		}
		string get_nombre();
		string get_asiento();
	
	protected:
		string nombre;
		string asiento;
		Consumo cons;
};

string Cliente :: get_nombre(){
	return nombre;
}

string Cliente :: get_asiento(){
	return asiento;
}

// Prueba de la clase Cliente:
//Consumo con2;
//Cliente clien("Benjamon", "a2", con2);
//cout << clien.get_nombre();  ---> Benjamon

int main(){
	Consumo con1;
	
	Cliente cl("Bruno","A1",con1);
	
	bool bandera = true;
	while(bandera == true){
		
	
	con1.set_cuenta();
	cout << "Quieres el total?" << endl;
	string cuent;
	cin >> cuent;
	if (cuent == "si"){
		bandera = false;
	} else{
		bandera = true;
	}
	
	
	
	}
	cout << con1.get_consumo_total() << endl;
	// pedir dos cafes calientes, uno pequeno y uno grande da 100 de consumo
	
	// Prueba de la subclase Jugo
	// Jugo jug1;
	// jug1.set_tamano("pequeno") 
	//cout << jug1.get_precio() << endl; --> 15
	
	// Prueba de la sub-clase Cafe
	// Cafe caf1;
	// caf1.set_tamano("pequeno") 
	// cout << caf1.get_precio() << endl; --> 30
	
	
	return 0;
}
