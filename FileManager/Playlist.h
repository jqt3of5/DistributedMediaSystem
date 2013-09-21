#include <vector>
#include "Track.h"

using namespace std;

struct Playlist
{
  vector<Track*> tracks;
  int numTracks;
  char * filePath;
  char * name;`
};
