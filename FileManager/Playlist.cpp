#include "PlayList.h"

PlayList * PlayList::LoadPlayListFromFile(char * fname)
{
  FILE * playList = fopen(filePath, "r");
  if (playList == null)
    {
      return null;
    }

  PlayList * newPlayList = new PlayList();
  char * line = 0;

  getline(&line, 0, playList);
  d I 
  bool isExtendedM3U = !strcmp(line, "#EXTM3U");

  if (isExtendedM3U)
    {
      getline(&line, 0, playList);
    }
  static const boost::regex m3uExtExp("#EXTINF:([0-9]*),(.*) - (.*)");
  static const boost::regex fsExp("([^/]+)\.([^/]+)$");
  
  do {
    var track = new Track();
    if (isExtendedM3U)
      {
	//parse the extended info
	if (regex_match(line, m3uExtExp))
	  {
	    track.duration = atoi(match_results[1].str().c_str());
	      
	    track.artist = new char[match_results[2].str().length()];
	    strcpy(track.artist, match_results[2].str().c_str());

	    track.name = new char[match_results[3].str().length()];
	    strcpy(track.name, match_results[3].str().c_str());
	  }
	  
      }
    //'parse' the file path
    getline(&line, strlen(line), playList);
    track.filePath = calloc(sizeof(char), strlen(line));
    strcpy(track.filePath, line);
    if (!isExtendedM3U && regex_match(line, fsExp))
      {
	track.name = new char[match_result[1].str().length()];
	strcpy(track.name, match_result[1].str().c_str());
	strcpy(track.ext, match_result[2].str().c_str());
      }
    //add the track to the play list
    newPlayList.tracks.push_back(track);
  } while (getline(&line, strlen(line), playList) != -1)
    
  fclose(playList);
  return newPlayList;
}

bool PlayList::SavePlayListTofile(PlayList *playList, char * fname)
{
  FILE * fPlaylist = fopen(fname, "w");
  if (fPlaylist == null)
    {
      return false;
    }

  fprintf(fPlaylist, "#EXTM3U\n\n");
  for (int i = 0; i < playList->numTracks; ++i)
    {
      fprintf(fPlaylist, "#EXTINF:%d,%s - %s\n",playList->tracks[i].duration, playList->tracks[i].name, playList->tracks[i].artist);
      fprintf(fPlaylist, "%s\n\n", playList->tracks[i].fname);
    }

  fclose(fPlaylist);
  return true;
}

bool PlayList::AddTrack(Track * track)
{
  tracks.push_back(track);
  return true;
}
bool PlayList::RemoveTrack(Track* track)
{
  for (vector<Track>::iterator it=tracks.begin(); it!=tracks.end();it++)
    {
      if (*it == track)
	{
	  tracks.erase(it);
	  break;
	}
    }
}
bool PlayList::RemoveTrack(char *name)
{
  for (vector<Track>::iterator it=tracks.begin(); it!=tracks.end();it++)
    {
      if (!strcmp(it->name, name))
	{
	  tracks.erase(it);
	  break;
	}
    }
}
