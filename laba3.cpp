#include <iostream>
#include <math.h>
using namespace std;

class vesh_chisl{ // класс вещественное число
public:
	vesh_chisl(); // конструктор, который создает число 0
	vesh_chisl(double c); // конструктор, который создает число c
	double modul(); // модуль числа, будет показывать статический полиморфизм
	virtual void print(); // функция вывода на экран, будет показывать динамический полиморфизм
protected:
	double chislo; // число

};

vesh_chisl::vesh_chisl() {
	chislo = 0;
}

vesh_chisl::vesh_chisl(double c) {
	chislo = c;
}

double vesh_chisl::modul() {
	return abs(chislo);
}

void vesh_chisl::print() {
	cout << chislo << endl;
}


class complex_chisl : public vesh_chisl { // класс комплексное число - наследник класс вещественное число
public:
	complex_chisl(); // конструктор, который делает 0 вещественное число
	complex_chisl(double a, double b); // конструктор, который делает комплексное число с действительной частью a, и вещественной частью b
	double modul(); // модуль комплексного числа
	void print(); // вывод комплексного число в две строки: в первой строке действительная часть, во второй мнимая
protected:
	double mnim; // мнимое число
};

complex_chisl::complex_chisl() {
	vesh_chisl();
	mnim = 0;
};

complex_chisl::complex_chisl(double a, double b):
	vesh_chisl(a) 
	{
		mnim = b;
	}

double complex_chisl::modul() { // переопределение функции modul
	return pow(pow(mnim, 2) + pow(chislo, 2), 0.5);
};

void complex_chisl::print() { // переопределение функции print
	vesh_chisl::print();
	cout << mnim << endl;
};

int main()
{
	vesh_chisl* a = new complex_chisl(2, 3);
	a->print();
	cout << a->modul(); // выдаст 2, а по факту это значение равно 3.6...

	cout << endl << endl << endl;

	complex_chisl* b = new complex_chisl(5, 6);
	b->print();
	cout << b->modul() << endl;
}
