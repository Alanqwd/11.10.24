#include <iostream>
#include <vector>
#include <string>

class Plant {
protected:
    std::string name;
    std::string size;  
    double height;

public:
    Plant(std::string n, std::string s, double h)
        : name(n), size(s), height(h) {}

    virtual void collectFruits() = 0;

    virtual ~Plant() = default; 
};

class Bush : public Plant {
public:
    Bush(std::string n, double h) : Plant(n, "Маленький", h) {}

    void collectFruits() override {
        std::cout << "Сбор ягод с куста: " << name << "\n";
    }
};

class Tree : public Plant {
private:
    int maxFruits; 
public:
    Tree(std::string n, double h, int maxFruits)
        : Plant(n, "Большой", h), maxFruits(maxFruits) {}

    void collectFruits() override {
        std::cout << "Сбор плодов с дерева: " << name << "\n";
        for (int i = 0; i < maxFruits; ++i) {
            if (i % 2 == 0) {
                std::cout << "Фрукт " << i + 1 << "\n";
            }
        }
    }

    std::vector<std::string> getFruits() {
        std::vector<std::string> fruits;
        for (int i = 0; i < maxFruits; ++i) {
            fruits.push_back("Фрукт " + std::to_string(i + 1));
        }
        return fruits;
    }
};


class Fruit {
protected:
    std::string name;
    double weight;

public:
    Fruit(std::string n, double w) : name(n), weight(w) {}
    virtual ~Fruit() = default;
};


class Berry : public Fruit {
public:
    Berry(std::string n, double w) : Fruit(n, w) {}
};

class FruitType : public Fruit {
public:
    FruitType(std::string n, double w) : Fruit(n, w) {}
};

class Cone : public Fruit {
public:
    Cone(std::string n, double w) : Fruit(n, w) {}
};

int main() {
    setlocale(LC_ALL, "ru");
    Bush myBush("Ягода", 1.5);
    myBush.collectFruits();

    Tree myTree("Дерево", 3.0, 5);
    myTree.collectFruits();

    // Получение плодов дерева
    auto fruits = myTree.getFruits();
    for (const auto& fruit : fruits) {
        std::cout << fruit << " Собирают с дерева" << "\n";
    }

    return 0;
}
