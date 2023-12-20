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

	// ����������� ��� ����������
	Vehicle() {
		this->costVehicle = 0;
		this->typeVehicle = 0;
		string owner = "";
		this->costFuel = 0;
		this->fuelPerKM = 0;
	}

	// ����������� � �����������
	Vehicle(double costVehicle, int typeVehicle, string owner, double costFuel, double fuelPerKM) {
		this->costVehicle = costVehicle;
		this->typeVehicle = typeVehicle;
		this->owner = owner;
 		this->costFuel = costFuel;
		this->fuelPerKM = fuelPerKM;
	}

	// ����������� �����������
	Vehicle(const Vehicle& other) {
		this->costVehicle = other.costVehicle;
		this->typeVehicle = other.typeVehicle;
		this->owner = other.owner;
		this->costFuel = other.costFuel;
		this->fuelPerKM = other.fuelPerKM;
	}



	// ���������� = 
	Vehicle & operator = (const Vehicle& other) {
		this->costVehicle = other.costVehicle;
		this->typeVehicle = other.typeVehicle;
		this->owner = other.owner;
		this->costFuel = other.costFuel;
		this->fuelPerKM = other.fuelPerKM;
		return *this;
	}



	// ������ ��� ��������� �� (1 �������)
	double GetCostVehicle() const {
		return costVehicle;
	}

	// ������ ��� ���� �� (2 �������)
	int GetTypeVehicle() {
		return typeVehicle;
	}

	// ������ ��� ����������
	string GetOwner() {
		return owner;
	}

	// ������ ��� ���� �������
	double GetCostFuel() {
		return costFuel;
	}

	// ������ ��� ������� ������� �� ��
	double GetFuelPerKM() {
		return fuelPerKM;
	}



	// ������ ��� ��������� ��
	void SetCostVehicle(double cost) {
		costVehicle = cost;
	}

	// ������ ��� ���� ��
	void SetTypeVehicle(int type) {
		typeVehicle = type;
	}

	// ������ ��� ����������
	void SetOwner(string name) {
		owner = name;
	}

	// ������ ��� ���� �������
	void SetCostFuel(double cost) {
		costFuel = cost;
	}

	// ������ ��� ������� ������� �� ��
	void SetFuelPerKM(double fuel) {
		fuelPerKM = fuel;
	}
 


	// ����������, � ������� �� ��� �������
	~Vehicle() {}

};


// ���-�� �� ������� ��� n
void cheaperThanN(Vehicle* array, int arraySize, double n) {
	int temp = 0;
	for (int i = 0; i < arraySize; i++) {
		if (array[i].GetCostVehicle() < n) temp++;
	}
	cout << temp << " ������������ ������� ����� ������� " << n << ".";
}


// ���������� ����������� ��
void percentage(Vehicle* array, int arraySize) {
	double a, b, c, d;
	a = b = c = d = 0;
	for (int i = 0; i < arraySize; i++) {
		if (array[i].GetTypeVehicle() == 1) a++;
		else if (array[i].GetTypeVehicle() == 2) b++;
		else if (array[i].GetTypeVehicle() == 3) c++;
		else if (array[i].GetTypeVehicle() == 4) d++;
	}
	cout << a / arraySize * 100 << " % �� 1 ���� ���� ������������ �� ������ ���-�� ��." << endl;
	cout << b / arraySize * 100 << " % �� 2 ���� ���� ������������ �� ������ ���-�� ��." << endl;
	cout << c / arraySize * 100 << " % �� 3 ���� ���� ������������ �� ������ ���-�� ��." << endl;
	cout << d / arraySize * 100 << " % �� 4 ���� ���� ������������ �� ������ ���-�� ��." << endl;
}


// ������ �� ��� ����������� ����������
void listOfVelicles(Vehicle* array, int arraySize, string name) {
	bool flag = false;
	int temp = 1;
	for (int i = 0; i < arraySize; i++) {
		if (array[i].GetOwner() == name) {
			cout << "���������� �� " << temp << "-��� ������������� ��������:" << endl;
			cout << "���������: " << array[i].GetCostVehicle() << endl;
			cout << "��� ������������� ��������: " << array[i].GetTypeVehicle() << endl;
			cout << "���� �������: " << array[i].GetCostFuel() << endl;
			cout << "������ �� ��: " << array[i].GetFuelPerKM() << endl;
			cout << endl;
			temp++;
			flag = true;
		}
	}
	if (flag == false) {
		cout << "� ������ ������� ��� ������������ �������." << endl;
	}
	else {
		cout << "����� � ������ ������� " << temp - 1 << " ������������ �������." << endl;
	}
}


int main() {

	setlocale(LC_ALL, "ru");
	cout << "������� ���-�� ��������������� ������������ �������: ";
	int temp;
	cin >> temp;
	cout << endl;
	Vehicle * arrayVehicle = new Vehicle [temp];

	// ���� ������������ ���� ������ � ����������� ������ �� �������
	for (int i = 0; i < temp; i++) {

		double costVehicle;
		int typeVehicle;
		string owner;
		double costFuel;
		double fuelPerKM;

		cout << "������� ������ �� ������������� �������� ��� ������� " << i + 1 << ":" << endl;

		cout << "���������: ";
		cin >> costVehicle;

		cout << "��� ������������� ��������: ";
		cin >> typeVehicle;

		cout << "����������: ";
		cin >> owner;

		cout << "���� �������: ";
		cin >> costFuel;

		cout << "������ �� ��: ";
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