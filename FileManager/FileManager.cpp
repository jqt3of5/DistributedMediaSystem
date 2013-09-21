#include <stdio.h>
#include <stdlib.h>
#include <boost/regex.hpp>
#include "FileManager.h"

FileManger::FileManager(char * musicDir, char * plsylistDir)
{
  //probably should copy these strings...
  musicRootDirectory = musicDir;
  playListRootDirectory = playlistDir;
}

void FileManager::RefreshMusicDB()
{
  //check for main playlist
  //if it exists, load it into _activePlayLists
  //if it doesn't, iterate through our root directory building the playlist
  
}

PlayList *  FileManager::LoadPlayList(char * name)
{
  int pathLen = strlen(playListRootDirectory) + strlen(name);
  char * filePath = calloc(sizeof(char), pathLen);
  strcpy(filePath, playListRootDirectory);
  strcat(filePath, name);

  FILE * playList = fopen(filePath, "r");
  PlayList * newPlayList = new PlayList();
  char * line = 0;

  getline(&line, 0, playList);
  
  bool isExtendedM3U = !strcmp(line, "#EXTM3U");

  if (isExtendedM3U)
    {
        getline(&line, 0, playList);
    }
  static const boost::regex m3uExtExp("#EXTINF:([0-9]*),(.*) - (.*)");
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
      track.name = calloc(sizeof(char), strlen(line));
      strcpy(track.name, line);

      //add the track to the play list
      newPlayList.tracks.push_back(track);
  } while (getline(&line, strlen(line), playList) != -1)
    
    fclose(playList);
    return newPlayList;
}

bool AddToPlayList(char * name, Track *tracks, int numTracks)
{
  int pathLen = strlen(playListRootDirectory) + strlen(name);
  char * filePath = calloc(sizeof(char), pathLen);
  strcpy(filePath, playListRootDirectory);
  strcat(filePath, name);

  FILE * playList = fopen(filePath, "a");

  
}


