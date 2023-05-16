#include "Bms.h"
#include <fstream>
#include <windows.h>
#include <algorithm>



Bms::Bms()
{
    SignMenu();
}


Bms::~Bms()
{

}


void Bms::SignMenu()
{
    std::string userOption;

    std::system("cls");
    std::cout << "============================================" << std::endl;
    std::cout << "     ====[ Bank Management System ]====     " << std::endl;
    std::cout << "     ========::[ Sign  Menu ]::========     " << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << std::endl;
    std::cout << "======> Press [1] to Sign Up" << std::endl;
    std::cout << "======> Press [2] to Sign In" << std::endl;
    std::cout << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << std::endl;
    std::cout << "======> Option: ";
    std::getline(std::cin, userOption);
    std::transform(userOption.begin(), userOption.end(), userOption.begin(),::tolower);
    std::cout << std::endl;

    if (userOption == "1" || userOption == "signup" || userOption == "sign up")
    {
        SignUp();
    } else if (userOption == "2" || userOption == "signin" || userOption == "sign in")
    {
        SignIn();
    } else
    {
        std::cout << std::endl;
        std::cout << "============================================" << std::endl;
        std::cout << "============================================" << std::endl;
        std::cout << std::endl;
        std::cout << "======> ERROR: Choice not found, please check the input." << std::endl;
        std::cout << std::endl;
        std::cout << "======> After 5 seconds, the program will let you try again." << std::endl;
        Sleep(5000);
        SignMenu();
    }
}


void Bms::SignUp()
{
    std::string username, password;
    double balance{1000};

    std::system("cls");
    std::cout << "============================================" << std::endl;
    std::cout << "     ====[ Bank Management System ]====     " << std::endl;
    std::cout << "     =========::[ Sign  Up ]::=========     " << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "======> Enter 'back' to go back [Sign Menu]." << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << std::endl;
    std::cout << "======> Username: ";
    std::cin >> username;
    if (username == "back")
    {
        SignMenu();
    }
    std::cout << std::endl;
    std::cout << "======> Password: ";
    std::cin >> password;
    std::cout << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "============================================" << std::endl;

    std::string fileName(username + ".txt");
    std::fstream signUpFile;
    signUpFile.open(fileName, std::ios::out);
    if (signUpFile)
    {
        signUpFile << password << ">=" << balance;
        Username = username;
        Password = password;
        Balance = balance;
        std::cout << std::endl;
        std::cout << "======> SignUp successfully." << std::endl;
        std::cout << std::endl;
        std::cout << "======> After 5 seconds, the program will turn you to [Home Menu]." << std::endl;
        Sleep(5000);
        HomeMenu();
    } else
    {
        std::cout << std::endl;
        std::cout << "======> ERROR: Couldn't creating the account." << std::endl;
        std::cout << std::endl;
        std::cout << "======> After 5 seconds, the program will let you try again." << std::endl;
        Sleep(5000);
        SignUp();
    }
    signUpFile.close();
}


void Bms::SignIn()
{
    std::string username, password;

    std::system("cls");
    std::cout << "============================================" << std::endl;
    std::cout << "     ====[ Bank Management System ]====     " << std::endl;
    std::cout << "     =========::[ Sign  In ]::=========     " << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "======> Enter 'back' to go back [Sign Menu]." << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << std::endl;
    std::cout << "======> Username: ";
    std::cin >> username;
    if (username == "back")
    {
        SignMenu();
    }

    std::string fileName(username + ".txt");
    std::fstream signInFile;
    signInFile.open(fileName, std::ios::in);
    if (signInFile)
    {
        std::string dataInFile;
        signInFile >> dataInFile;

        std::cout << std::endl;
        std::cout << "======> Password: ";
        std::cin >> password;
        std::cout << std::endl;
        std::cout << "============================================" << std::endl;
        std::cout << "============================================" << std::endl;

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
            std::cout << std::endl;
            std::cout << "======> SignIn successfully." << std::endl;
            std::cout << std::endl;
            std::cout << "======> After 5 seconds, the program will turn you to [Home Menu]." << std::endl;
            Sleep(5000);
            HomeMenu();
        } else
        {
            std::cout << std::endl;
            std::cout << "======> ERROR: Incorrect password, please check the input." << std::endl;
            std::cout << std::endl;
            std::cout << "======> After 5 seconds, the program will let you try again." << std::endl;
            Sleep(5000);
            SignIn();
        }
    } else
    {
        std::cout << std::endl;
        std::cout << "============================================" << std::endl;
        std::cout << "============================================" << std::endl;
        std::cout << std::endl;
        std::cout << "======> ERROR: Username not found, please check the input." << std::endl;
        std::cout << std::endl;
        std::cout << "======> After 5 seconds, the program will let you try again." << std::endl;
        Sleep(5000);
        SignIn();
    }
    signInFile.close();
}


