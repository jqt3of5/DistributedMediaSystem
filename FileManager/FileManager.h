#include "Track.h"
#include "Playlist.h"

#define ALL_TRACK_PLAYLIST "all_track_playlist"
class FileManager
{

 public:
  FileManager(char *musicDir, char * playlistDir);


  void RefreshMusicDB();
  PlayList * LoadPlayList(char * name);
  bool AddToPlayList(char * name, Track *tracks, int numTracks);
  bool RMPlaylist(char * name);
  
 private:
  PlayList * _activePlayLists;
  char * musicRootDirectory;
  char * playListRootDirectory;

};
