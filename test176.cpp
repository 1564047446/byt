#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

class Dog;
class Cat;

class Animal {
public :
	class Ivisitor {
		virtual void visitor(Cat *cat) = 0;
		virtual void visitor(Dog *dog) = 0;
	};
	Animal(string name) : name(name) {}
	virtual void say() = 0;
	virtual void Accept(Ivisitor *vis) = 0;
	virtual ~Animal();
private :
	string name;
	int age; 
};

class Cat : public Animal {
public :
	Cat() : Animal("cat") {}
	virtual void say() {
		cout << "I am a cat" << endl;
		return ;
	}
	virtual void Accept(Ivisitor *vis) {
		return vis->visitor(this);
	}
	~Cat();
};

class Dog : public Animal {
public :
	Dog() : Animal("dog") {}
	virtual void say() {
		cout << "I am a dog" << endl;
		return ;
	}
	virtual void Accept(Ivisitor *vis) {
		return vis->visitor(this);
	}
	~Dog();
};

class output : public Animal::Ivisitor {
public :
	virtual void visitor(Cat *cat) {
		cout << "miao miao miao" << endl;
	}
	virtual void visitor(Dog *dog) {
		cout << "wang wang wang" << endl;
	}
};

Cat *get_cat() {
	return new Cat;
}

Dog *get_dog() {
	return new Dog;
}

int main() {
	Animal *arr[10];
	Animal *(*func[2])() = {
		get_dog, get_cat
	}
	for (int i = 0; i < 10; i++) {
		int x = rand() % 2;
		arr[i] = func[x]();
	}
	for (int i = 0; i < 10; i++) {
		Ivisitor vis;
		arr[i].Accept(vis);
	}
	return 0;
}