void Bms::HomeMenu()
{
    std::string userOption;

    std::system("cls");
    std::cout << "============================================" << std::endl;
    std::cout << "     ====[ Bank Management System ]====     " << std::endl;
    std::cout << "     ========::[ Home  Menu ]::========     " << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "======> [Welcome, " << Username << "]" << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "======> [Balance: $" << Balance << "]" << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << std::endl;
    std::cout << "======> Press [1] to Deposit Amount" << std::endl;
    std::cout << "======> Press [2] to Withdraw Amount" << std::endl;
    std::cout << "======> Press [3] to Account Information" << std::endl;
    std::cout << "======> Press [4] to Modify Account" << std::endl;
    std::cout << "======> Press [5] to Sign Out" << std::endl;
    std::cout << "======> Press [6] to EXIT" << std::endl;
    std::cout << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << std::endl;
    std::cout << "======> Option: ";
    std::cin >> userOption;
    std::transform(userOption.begin(), userOption.end(), userOption.begin(),::tolower);
    std::cout << std::endl;

    if (userOption == "1" || userOption == "deposit" || userOption == "deposit amount")
    {
        Deposit();
    } else if (userOption == "2" || userOption == "withdraw" || userOption == "withdraw amount")
    {
        Withdraw();
    } else if (userOption == "3" || userOption == "account" || userOption == "information" || userOption == "account information")
    {
        AccountInformation();
    } else if (userOption == "6" || userOption == "exit")
    {
        std::cout << "============================================" << std::endl;
        std::cout << "============================================" << std::endl;
        std::cout << std::endl;
        std::cout << "======> Good bye, " << Username << std::endl;
        std::exit(0);
    } else
    {
        std::cout << "============================================" << std::endl;
        std::cout << "============================================" << std::endl;
        std::cout << std::endl;
        std::cout << "======> ERROR: Choice not found, please check the input." << std::endl;
        std::cout << std::endl;
        std::cout << "======> After 5 seconds, the program will let you try again." << std::endl;
        Sleep(5000);
        HomeMenu();
    }
}


void Bms::Deposit()
{
    std::string amount;

    std::system("cls");
    std::cout << "============================================" << std::endl;
    std::cout << "     ====[ Bank Management System ]====     " << std::endl;
    std::cout << "     ===========::[Deposit]::==========     " << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "======> [Balance: $" << Balance << "]" << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "======> Enter 'back' to go back [Home Menu]." << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << std::endl;
    std::cout << "======> Amount: $";
    std::cin >> amount;
    std::transform(amount.begin(), amount.end(), amount.begin(),::tolower);
    if (amount == "back")
    {
        HomeMenu();
    }
    Balance += std::stod(amount);
    std::string newData(Password + ">=" + std::to_string(Balance));
    std::string fileName(Username + ".txt");
    std::ofstream userFile;
    userFile.open(fileName, std::ios::trunc);
    userFile << newData;
    userFile.close();
    std::cout << std::endl;
    std::cout << "======> Balance: $" << Balance << std::endl;
    std::cout << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << std::endl;
    std::cout << "======> After 5 seconds, the program will turn you to [Home Menu]." << std::endl;
    Sleep(5000);
    HomeMenu();
}


void Bms::Withdraw()
{
    std::string amount;

    std::system("cls");
    std::cout << "============================================" << std::endl;
    std::cout << "     ====[ Bank Management System ]====     " << std::endl;
    std::cout << "     ===========::[Withdraw]::==========     " << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "======> [Balance: $" << Balance << "]" << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "======> Enter 'back' to go back [Home Menu]." << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << std::endl;
    std::cout << "======> Amount: $";
    std::cin >> amount;
    std::transform(amount.begin(), amount.end(), amount.begin(),::tolower);
    if (amount == "back")
    {
        HomeMenu();
    }
    Balance -= std::stod(amount);
    std::string newData(Password + ">=" + std::to_string(Balance));
    std::string fileName(Username + ".txt");
    std::ofstream userFile;
    userFile.open(fileName, std::ios::trunc);
    userFile << newData;
    userFile.close();
    std::cout << std::endl;
    std::cout << "======> Balance: $" << Balance << std::endl;
    std::cout << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << std::endl;
    std::cout << "======> After 5 seconds, the program will turn you to [Home Menu]." << std::endl;
    Sleep(5000);
    HomeMenu();
}


void Bms::AccountInformation()
{
    std::string userOption;

    std::system("cls");
    std::cout << "============================================" << std::endl;
    std::cout << "     ====[ Bank Management System ]====     " << std::endl;
    std::cout << "     =========::[Information]::========     " << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "======> Username: @" << Username << std::endl;
    std::cout << "======> Password: " << Password << std::endl;
    std::cout << "======> Balance: $" << Balance << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "============================================" << std::endl;
    std::cout << "======> Enter any key to go back: ";
    std::cin >> userOption;
    std::cout << "============================================" << std::endl;
    std::cout << "======> After 3 seconds, the program will turn you to [Home Menu]." << std::endl;
    Sleep(3000);
    HomeMenu();
}


void Bms::ModifyAccount()
{

}
