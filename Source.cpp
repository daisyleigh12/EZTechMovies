/*
EZTechMovie Company customer and movie management software.
This software enables front-line employees to add, search, and delete customer records, and
to add, search, and delete movie records.  It connects to a central MySQL database to store records,
enable reporting, and provide scalable business functionality.
Some portions of the software are still under construction and will provide a message stating the function
is not yet available and return to the main menu.
*/
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct EZTechCustomer {
	string fname; string lname; string email; string phone; string birth_date; string start_date; string sub_ID; string sub_status;
	string pmt_method; string userID; string password; int customer_id;
} customerEntry[10]; //Dynamic array of strings for movie information;

void outputcustomer(EZTechCustomer customer);

struct EZTechMovie {
	string name; string cast; string rating; string description; string releaseyear; string genre;
} movieListEntry[10]; //Dynamic array of strings for movie information;

void outputmovie(EZTechMovie movies);

int main() {
	/*
	sql::mysql::MySQL_Driver* driver;
	sql::Connection* con;

	driver = sql::mysql::MySQL_Driver::get_mysql_driver_instance();
	con = driver->connect("tcp://mysql.earthcore.net:3306/eztechmovies", "eztech", "********");
	*/


	int menuOption = 0;

	cout << "--- EZTechMovie database management system --- \n";
	cout << "--- Please select the option from the following menu to proceed. --- \n";
	while (menuOption != 7) {
		cout << "1 - Add Customer" << endl <<
			"2 - Search Customer" << endl <<
			"3 - Delete Customer" << endl <<
			"4 - Add Movie" << endl <<
			"5 - Search Movie" << endl <<
			"6 - Delete Movie" << endl <<
			"7 - Quit" << endl <<
			"Enter the number of the menu item you want to access: ";
		cin >> menuOption; // receive input for menu selection
		cin.ignore(); //ignore trailing whitespace
		if (menuOption == 1 || menuOption == 4) {
			if (menuOption == 1) {
				// create variables for use in customer entry functions
				struct EZTechCustomer;
				bool addCustomer;
				string addMore = "yes";
				int n;

				cout << "--- EZTechMovie customer database entry system --- \n";
				addCustomer = true; // assign beginning value
				n = 0; // set counter to limit customer entry to the struct array to 0
				while (addCustomer == true && n < 10) {
					cout << "\n Enter first name: ";
					getline(cin, customerEntry[n].fname); // receive variable input for customer first name
					cout << "\n Enter last name: ";
					getline(cin, customerEntry[n].lname); // receive variable input for customer last name
					cout << "\n Enter customer email: ";
					getline(cin, customerEntry[n].email); // receive variable input for customer email
					cout << "\n Enter customer phone number: ";
					cin >> customerEntry[n].phone; // receive variable input for customer phone
					cout << "\n Enter customer birth date (MMDDYYYY): ";
					cin >> customerEntry[n].birth_date; // receive variable input for customer date of birth
					cout << "\n Enter start date (MMDDYYYY): ";
					cin >> customerEntry[n].start_date; // receive variable input for customer start date
					cout << "\n Enter payment method (card/echeck/PayPal): ";
					cin >> customerEntry[n].pmt_method; // receive input for payment method
					cout << "\n Enter subscription ID (Stream[1-3]/Ship[1-3]): ";
					cin >> customerEntry[n].sub_ID; // receive input for payment method
					cout << "\n Enter suscription status (active/inactive): ";
					cin >> customerEntry[n].sub_status; // receive input for payment method
					cout << "\n Enter customer user ID: ";
					cin >> customerEntry[n].userID; // receive input for payment method
					cout << "\n Enter customer password: ";
					cin >> customerEntry[n].password; // receive input for password
					outputcustomer(customerEntry[n]); // output current movie inputs as loaded to struct
					n++;
					if (n < 10) { // check that the counter limit is unmet before asking about additional entry
						cout << "Would you like to store additional customers?" << std::endl;
						cin >> addMore; // receive input whether to continue
						cin.ignore(); //ignore trailing whitespace
						if (addMore == "no" || addMore == "n" || addMore == "NO" || addMore == "No") {
							addCustomer = false;  //change variable to exit the loop
						}
					}
				}
			}
			if (menuOption == 4) {
				// create variables for use in movie entry functions
				struct EZTechMovie;
				bool addMovies;
				bool addCast;
				string addMore = "yes";
				string addMoreCast = "yes";
				string castMember;
				int j;
				int n;
				// int i;

				cout << "--- EZTechMovie movies database entry system --- \n";
				addMovies = true; // assign beginning value
				addCast = true; // assign beginning value
				n = 0; // set counter to limit movie entry to the struct array to 0
				while (addMovies == true && n < 10) {
					cout << "\n Enter title: ";
					getline(cin, movieListEntry[n].name); // receive variable input for movie name
					cout << "\n Enter up to four main cast members";
					j = 0; // set counter for limiting cast member entry to 0
					while (j < 4 && addCast == true) { // while loop to add up to four cast members
						cout << "\n Enter cast member first and last name : ";
						getline(cin, castMember); // receive variable input for movie cast
						if (j == 0) {
							movieListEntry[n].cast = castMember;
						}
						else {
							movieListEntry[n].cast = movieListEntry[n].cast + ", " + castMember;
						}
						j++;
						if (j < 4) { // check that the counter limit is unmet before asking about additional entry
							cout << "\n Enter another cast member? ";
							cin >> addMoreCast; // receive input whether to continue
							cin.ignore(); //ignore trailing whitespace
							if (addMoreCast == "no" || addMoreCast == "n" || addMoreCast == "NO" || addMoreCast == "No") {
								addCast = false;  //change variable to exit the loop
							}
						}
					}
					cout << "\n Enter description: ";
					getline(cin, movieListEntry[n].description); // receive variable input for movie description
					cout << "\n Enter rating: ";
					getline(cin, movieListEntry[n].rating); // receive variable input for movie rating
					cout << "\n Enter release year: ";
					cin >> movieListEntry[n].releaseyear; // receive input whether to continue
					cin.ignore(); //ignore trailing whitespace
					cout << "\n Enter genre: ";
					cin >> movieListEntry[n].genre; // receive input whether to continue
					cin.ignore(); //ignore trailing whitespace
					outputmovie(movieListEntry[n]); // output current movie inputs as loaded to struct
					n++;
					if (n < 10) { // check that the counter limit is unmet before asking about additional entry
						cout << "Would you like to store additional movies?" << std::endl;
						cin >> addMore; // receive input whether to continue
						cin.ignore(); //ignore trailing whitespace
						if (addMore == "no" || addMore == "n" || addMore == "NO" || addMore == "No") {
							addMovies = false;  //change variable to exit the loop
						}
					}
				}
			}
		}
		else {
			cout << "This option is not yet available, please select another option." << std::endl;
			cout << "Enter the number of the menu item you want to access:\n 1 - Add Customer \n  2 - Search Customer \n  3 - Delete Customer \n  4 - Add Movie \n   5 - Search Movie \n   6 - Delete Movie \n   7 - Quit \n ";
			cin >> menuOption; // receive input for menu selection
		}

	}
	return 0;
}

