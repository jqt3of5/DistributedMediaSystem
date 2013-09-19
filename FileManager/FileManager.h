#include "Track.h"
#include "Playlist.h"

#define ALL_TRACK_PLAYLIST "all_track_playlist.m3u"
class FileManager
{

 public:
  FileManager(char *musicDir, char * playlistDir);
  void RefreshMusicDB();
  PlayList * LoadPlayListFromFile(char * filePath);
  char * CreatePlayList(char * name, Track* tracks, int numTracks);
  bool SavePlayListToFile(char * filePath);

 private:
  PlayList * _activePlayLists;
  char * musicRootDirectory;
  char * playListRootDirectory;

};
