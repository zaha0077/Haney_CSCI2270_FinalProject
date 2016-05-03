# Haney_CSCI2270_FinalProject
-------------------------------------
Summary
-------------------------------------
This code emulates a "Jukebox." The code reads in a set of default song titles and artists from a .txt file and stores the values in a hash table of linked lists of structs. The code contains functionality to add songs to the archive, delete songs from the archive, search for a song in the archive, print the archive's contents, and add songs to a queue. Once a list of songs have been queued, the user can then tell the program to "play" the songs in the order they were queued, printing their title and artist. Alternatively, they may play them one at a time. The program also contains functions to clear the archive and playlist, as well as reset the program to its default state.

-------------------------------------
How to run:
-------------------------------------
In the terminal run "g++ -std=c++11 -c Jukebox.cpp" to produce a .o file.
Then run the line "g++ -std=c++11 Jukebox.o driver.cpp" to produce ./a.out.

You are now ready to run the program.

Executing ./a.out via the terminal will bring you to the Main Menu. On which there are several options to choose from:
  1. Add a song.
  2. Delete a song.
  3. Find a song.
  4. Print the contents of the song archive.
  5. Add a song to the playlist.
  6. Play the first song in said playlist.
  7. Play the entire playlist.
  8. Clear the archive and playlist.
  9. Clear only the playlist.
  10. Reset the program to its default state.
  11. Quit the program.

The options are selected by typing the appropriate number at the menu. For example, if one wanted to delete "Stayin' Alive" from the song list. They would input "2" and press return or enter. 

Detailed descriptions of the options are as follows:

Adding a song: 
Allows users to add their own song to the archive. When this option is selected, the user is prompted to input a song name and a song artist. And the program will then add that song to the archive. For instance, if one were to select 1, they could enter "Rock Lobster" as the title, and "B-52's" as the artist and the song will be added to the archive.  

Deleting a song: 
Allows a user to remove a song from the archive. The user is prompted for the title of the target song, and if that song exists, that song is removed from the archive completely. In order to prevent errors, the user is required to either play all the songs in or clear the playlist before deleting a song.

Finding a song: 
Prompts the user for a song title and then searches the archive for a matching song, outputting its title and artist if it exists. For instance, inputting "Megitsune" will output the song's title and artist as "Baby Metal", while an input of "Yes" will yield "Song 'Yes' not found." 

Printing the archive: 
Lists the entire contents of the hash table that stores all the songs. No user input is required.

Adding a song to the playlist:
The user is prompted for a song title. If that title exists, it is pushed into a queue.

Playing the first song in the playlist:
This will output the song in the front of the queue before removing it. Selecting this option repeatedly allows the user to go through the playlist one song at a time.

Playing the entire playlist:
Similar to the above option, except this one will output and empty the entire contents of the queue automatically.

Clearing the archive:
Selecting this option will wipe the hash table completely clean, allowing the user a blank slate to work with when building a new archive out of custom "songs." In order to prevent errors, this operation will clear the current contents of the playlist as well...

Clearing the playlist:
Selecting this option completely empties the playlist queue.

Resetting to default.
This will clear the playlist and reset the archive to the default list of songs included in defaultSongs.txt. Convenient for starting over without having to restart the program. Note that the afformentioned file is hard-coded into the program, and the program will not run properly without it. However if one wishes to change the default list, they can add or remove lines from the txt file as they wish. As long as there is at least one, non-blank, line of data present.

To end operation of this program, one must simply input "11" at the main menu.

-------------------------------------
Dependencies:
-------------------------------------
No third-party libraries were used in this program. This program should run with default C++ 11.

-------------------------------------
System Requirements:
-------------------------------------
This program was written on a Linux system, and will run best on Linux.

-------------------------------------
Group Members:
-------------------------------------
Zachary Haney

-------------------------------------
Contributors:
-------------------------------------
dingjunweng

-------------------------------------
Open Issues/Bugs:
-------------------------------------
None, currently.
