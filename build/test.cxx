#include<iostream>

int main(){
	std::string str("this is a string");
	std::string substr1;
	std::string substr2;
	std::string substr3;
	std::string substr4;
	str>>substr1>>substr2>>substr3>>substr4;
	std::cout<<substr1<<" "<<substr2<<std::endl;
	return 0;
}
