#include <filesystem>
#include <fstream>
#include <ios>
#include <iostream>
#include <ncurses.h>
#include <pthread.h>
#include <sstream>
#include <string>
#include <thread>
#include <unistd.h>

float time_ = 0.0;
int NUM_THREADS = 0;
bool running = true;

static struct
{
  int a;
  int e;
  int i;
  int o;
  int u;
  int y;
} letter;

static struct
{
  pthread_mutex_t a;
  pthread_mutex_t e;
  pthread_mutex_t i;
  pthread_mutex_t o;
  pthread_mutex_t u;
  pthread_mutex_t y;
} mutex;



void refreshScreen()
{
  while (running)
  {
    clear();

    // <code>

    printw("NUM_THREADS: %d\n", NUM_THREADS);
    printw("A/a: %d\n", letter.a);
    printw("E/e: %d\n", letter.e);
    printw("I/i: %d\n", letter.i);
    printw("O/o: %d\n", letter.o);
    printw("U/u: %d\n", letter.u);
    printw("Y/y: %d\n", letter.y);
    time_ += 0.01;
    printw("Time: %.2f\n", time_);

    //</code>

    refresh();
    // Refresh every 0.1 s
    usleep(10000);
  }
}

void *vowelCount(void *args)
{
  std::ifstream inFile;
  std::string *p = (std::string *)args;
  std::string file = *p;
  delete p;
  inFile.open(file.c_str());

  if (!inFile.is_open())
  {
    std::cerr << "Unable to open " << file << std::endl;
    inFile.close();
    pthread_exit(NULL);
  }

  char vowel;
  while (inFile >> vowel)
  {
    switch ((char)std::tolower(vowel))
    {
    case 'a':
    {
      pthread_mutex_lock(&mutex.a);
      letter.a++;
      pthread_mutex_unlock(&mutex.a);
      break;
    }
    case 'e':
    {
      pthread_mutex_lock(&mutex.e);
      letter.e++;
      pthread_mutex_unlock(&mutex.e);
      break;
    }
    case 'i':
    {
      pthread_mutex_lock(&mutex.i);
      letter.i++;
      pthread_mutex_unlock(&mutex.i);
      break;
    }
    case 'o':
    {
      pthread_mutex_lock(&mutex.o);
      letter.o++;
      pthread_mutex_unlock(&mutex.o);
      break;
    }
    case 'u':
    {
      pthread_mutex_lock(&mutex.u);
      letter.u++;
      pthread_mutex_unlock(&mutex.u);
      break;
    }
    case 'y':
    {
      pthread_mutex_lock(&mutex.y);
      letter.y++;
      pthread_mutex_unlock(&mutex.y);
      break;
    }
    default:
      break;
    }
  }

  inFile.close();
  pthread_exit(NULL);
}

int count_by_extension(std::filesystem::path p, std::string extension)
{
  int n = 0;
  if(is_directory(p))
  {
    for(const std::filesystem::directory_entry& x : std::filesystem::directory_iterator{p})
    {
      const std::filesystem::path& f = x;
      if(f.extension() == extension)
      {
        n++;
      }
    }
  }
  return n;
}

int main(int argc, char const *argv[])
{
  std::ios_base::sync_with_stdio(false);

  if(not (NUM_THREADS = count_by_extension(".", ".txt")))
  {
    std::cerr << "Error: no files" << std::endl;
    std::terminate();
  }

  pthread_t *thread = new pthread_t[NUM_THREADS];

  std::stringstream fileName;
  std::string *str_p = new std::string;

  pthread_mutex_init(&mutex.a, 0);
  pthread_mutex_init(&mutex.e, 0);
  pthread_mutex_init(&mutex.i, 0);
  pthread_mutex_init(&mutex.o, 0);
  pthread_mutex_init(&mutex.u, 0);
  pthread_mutex_init(&mutex.y, 0);

  // Initialize ncurses
  initscr();
  curs_set(0);

  // Start monitor
  std::thread monitor(refreshScreen);

  for (int n = 0; n < NUM_THREADS; n++)
  {
    fileName << n + 1 << ".txt";

    str_p = new std::string(fileName.str());

    if (pthread_create(&thread[n], NULL, vowelCount, (void *)str_p))
    {
      std::cerr << "Error: thread creation" << std::endl;
      std::terminate();
    }

    fileName.str("");
  }

  for (int n = 0; n < NUM_THREADS; n++)
  {
    if (pthread_join(thread[n], NULL))
    {
      std::cerr << "Error: joining thread" << std::endl;
      std::terminate();
    }
  }

  running = false;

  printw("Press any key to exit\n");

  pthread_mutex_destroy(&mutex.a);
  pthread_mutex_destroy(&mutex.e);
  pthread_mutex_destroy(&mutex.i);
  pthread_mutex_destroy(&mutex.o);
  pthread_mutex_destroy(&mutex.u);
  pthread_mutex_destroy(&mutex.y);

  // Stop monitor
  sleep(1);

  monitor.join();

  getch();

  // Close ncurses
  endwin();

  return 0;
}
