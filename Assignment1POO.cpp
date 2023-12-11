#include <iostream>

using namespace std;

class Product
{
	int id = -1;
	char* name = nullptr;
	char* description = nullptr;
	double price = 0.0;
	double* priceHistory = nullptr;
	int priceHistoryLen = 0;

public:
	Product(int id, const char* name, const char* description, double price, const double* priceHistory)
	{
		this->setId(id);
		this->setName(name);
		this->setDescription(description);
		this->setPrice(price);
		this->initPriceHistory(priceHistory, priceHistoryLen);
	}

	//all setters
	//....
	void setId(int id) {
		this->id = id;
	}

	void setName(const char* name) {

		if (this->name != nullptr) delete[] this->name;
		if (name == nullptr) {
			this->name == nullptr;
			return;
		}
		this->name = new char[strlen(name) + 1];
		strcpy_s(this->name, strlen(name) + 1, name);
	}

	void setDescription(const char* description) {

		if (this->description != nullptr) delete[] this->description;
		if (description == nullptr) {
			this->description == nullptr;
			return;
		}
		this->description = new char[strlen(description) + 1];
		strcpy_s(this->description, strlen(description) + 1, description);
	}

	void setPrice(double price) {
		double* pH = new double[this->priceHistoryLen + 1];
		for (int i = 0; i < this->priceHistoryLen; i++) {
			pH[i] = this->priceHistory[i];
		}
		pH[this->priceHistoryLen] = this->price;
		this->priceHistoryLen += 1;
		this->price = price;

		if (this->priceHistory != nullptr) delete[] this->priceHistory;
		this->priceHistory = pH;
	}

	void initPriceHistory(const double* priceHistory, int priceHistoryLen) {
		if (this->priceHistory != nullptr) {
			delete[] this->priceHistory;
		}
		if (priceHistory == nullptr) {
			this->priceHistory = nullptr;
			this->priceHistoryLen = 0;
			return;
		}
		this->priceHistoryLen = priceHistoryLen;
		this->priceHistory = new double[priceHistoryLen];
		for (int i = 0; i < priceHistoryLen; i++) {
			this->priceHistory[i] = priceHistory[i];
		}
	}

	//all getters
	//.....

	int getId() {
		return this->id;
	}

	char* getName() {
		char* retName = new char[strlen(this->name) + 1];
		strcpy_s(retName, strlen(this->name) + 1, this->name);
		return retName;
	}

	char* getDescription() {
		char* retDesc = new char[strlen(this->description) + 1];
		strcpy_s(retDesc, strlen(this->description) + 1, this->description);
		return retDesc;
	}

	double getPrice() {
		return this->price;
	}

	double* getPriceHistory() {
		double* retPriceHistory = new double[this->priceHistoryLen];
		for (int i = 0; i < this->priceHistoryLen; i++) {
			retPriceHistory[i] = this->priceHistory[i];
		}
		return retPriceHistory;
	}

	int getPriceHistoryLen() {
		return this->priceHistoryLen;
	}

	double getPriceAverage()
	{
		double avg = 0.0;
		for (int i = 0; i < this->priceHistoryLen; i++) {
			avg += this->priceHistory[i];
		}
		avg += this->price;
		avg = avg / (this->priceHistoryLen + 1);
		return avg;
	}

	void printPriceHistory() {
		for (int i = 0; i < this->priceHistoryLen; i++) {
			cout << this->priceHistory[i]<<" ";
		}
		cout << endl;
	}

	~Product()
	{

	}
};

int main() {
	cout << "hello world";
	return 0;
}