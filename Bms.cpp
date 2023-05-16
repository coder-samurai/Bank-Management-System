#include "Bms.h"
#include <fstream>
#include <windows.h>



Bms::Bms()
{
    SignMenu();
}


Bms::~Bms()
{

}


void Bms::SignMenu()
{
    std::string userOption, username, password;

    std::system("cls");
    std::cout << "============================================" << std::endl;
    std::cout << "     ====[ Bank Management System ]====     " << std::endl;
    std::cout << "     ========::[ Sign  Menu ]::========     " << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << std::endl;
    std::cout << "[/] Press [1] to Sign Up" << std::endl;
    std::cout << "[/] Press [2] to Sign In" << std::endl;
    std::cout << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << std::endl;
    std::cout << "[+] Option: ";
    std::getline(std::cin, userOption);
    std::cout << std::endl;

    if (userOption == "1" || userOption == "SignUp" || userOption == "Sign Up")
    {
        std::system("cls");
        std::cout << "============================================" << std::endl;
        std::cout << "     ====[ Bank Management System ]====     " << std::endl;
        std::cout << "     =========::[ Sign  Up ]::=========     " << std::endl;
        std::cout << "============================================" << std::endl;
        std::cout << std::endl;
        std::cout << "[+] Username: ";
        std::cin >> username;
        std::cout << std::endl;
        std::cout << "[+] Password: ";
        std::cin >> password;
        std::cout << std::endl;
        std::cout << "============================================" << std::endl;
        SignUp(username, password, 1000);
    } else if (userOption == "2" || userOption == "SignIn" || userOption == "Sign In")
    {
        std::system("cls");
        std::cout << "============================================" << std::endl;
        std::cout << "     ====[ Bank Management System ]====     " << std::endl;
        std::cout << "     =========::[ Sign  In ]::=========     " << std::endl;
        std::cout << "============================================" << std::endl;
        std::cout << std::endl;
        std::cout << "[+] Username: ";
        std::cin >> username;
        std::cout << std::endl;
        std::cout << "[+] Password: ";
        std::cin >> password;
        std::cout << std::endl;
        std::cout << "============================================" << std::endl;
        SignIn(username, password);
    } else
    {
        std::cout << "\n[!] ERROR: Choice not found, please check the input." << std::endl;
        Sleep(3000);
        SignMenu();
    }
}


void Bms::SignUp(std::string username, std::string password, double balance)
{
    std::string fileName(username + ".txt");

    std::fstream signUpFile;
    signUpFile.open(fileName, std::ios::out);
    if (signUpFile)
    {
        signUpFile << password << ">=" << balance;
        Username = username;
        Password = password;
        Balance = balance;
        std::cout << "\n[!] SignUp successfully." << std::endl;
    } else
    {
        std::cout << "\n[!] ERROR: Couldn't creating the account." << std::endl;
        Sleep(3000);
        SignMenu();
    }
    signUpFile.close();
}


void Bms::SignIn(std::string username, std::string password)
{
    std::string fileName(username + ".txt");

    std::fstream signInFile;
    signInFile.open(fileName, std::ios::in);
    if (signInFile)
    {
        std::string dataInFile;
        signInFile >> dataInFile;

        size_t pos = 0;
        std::string delimiter = ">=";
        std::string outputPassword;
        std::string outputBalance;
        while ((pos = dataInFile.find(delimiter)) != std::string::npos)
        {
            outputPassword = dataInFile.substr(0, pos);
            outputBalance = dataInFile.erase(0, pos + delimiter.length());
        }

        if (outputPassword == password)
        {
            Username = username;
            Password = password;
            Balance = std::stod(outputBalance);
            std::cout << "\n[!] SignIn successfully." << std::endl;
        } else
        {
            std::cout << "\n[!] ERROR: Incorrect password, please check the input." << std::endl;
        }
    } else
    {
        std::cout << "\n[!] ERROR: Username not found, please check the input." << std::endl;
    }
    signInFile.close();
}


void Bms::HomeMenu()
{
    std::cout << "============================================" << std::endl;
    std::cout << "     ====[ Bank Management System ]====     " << std::endl;
    std::cout << "     ========::[ Home  Menu ]::========     " << std::endl;
    std::cout << "============================================" << std::endl;
}


void Bms::GetAccountInformation()
{
    std::cout << "Username: " << Username << std::endl;
    std::cout << "Password: " << Password << std::endl;
    std::cout << "Balance: " << Balance << std::endl;
}