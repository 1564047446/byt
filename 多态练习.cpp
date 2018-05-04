#include <iostream>

using namespace std;

class HashFunc {
public :
	virtual int operator() (const void *data) = 0;
	virtual ~HashFunc() {}
};

class HashTable {
public :
	HashTable (HashFunc &hc) : __hc(hc) {}
	int get_hash(const void *data) {
		return this->__hc(data);
	} 
private :
	HashFunc &__hc;
};

class Myhash : public HashFunc {
public :
	int operator() (const void *data) {
		const char *str = (const char *)(data);
		int hash_code = 0, seed = 131;
		while (*str) {
			hash_code += hash_code * seed + str[0];
			++str;
		}
		return hash_code & 0x7fffffff;
	}
};

int main() {
	Myhash func1;
	HashTable h1(func1);
	cout << h1.get_hash("baotongyu") << endl;
	cout << h1.get_hash("haizei") << endl;
	return 0;
}