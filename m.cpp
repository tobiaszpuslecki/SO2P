#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <pthread.h>
#include "command.h"
#include "Stopwatch.h"

#include <thread>
#include <ncurses.h>
#include <unistd.h>

using namespace std;

Stopwatch stopwatch;
float time_=0.0;
int NUM_THREADS = 0;
int a = 0;
int e = 0;
int i = 0;
int o = 0;
int u = 0;
int y = 0;

pthread_mutex_t aMutex;
pthread_mutex_t eMutex;
pthread_mutex_t iMutex;
pthread_mutex_t oMutex;
pthread_mutex_t uMutex;
pthread_mutex_t yMutex;




bool running = true;

void refreshScreen()
{
    while(running == true)
    {
        clear();

        // <code>

        printw( "NUM_THREADS: %d\n", NUM_THREADS );
        printw( "A/a: %d\n", a );
        printw( "E/e: %d\n", e );
        printw( "I/i: %d\n", i );
        printw( "O/o: %d\n", o );
        printw( "U/u: %d\n", u );
        printw( "Y/y: %d\n", y );
        time_+=0.01;
        printw( "Time: %.2f\n", time_);

        //</code>

        refresh();
        // Refresh every 0.1 s
        usleep(10000);
    }
}



void * vowelCount(void *args) {
    ifstream inFile;
    string *p = (string *)args;
    string file = *p;
    delete p;
    inFile.open(file.c_str());

    if (!inFile){
      cout << "Unable to open " << file << endl;
      exit(1);
    }
    char vowel;
    while (inFile >> std::skipws >> vowel){
    	if (vowel == 'a' || vowel == 'A')
      {
        pthread_mutex_lock(&aMutex);
        a++;
        pthread_mutex_unlock(&aMutex);
      }
    	else if (vowel == 'e' || vowel == 'E')
      {
        pthread_mutex_lock(&eMutex);
    	  e++;
        pthread_mutex_unlock(&eMutex);
      }
      else if (vowel == 'i' || vowel == 'I')
      {
        pthread_mutex_lock(&iMutex);
        i++;
        pthread_mutex_unlock(&iMutex);
      }
      else if (vowel == 'o' || vowel == 'O')
      {
        pthread_mutex_lock(&oMutex);
        o++;
        pthread_mutex_unlock(&oMutex);
      }
      else if (vowel == 'u' || vowel == 'U')
      {
        pthread_mutex_lock(&uMutex);
        u++;
        pthread_mutex_unlock(&uMutex);
      }
      else if (vowel == 'y' || vowel == 'Y')
      {
        pthread_mutex_lock(&yMutex);
        y++;
        pthread_mutex_unlock(&yMutex);
      }
    }

    inFile.close();
    pthread_exit(NULL);
}

int main()
{
  stopwatch.start();

  NUM_THREADS = getTXTFilesNumber();
  pthread_t* thread = new pthread_t[NUM_THREADS];

  stringstream fileName;
  string *str_p = new string;
  pthread_mutex_init(&aMutex, 0);
  pthread_mutex_init(&eMutex, 0);
  pthread_mutex_init(&iMutex, 0);
  pthread_mutex_init(&oMutex, 0);
  pthread_mutex_init(&uMutex, 0);
  pthread_mutex_init(&yMutex, 0);



  // Initialize ncurses
  initscr();
  curs_set(0);

  // Start monitor
  std::thread monitor(refreshScreen);



  for (int n = 0; n < NUM_THREADS; n++)
  {
    fileName << n + 1 << ".txt";

    str_p = new string(fileName.str());
  	if(pthread_create(&thread[n], NULL, vowelCount,
  					  (void *)str_p)){
  	  cout << "Error with thread creation" << endl;
  	  return -1;
  	}
  	fileName.str("");
  	fileName.clear();
  }


  for (int n = 0; n < NUM_THREADS; n++){

  	if(pthread_join(thread[n], NULL)){
  	  cout << "Error joining thread" << endl;
  	  return -1;
  	}

  }

  running = false;


  pthread_mutex_destroy(&aMutex);
  pthread_mutex_destroy(&eMutex);
  pthread_mutex_destroy(&iMutex);
  pthread_mutex_destroy(&oMutex);
  pthread_mutex_destroy(&uMutex);
  pthread_mutex_destroy(&yMutex);



  // Stop monitor
  sleep(1);
  //running = false;
  monitor.join();

  int ttt;
  cin >> ttt;

  // Close ncurses
  endwin();

  cout << "NUM_THREADS: " << NUM_THREADS << endl;
  cout << "A/a: " << a << endl;
  cout << "E/e: " << e << endl;
  cout << "I/i: " << i << endl;
  cout << "O/o: " << o << endl;
  cout << "U/u: " << u << endl;
  cout << "Y/y: " << y << endl;
  //cout << "Time: " << stopwatch.read() << endl;

  return 0;




}
