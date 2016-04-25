#include <string>
#include <iostream>

using namespace std;

int main() {
	string myStr;
//	cout<<"Input string:";
//	getline(cin,myStr);
	myStr = "Hello world!";
	cout<<"The input is:"<<myStr<<endl;
	cout<<"Capicity:"<<myStr.capacity()<<endl;
	cout<<"Length:"<<myStr.length()<<endl;
	cout<<"Size:"<<myStr.size()<<endl;
	cout<<"Max Size:"<<myStr.max_size()<<endl;
	myStr+="I said that!";
	cout<<"The input is:"<<myStr<<endl;
	cout<<"Capicity:"<<myStr.capacity()<<endl;
	cout<<"Length:"<<myStr.length()<<endl;
	cout<<"Size:"<<myStr.size()<<endl;
	cout<<"c_str:"<<myStr.c_str()<<endl;
	char chars[20];
	int numCopied = myStr.copy(chars,12,15);
	cout<<"copy:"<<chars<<endl;
	cout<<"Chars copied:"<<numCopied<<endl;
	cout<<"data:"<<myStr.data()<<endl;
	float pi=3.14159;
	cout<<"PI:"<<std::to_string(pi)<<endl;
}