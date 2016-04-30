#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include "Jukebox.h"

using namespace std;

int main(){
	Jukebox box;
	while(1==1){ //Main loop. Detailed documentation of each function can be found in Jukebox.cpp
		int choice = 0;
		cout << "======Main Menu======" << endl;
		cout << "1. Add Song." << endl;
		cout << "2. Delete Song." << endl;
		cout << "3. Find Song." << endl;
		cout << "4. Print Archive." << endl;
		cout << "5. Add song to playlist." << endl;
		cout << "6. Play first song in playlist." << endl;
		cout << "7. Play entire playlist." << endl;
		cout << "8. Clear the archive. (Will also clear playlist!)" << endl;
		cout << "9. Clear the playlist." << endl;
		cout << "10. Reset to default." << endl;
		cout << "11. Quit." << endl;
		
		cin >> choice;

		if (choice == 1){
			string inpt1;
			string inpt2;
			cout << "Enter Title: " << endl;
			cin.clear();
			cin.ignore(1000,'\n');
			getline(cin,inpt1);
			cout << "Enter Artist: " << endl;
			getline(cin,inpt2);

			box.addSong(inpt1,inpt2);
			}
		else if (choice == 2){
			string del;
			cout << "Enter Title: " << endl;
			cin.clear();
			cin.ignore(1000,'\n');
			getline(cin,del);
			box.deleteSong(del);
			}
		else if (choice == 3){
			string seek;
			cout << "Enter Title: " << endl;
			cin.clear();
			cin.ignore(1000,'\n');
			getline(cin,seek);
			box.findSong(seek);
			}
		else if (choice == 4){
			box.printContents();
			}
		else if (choice == 5){
			string addTrack;
			cout << "Enter Title: " << endl;
			cin.clear();
			cin.ignore(1000,'\n');
			getline(cin,addTrack);
			box.queueSong(addTrack);
			}
		else if (choice == 6){
			box.playFirstQueue();
			}
		else if (choice == 7){
			box.playFullQueue();
			}
		else if (choice == 8){
			box.clearArchive();
			}
		else if (choice == 9){
			box.clearQueue();
			}
		else if (choice == 10){
			box.setDefault();
			}
		else if (choice == 11){
			break;
			}
		else {
			cin.clear();
			cin.ignore(1000,'\n');
			}
		}				
		



	cout << "Goodbye!" << endl;
	return 0;
	}
