// callback.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace std;

class Encryptor {
	int m_count;
public:
	
	Encryptor(int count) {
		m_count = count;
	}
	std::string operator()(std::string data) {
		for (int i = 0; i < data.size(); i++)
			if ((data[i] >= 'a' && data[i] <= 'z')
				|| (data[i] >= 'A' && data[i] <= 'Z'))
					data[i] = data[i] + m_count;
		return data;
	}

};

std::string buildCompleteMessage(std::string rawData, Encryptor encyptorFuncObj) {
	// Call the callBack provided i.e. function pointer to encrypt the
	rawData = encyptorFuncObj(rawData); //call to functor

	return rawData;
}

int main() {
	Encryptor obj1(1); //ctor call
	std::string msg = buildCompleteMessage("abcd", obj1);
	cout<< msg << std::endl;//bcde
	return 0;
}
