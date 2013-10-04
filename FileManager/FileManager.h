#include "Track.h"
#include "Playlist.h"

#define ALL_TRACK_PLAYLIST "all_track_playlist"
class FileManager
{

  FileManager(char *musicDir, char * playlistDir);
  
 public:
  //Intialize functions
  static FileManager GetFileManager(char * music = null, char * playlist = null)
  {
    if (_fileManagerInstance == null)
    {
     if (music != null && playlist != null) // should check if these dirs exist
     {
      _fileManagerInstance = new FileManager(music, playlist); 
     }
     
    }
    
    return _fileManagerInstance;
  }
 
  void RefreshMusicDB();

  //Playlist functions
  char ** ListPlayLists();
  bool LoadPlayList(char * name, PlayList * playList);
  bool AddToPlayList(char * name, Track tracks[], int numTracks);
  bool RMPlaylist(char * name);
  
 private:
 
  static FileManager * _fileManagerInstance = null;
  PlayList * _activePlayList;
  char * musicRootDirectory;
  char * playListRootDirectory;

};
