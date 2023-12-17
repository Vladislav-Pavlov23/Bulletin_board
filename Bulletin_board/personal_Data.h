#pragma once
#include <string>
#include "ASDInput.h"

class PersonalData {
private:
	std::string NameUser, PasswordUser, PhoneUser;
	bool Successful_Registr;
public:
	PersonalData() {
		Successful_Registr = true;
	}

	void createUser();														// (������� ������� ������)

	void loginUser();														// (���� � ������������ ������� ������)

	void logout();															// ����� � �������� � ������� ����

	bool checkForNumber(const std::string& phone);

	std::string getName() { return NameUser.empty() ? "-" : NameUser; }
};