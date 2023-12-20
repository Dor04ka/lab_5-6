#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Vehicle {

	double costVehicle;
	int typeVehicle;
	string owner;
	double costFuel;
	double fuelPerKM;

public:

	// конструктор без параметров
	Vehicle() {
		this->costVehicle = 0;
		this->typeVehicle = 0;
		string owner = "";
		this->costFuel = 0;
		this->fuelPerKM = 0;
	}

	// конструктор с параметрами
	Vehicle(double costVehicle, int typeVehicle, string owner, double costFuel, double fuelPerKM) {
		this->costVehicle = costVehicle;
		this->typeVehicle = typeVehicle;
		this->owner = owner;
 		this->costFuel = costFuel;
		this->fuelPerKM = fuelPerKM;
	}

	// конструктор копирования
	Vehicle(const Vehicle& other) {
		this->costVehicle = other.costVehicle;
		this->typeVehicle = other.typeVehicle;
		this->owner = other.owner;
		this->costFuel = other.costFuel;
		this->fuelPerKM = other.fuelPerKM;
	}



	// перегрузка = 
	Vehicle & operator = (const Vehicle& other) {
		this->costVehicle = other.costVehicle;
		this->typeVehicle = other.typeVehicle;
		this->owner = other.owner;
		this->costFuel = other.costFuel;
		this->fuelPerKM = other.fuelPerKM;
		return *this;
	}



	// геттер для стоимости ТП (1 функция)
	double GetCostVehicle() const {
		return costVehicle;
	}

	// геттер для типа ТП (2 функция)
	int GetTypeVehicle() {
		return typeVehicle;
	}

	// геттер для обладателя
	string GetOwner() {
		return owner;
	}

	// геттер для цены топлива
	double GetCostFuel() {
		return costFuel;
	}

	// геттер для расхода топлива на Км
	double GetFuelPerKM() {
		return fuelPerKM;
	}



	// сеттер для стоимости ТП
	void SetCostVehicle(double cost) {
		costVehicle = cost;
	}

	// сеттер для типа ТП
	void SetTypeVehicle(int type) {
		typeVehicle = type;
	}

	// сеттер для обладателя
	void SetOwner(string name) {
		owner = name;
	}

	// сеттер для цены топлива
	void SetCostFuel(double cost) {
		costFuel = cost;
	}

	// сеттер для расхода топлива на км
	void SetFuelPerKM(double fuel) {
		fuelPerKM = fuel;
	}
 


	// деструктор, в котором хз что удалять
	~Vehicle() {}

};


// кол-во ТП дешевле чем n
void cheaperThanN(Vehicle* array, int arraySize, double n) {
	int temp = 0;
	for (int i = 0; i < arraySize; i++) {
		if (array[i].GetCostVehicle() < n) temp++;
	}
	cout << temp << " транспортных средств стоят дешевле " << n << ".";
}


// процентное соотношение ТП
void percentage(Vehicle* array, int arraySize) {
	double a, b, c, d;
	a = b = c = d = 0;
	for (int i = 0; i < arraySize; i++) {
		if (array[i].GetTypeVehicle() == 1) a++;
		else if (array[i].GetTypeVehicle() == 2) b++;
		else if (array[i].GetTypeVehicle() == 3) c++;
		else if (array[i].GetTypeVehicle() == 4) d++;
	}
	cout << a / arraySize * 100 << " % ТП 1 типа было представлено от общего кол-ва ТП." << endl;
	cout << b / arraySize * 100 << " % ТП 2 типа было представлено от общего кол-ва ТП." << endl;
	cout << c / arraySize * 100 << " % ТП 3 типа было представлено от общего кол-ва ТП." << endl;
	cout << d / arraySize * 100 << " % ТП 4 типа было представлено от общего кол-ва ТП." << endl;
}


// список ТП для конкретного обладателя
void listOfVelicles(Vehicle* array, int arraySize, string name) {
	bool flag = false;
	int temp = 1;
	for (int i = 0; i < arraySize; i++) {
		if (array[i].GetOwner() == name) {
			cout << "Информация по " << temp << "-ому транспортному средству:" << endl;
			cout << "Стоимость: " << array[i].GetCostVehicle() << endl;
			cout << "Тип транспортного средства: " << array[i].GetTypeVehicle() << endl;
			cout << "Цена топлива: " << array[i].GetCostFuel() << endl;
			cout << "Расход на КМ: " << array[i].GetFuelPerKM() << endl;
			cout << endl;
			temp++;
			flag = true;
		}
	}
	if (flag == false) {
		cout << "У данной персоны нет транспортных средств." << endl;
	}
	else {
		cout << "Всего у данной персоны " << temp - 1 << " транспортных средств." << endl;
	}
}


int main() {

	setlocale(LC_ALL, "ru");
	cout << "Введите кол-во рассматриваемых транспортных средств: ";
	int temp;
	cin >> temp;
	cout << endl;
	Vehicle * arrayVehicle = new Vehicle [temp];

	// куча декоративных штук вместе с считыванием данных из консоли
	for (int i = 0; i < temp; i++) {

		double costVehicle;
		int typeVehicle;
		string owner;
		double costFuel;
		double fuelPerKM;

		cout << "Введите данные по транспортному средству под номером " << i + 1 << ":" << endl;

		cout << "Стоимость: ";
		cin >> costVehicle;

		cout << "Тип транспортного средства: ";
		cin >> typeVehicle;

		cout << "Обладатель: ";
		cin >> owner;

		cout << "Цена топлива: ";
		cin >> costFuel;

		cout << "Расход на КМ: ";
		cin >> fuelPerKM;
		cout << endl;

		Vehicle x(costVehicle, typeVehicle, owner, costFuel, fuelPerKM);
		arrayVehicle[i] = x;
	}

	//cheaperThanN(arrayVehicle, temp, 50);
	//percentage(arrayVehicle, temp);
	//listOfVelicles(arrayVehicle, temp, "bob");

	delete[] arrayVehicle;

}
