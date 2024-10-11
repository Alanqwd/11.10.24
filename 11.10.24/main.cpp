#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>



// ����������� - ���������� ����������� ��������� ��������� ��� �������� ���������� ��������� ���� 
// ��� ����������� ������� ��������� ��������� �� ��� ��������� � ������������ ������ ���������� ����� ��������� ��� ������� ��������� � ������� �����������
//
//
//
  
// ��� ���� ����� ����������� ������� ������ ������������ ����������� ������� �����
class Base
{
public:
	Base() {
		std::cout << "Base construct\n";
	}
	virtual ~Base() {
		std::cout << "Base destroyed\n";
	}
		// �������� ����� virtual ������� ����������� ������� ����� � ��������� 
	virtual void PrintW() const { std::cout << "Hello world\n"; }


private:

};

class Derived:public Base{ 
public:    
	Derived() {
		std::cout << "Derived construct\n";
	}
	~Derived() {
		std::cout << "Derived destroyed\n";
	}
	void PrintW() const override { std::cout << "Hello world 2\n"; }


};
// ����������� �������� ������ ����� ������� � ��������� �� ������� � ���������� 


void Foo(Base &a)
{
	a.PrintW();
}

class Plant {
public:

	Plant(const std::string& name, const std::string& size, float height)
		: name(name), size(size), height(height) {}


	virtual void info() const {
		std::cout << "��������: " << name << "\n"
			<< "������: " << size << "\n"
			<< "������: " << height << " ������\n";
	}
protected:
	std::string name;
	std::string size;  
	float height;      


};


class The_shrub : public Plant {
public:

	The_shrub(const std::string& name, float height)
		: Plant(name, "���������", height) {}


	void info() const override {
		Plant::info();
	}
};

class Tree : public Plant {
public:

	Tree(const std::string& name, float height)
		: Plant(name, "�������", height) {}


	void info() const override {
		Plant::info();
	}
};


// ���� �������� �������  �� ��������� �� ���������� �������� upcast ������� �������� �� ��� �������� ��������� ������� � ������� ����� ������ �������� 
// �� �� ������ 
int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	/*Base * a= new Base;
	a->PrintW();
	Base * A = new Derived;
	A->PrintW();
	Foo(*a);
	Foo(*A);
	delete a;
	delete A;*/
	The_shrub shrub("����", 1.2);
	Tree tree("������", 5.5);
	// ����� ���������� � ���������
	std::cout << "���������� � �����:\n";
	shrub.info();
	std::cout << "\n���������� � ������:\n";
	tree.info();

	return 0;
}