void outputcustomer(EZTechCustomer customer) {
	cout << "\n ---- " << endl << " You entered " << std::endl;
	cout << "Customer Name: " + customer.fname + " " + customer.lname << std::endl;
	cout << "Email:" + customer.email << std::endl;
	cout << "Phone: " + customer.phone << std::endl;
	cout << "Date of Birth: " + customer.birth_date << std::endl;
	cout << "Start Date: " + customer.start_date << std::endl;
	cout << "Payment Method: " + customer.pmt_method << std::endl;
	cout << "Subscription type: " + customer.sub_ID << endl << " ----" << std::endl;
	cout << "Subscription status: " + customer.sub_status << endl << " ----" << std::endl;
	cout << "User ID: " + customer.userID << endl << " ----" << std::endl;
	cout << "Password: " + customer.password << endl << " ----" << std::endl;
}

void outputmovie(EZTechMovie movies) {
	cout << "\n ---- " << endl << " You entered " << std::endl;
	cout << "Movie title: " + movies.name << std::endl;
	cout << "Main Cast:" << endl << " Cast members: " + movies.cast << std::endl;
	cout << "Description: " + movies.description << std::endl;
	cout << "Rating: " + movies.rating << std::endl;
	cout << "Year Released: " + movies.releaseyear << std::endl;
	cout << "Genre: " + movies.genre << endl << " ----" << std::endl;
}
