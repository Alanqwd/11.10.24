#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>



// онкхлнптхгл - реумнкнцхъ хглемвхбнцн онбедемхъ опнцпюллш опх кхмеимни янупюмемхе ярпсйрспш йндю 
// опх онкхлнптмшу бшгнбюу опнцпюллю пюявхршюъ мю йнд нохяюммши б пндхрекэяйнл йкюяяе тюйрхвеяйх асдер бшонкмърэ йнд лернднб нохяюммшу б йкюяяюу мюякедмхйюу
//
//
//
  
// дкъ рнцн врнаш онкхлнптхгл пюанрюк днкфмю ясыеярбнбюрэ бхпрсюкэмюъ рюакхжю рхонб
class Base
{
public:
	Base() {
		std::cout << "Base construct\n";
	}
	virtual ~Base() {
		std::cout << "Base destroyed\n";
	}
		// йкчвебне якнбн virtual янгдюер бхпрсюкэмсч рюакхжс рхонб б опнцпюлле 
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
// онкхлнптмше бнглнфмш рнкэйн йнцдю назейрш б опнцпюлле он яяшкйюл х сйюгюрекъл 


void Foo(Base &a)
{
	a.PrintW();
}
class Plant {
public:

	Plant(const std::string& name, const std::string& size, float height)
		: name(name), size(size), height(height) {}


	virtual void info() const {
		std::cout << "мЮГБЮМХЕ: " << name << "\n"
			<< "пЮГЛЕП: " << size << "\n"
			<< "бШЯНРЮ: " << height << " Б ЛЕРПЮУ\n";
	}
protected:
	std::string name;
	std::string size;
	float height;


};


class The_shrub : public Plant {
public:

	The_shrub(const std::string& name, float height)
		: Plant(name, "лЮКЕМЭЙХИ", height) {}


	void info() const override {
		Plant::info();
	}
};

class Tree : public Plant {
public:

	Tree(const std::string& name, float height)
		: Plant(name, "аНКЭЬНИ", height) {}


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
		std::cout << "мЮГБЮМХЕ: " << name << "\n"
			<< "бЕЯ: " << weight << " ЙЦ\n";
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


// еякх оепедювю бедеряъ  он оюпюлерпс рн опнхяундхр ноепюжхъ upcast йнрнпюъ нряейюер нр бяе ябниярбю мюякедмшу йкюяянб х янгдюер мнбши назейр аюгнбнцн 
// мю ху нямнбе 
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
	The_shrub shrub("йСЯР", 1.5);
	Tree tree("дЕПЕБН", 7);
	// бШБНД ХМТНПЛЮЖХХ Н ПЮЯРЕМХЪУ
	std::cout << "хМТНПЛЮЖХЪ Н ЙСЯРЕ:\n";
	shrub.info();
	std::cout << "\nхМТНПЛЮЖХЪ Н ДЕПЕБЕ:\n";
	tree.info();
	blueberries bb("вЕПМХЙЮ", 1);
	banana banana("аЮМЮМ", 5);
	// бШБНД ХМТНПЛЮЖХХ Н ПЮЯРЕМХЪУ
	std::cout << "хМТНПЛЮЖХЪ Н ВЕПМХЙЕ:\n";
	bb.info();
	std::cout << "\nхМТНПЛЮЖХЪ Н АЮМЮМЕ:\n";
	banana.info();

	return 0;
}