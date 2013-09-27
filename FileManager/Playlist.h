#include <vector>
#include "Track.h"

using namespace std;

class Playlist
{
  public:
  vector<Track*> tracks;
  int numTracks;
  char * filePath;
  char * name;
  
  static PlayList * LoadPlayListFromFile(char *fname);
  static bool SavePlayListToFile(PlayList *playList, char *fname);
  bool SavePlayListToFile(char *fname);
  bool AddTrack(Track *track);
  bool RemoveTrack(Track *track);
  bool RemoveTrack(char *name);
  
};
