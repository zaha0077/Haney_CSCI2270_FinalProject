#ifndef JUKEBOX_H
#define JUKEBOX_H

struct Song{
    std::string title;
    std::string artist;
    Song* next = NULL;
    Song* prev = NULL;

    Song(){};

    Song(std::string _title, std::string _artist)
    {
      title = _title;
      artist = _artist;
    }

};

class Jukebox
{
    public:
    Jukebox();
    ~Jukebox();
    void addSong(std::string title, std::string artist);
    void deleteSong(std::string title);
    void findSong(std::string title);
    void printContents();
    void queueSong(std::string title);
	void playFirstQueue();
	void playFullQueue();
	void clearArchive();
	void clearQueue();
	void setDefault();
	
	
    protected:

    private:
    Song* searchSong(std::string title);
    int hashSum(std::string inTitle, int size);
    int tableSize = 10;
    Song* hashTable[10];
    std::queue<Song*> playList;
};

#endif // JUKEBOX_H

