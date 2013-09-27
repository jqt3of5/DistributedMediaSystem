//enum MediaType { MP3, VORBIS }
struct Track
{
  char * name;
  char * artist;
  int duration;
  char * filePath;
  char ext[5];
  //  MediaType type;
  //  char * album;
  //  char * data;
  //  char * description;
  
  static bool LoadTrack(char * fname);
};
