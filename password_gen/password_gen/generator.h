#pragma once

#include <iostream>
#include <string>
#include <random>

class Generate_Password
{
public:
	void Password_Generates(int length = 8)
	{
		std::srand(std::time(nullptr));
		const std::string characters =
			"abcdefghijklmnopqrstuvwxyz"
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"0123456789"
			"!@#$%^&*()_+=-`|";
		std::string password;

		for (int i = 0; i < length; i++)
		{
			password += characters[std::rand() % characters.size()];
		}
		std::cout << password << '\n';
	}
};