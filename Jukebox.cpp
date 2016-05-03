#include <cstdlib>
#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <queue>
#include "Jukebox.h"

using namespace std;

//Constructor - Calls setDefault.
Jukebox::Jukebox(){
	for (int i = 0; i < tableSize; i++){ //set the hash table to null to prevent segfaults
		hashTable[i] = NULL;
		}
	setDefault();
	}

Jukebox::~Jukebox(){}
//---------------
//PUBLIC METHODS
//---------------
//Add a song to the archive.
void Jukebox::addSong(std::string title, std::string artist){
	int key = hashSum(title,tableSize);
	Song* newSong = new Song(title, artist);
	if (hashTable[key] == NULL){
		//cout << "ping" << endl;
		hashTable[key] = newSong;
		}
	else{
		Song* trace = hashTable[key];
		while (trace->next != NULL){ //add songs with identical hash values to existing songs to the end of the list at a given index.
			trace = trace->next;
			}
		trace->next = newSong;
		newSong->prev = trace;
		}
	}

//Delete a song from the archive.
void Jukebox::deleteSong(std::string title){
	bool found = 0; //Bool to check if the target song exists.
	int key = hashSum(title,tableSize);
	if (playList.empty()){ //Check if the playlist is empty to prevent errors.
		Song * seek = hashTable[key]; //Jump to the index of target song.
		if (seek!=NULL){
			while (seek!=NULL){ //search the list at that index for the song.
					if (title.compare(seek->title) == 0){
						if (seek->next != NULL){ //Cases where not at the end of the list.
							if (seek->prev != NULL){
								seek->prev->next = seek->next;
								seek->next->prev = seek->prev;
								}
							else{
								seek->next->prev = NULL;
								hashTable[key] = seek->next;
								}
							}
						else{ //Cases where at the end of the list
							if (seek->prev == NULL) hashTable[key] = NULL;
							else seek->prev->next = NULL;
							}
						found = 1;
						delete seek;
						cout << title << " deleted." << endl;
						break;
						}
					seek = seek->next;
					}
			
			
			}
		if (found == 0){ //If the target song was not found.
			cout << "Song '" << title << "' not found." << endl;
			}
		}
		else{ //if there is something in the playlist.
			cout << "Please clear or empty the playlist before attempting to delete a song from the archive." << endl;
			}
	}
	
//Find a song in the archive.
void Jukebox::findSong(std::string title){
	Song* finder = searchSong(title); //call to search function. Output will be based on what is returned.
	if (finder == NULL){
		cout << "Song '" << title << "' not found." << endl;
		}
	else{
		cout << "Title: " << finder->title << endl;
		cout << "Artist: " << finder->artist << endl;
		}
	}

//Print the contents of the archive.
void Jukebox::printContents(){
	bool isEmpty = 1;
	for(int i = 0; i < tableSize; i++){ //Loop through the archive and print contents.
		Song* trace = hashTable[i];
		//cout << "---" << endl << i << endl << "---" << endl; //Prints the hash indexes, used for debugging purposes only.
		while (trace != NULL){
			isEmpty = 0;
			cout << "Title: " << trace->title << endl;
			cout << "Artist: " << trace->artist << endl;
			cout << "-" << endl;
			trace = trace->next;
			}
		
		}
	
	if(isEmpty){
		cout << "Archive empty." << endl;
		}
	else{
		cout << "End of archive." << endl;
		}
	
	}


//Add a song to the playlist.
void Jukebox::queueSong(std::string title){ 
	Song* track = searchSong(title); //Search for the target song.
	if (track!=NULL){ //Queue it if it exists.
		playList.push(track);
		cout << "Queued." << endl;
		}
	else{
		cout << "Song '" << title << "' not found." << endl;
		}
	
	}

//"Play" the first song in the queue.
void Jukebox::playFirstQueue(){
	if (!playList.empty()){ //If the queue isn't empty, output the data and pop the queue.
		Song* temp = playList.front();
		cout << "Now playing: " << temp->title << " by " << temp->artist << endl;
		playList.pop();
		}
	else{ //send empty message if the queue is empty.
		cout << "Queue empty." << endl;
		}
	}

//"Play" the entire playlist.
void Jukebox::playFullQueue(){
	if (playList.empty()){ //Sends message if the queue is empty.
		cout << "Queue empty." << endl;
		}
	else
	while (!playList.empty()){ //If the queue isn't empty, output the data and pop the queue until it's empty.
		Song* temp = playList.front();
		cout << "Now playing: " << temp->title << " by " << temp->artist << endl;
		playList.pop();
		}
	
	}

//Clear the archive.
void Jukebox::clearArchive(){
	clearQueue();
	bool isEmpty = 1;
	for(int i = 0; i < tableSize; i++){ //Loop through the archive and delete
		Song* trace = hashTable[i];
		while (trace != NULL){
			isEmpty = 0;
			if (trace==hashTable[i]){
				trace = trace->next;
				hashTable[i] = NULL;
				}
			else{
				if (trace->next != NULL){
					trace = trace->next;
					delete trace->prev;
					}
				else{
					delete trace;
					trace = NULL;
					}
				}
			}
		
		}
	
	if(isEmpty){
		cout << "Archive empty." << endl;
		}
	else{
		cout << "Archive cleared." << endl;
		}
	
	
	}

//Clear the playlist.
void Jukebox::clearQueue(){
	cout << "Clearing playlist..." << endl;
	if (!playList.empty()){ //Clear the playlist if it's not empty.
		while(!playList.empty()){
			playList.pop();
			}
		cout << "Done." << endl;
		}
	else cout << "Queue already empty." << endl;
	}

//Reset the archive to default.
void Jukebox::setDefault(){
	bool notEmpty = 0;
	
	for (int i = 0; i < tableSize; i++){ //tests if the table is empty.
		if (hashTable[i] != NULL) notEmpty = 1; 
		}
	
	if (notEmpty){
		cout << "Clearing archive..." << endl;
		clearArchive(); //Clears the archive if table is not empty already.
		cout << "Resetting..." << endl;
		}
		
	ifstream inFile;
	inFile.open("defaultSongs.txt"); //Reads in default data from the txt file.
	if (inFile.good()){
		string stuff;
		string line;
		string nTitle;
		string nArtist;
		int counter = 0;
		stringstream ss;
		while (getline(inFile,line)){
			ss << line;
			while (getline(ss,stuff,',')){
				if (counter == 0){
					nTitle = stuff;
					}
				if (counter == 1){
					counter = -1;
					nArtist = stuff;
					addSong(nTitle,nArtist);
					}
				counter++;
				}
			ss.clear();
			}
		inFile.close();
		}
	else {
		cout << "ERROR: Unable to read defaultSongs.txt! File may be missing or failed to open.";
		}
	}

//-------------------
//PRIVATE METHODS
//-------------------

//Search the archive and return a song.
Song* Jukebox::searchSong(std::string title){
	bool found = 0;
	
	int key = hashSum(title,tableSize);
	Song* trace = hashTable[key];
	while (trace != NULL){ //Search linked lists if applicable.
		if (trace->title == title){
			found = 1;
			break;
			}
		else
			trace = trace->next;
		}
	if (found == 1) return trace;
	else return NULL; //Return NULL if not found.

	}
	
//Hash sum.
int Jukebox::hashSum(std::string inTitle, int size){
	int sum = 0;
    for (int i = 0; i < inTitle.length(); i++){
        sum+=inTitle[i];
    }
    sum = sum % size;
    return sum;
	
	
	}
