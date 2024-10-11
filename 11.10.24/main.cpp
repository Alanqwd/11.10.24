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
			<< "������: " << height << " � ������\n";
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







class fetus {
public:

	fetus(const std::string& name, float weight)
		: name(name),
		weight(weight){}


	virtual void info() const {
		std::cout << "��������: " << name << "\n"
			<< "���: " << weight << " ��\n";
	}
protected:
	std::string name; 
	float weight;


};


class blueberries : public fetus {
public:

	blueberries(const std::string& name, float weight)
		: fetus(name,weight) {}


	void info() const override {
		fetus::info();
	}
};

class banana : public fetus{
public:

	banana(const std::string& name, float weight)
		: fetus(name,weight) {}


	void info() const override {
		fetus::info();
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
	The_shrub shrub("����", 1.5);
	Tree tree("������", 7);
	// ����� ���������� � ���������
	std::cout << "���������� � �����:\n";
	shrub.info();
	std::cout << "\n���������� � ������:\n";
	tree.info();
	blueberries bb("�������", 1);
	banana banana("�����", 5);
	// ����� ���������� � ���������
	std::cout << "���������� � �������:\n";
	bb.info();
	std::cout << "\n���������� � ������:\n";
	banana.info();

	return 0;
}