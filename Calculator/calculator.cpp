/*
 * calculator.cpp
 *
 *  Created on: 12-Apr-2017
 *      Author: avadh
 */

#include<iostream>
#include<ctype.h>
#include "calculator.h"

using namespace std;

double Expression(string str);
double Number (string str);
double Term(string str);
double Factor(string str);

calculator::calculator() {
	// TODO Auto-generated constructor stub

}

calculator::~calculator() {
	// TODO Auto-generated destructor stub
}


int main()
{
	string str; // to read input expression

	cout<<"Expression ?";
	getline(cin,str);
	cout<<Expression(str);

//	while(str !=".")
//	{
//
//		if(str[str.length()-1]=='=')
//		{
//			getline(cin,str);
//			cout<<Expression(str);
//		}
//		else
//		{
//			cout<<"wrong format";
//		}
//	}



}

double Expression(string str)
{

	double value=Term(str);
	char c=str[0];

	cout<<"Expression:"<<str;

	switch (c) {

	case '+': {
		value = value + Term(str);
		return value;
	}

	case '-': {
		value = value - Term(str);
		return value;
	}

	default: {
		return value;
	}
	}

}
double Term(string str)
{

	double value=Factor(str);

	char c=str[0];

	cout<<"Term:"<<str;
	switch (c) {
	case '*': {
		value = value * Factor(str);
		return value;
	}

	case '/': {
		value = value / Factor(str);
		return value;
	}

	default: {
		return Factor(str);
	}

	}

}

double Factor(string str)
{
	int count=0;

	double value=Number(str);

	char c =str[0];

	cout<<"Factor:"<<str ;
	switch(c)
	{

	case '(':
	{
		count++;
		str=str.erase(0,1);
		//str=str.substr(1);
		value= Expression(str);
		break;
	}

	case ')' :
	{
		count--;
		str=str.substr(1);
		return value;
	}

	default :
	{
		return Number(str);
	}

	}

}
double Number (string str)
{
	string number;
	double value;

	while(str.length()>0)
	{
		char c=str[0];
		if(isdigit(c)==true)
		{
			number=number+c;
			str=str.erase(0,1);
			cout<<"number"<<number;
			cout<< "Number:"<<str ;
		}
		else
		{
			cout<< "Number:"<<str ;
			break;
		}


	}



	value=stod(number.c_str());

	return value;;
}


