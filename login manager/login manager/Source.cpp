#include<iostream>
#include<fstream>
#include<string>

using namespace std;

class loginManager 
{
public:
	loginManager()
	{
		accessGranted = 0;
	}
	void login()
	{
		system("CLS");
		cout << "Ahem your username is required !" << endl;
		cout << "username :";
		cin >> usernameAttempt;
	
		username = getFile("user.txt");

		if (username == usernameAttempt)
		{
			cout << "\npassword :";
			cin >> passwordAttempt;

			password = getFile("pswd.txt");
			if (password == passwordAttempt)
			{
				cout << " \n\ncongratulations you logged in successfully!" << endl;
				cin.get();
			}
			else
			{
				login();
			}
		}
		else
		{
			login();
		}
	}
    
	string getFile(const char* p_file)
	{
		string line;

		fstream file;
		file.open(p_file, ios::in);

		if (file.is_open())
		{
			getline(file, line);
		}
		return line;
   }
private:
	string username;
	string password;

	string usernameAttempt;
	string passwordAttempt;

	bool accessGranted;
};

int main()
{
	loginManager loginObj;

	loginObj.login();

	cin.get();
}