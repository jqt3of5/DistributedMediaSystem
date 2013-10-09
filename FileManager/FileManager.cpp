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

  return PlayList.LoadPlayListFromFile(filePath);
}

bool FileManager::AddToPlayList(char * name, Track *tracks[], int numTracks)
{
  int pathLen = strlen(playListRootDirectory) + strlen(name);
  char * filePath = calloc(sizeof(char), pathLen);
  strcpy(filePath, playListRootDirectory);
  strcat(filePath, name);

  return true;
}


