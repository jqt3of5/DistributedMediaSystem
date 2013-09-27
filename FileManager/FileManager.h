#include "Track.h"
#include "Playlist.h"

#define ALL_TRACK_PLAYLIST "all_track_playlist"
class FileManager
{

 public:
  //Intialize functions
  FileManager(char *musicDir, char * playlistDir);
  void RefreshMusicDB();

  //Playlist functions
  char ** ListPlayLists();
  PlayList * LoadPlayList(char * name);
  bool AddToPlayList(char * name, Track tracks[], int numTracks);
  bool RMPlaylist(char * name);
  
 private:
  static PlayList * _activePlayList;
  char * musicRootDirectory;
  char * playListRootDirectory;

};
