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
float time_ = 0.0;
int NUM_THREADS = 0;
int a = 0;
int b = 0;
int c = 0;
int d = 0;
int e = 0;
int f = 0;
int g = 0;
int h = 0;
int i = 0;
int j = 0;
int k = 0;
int l = 0;
int m = 0;
int n = 0;
int o = 0;
int p = 0;
int q = 0;
int r = 0;
int s = 0;
int t = 0;
int u = 0;
int v = 0;
int w = 0;
int x = 0;
int y = 0;
int z = 0;

pthread_mutex_t aMutex;
pthread_mutex_t bMutex;
pthread_mutex_t cMutex;
pthread_mutex_t dMutex;
pthread_mutex_t eMutex;
pthread_mutex_t fMutex;
pthread_mutex_t gMutex;
pthread_mutex_t hMutex;
pthread_mutex_t iMutex;
pthread_mutex_t jMutex;
pthread_mutex_t kMutex;
pthread_mutex_t lMutex;
pthread_mutex_t mMutex;
pthread_mutex_t nMutex;
pthread_mutex_t oMutex;
pthread_mutex_t pMutex;
pthread_mutex_t qMutex;
pthread_mutex_t rMutex;
pthread_mutex_t sMutex;
pthread_mutex_t tMutex;
pthread_mutex_t uMutex;
pthread_mutex_t vMutex;
pthread_mutex_t wMutex;
pthread_mutex_t xMutex;
pthread_mutex_t yMutex;
pthread_mutex_t zMutex;

bool running = true;

void refreshScreen()
{
  while (running == true)
  {
    clear();

    // <code>

    printw("NUM_THREADS: %d\n", NUM_THREADS);
    printw("A/a: %d\n", a);
    printw("B/b: %d\n", b);
    printw("C/c: %d\n", c);
    printw("D/d: %d\n", d);
    printw("E/e: %d\n", e);
    printw("F/f: %d\n", f);
    printw("G/g: %d\n", g);
    printw("H/h: %d\n", h);
    printw("I/i: %d\n", i);
    printw("J/j: %d\n", j);
    printw("K/k: %d\n", k);
    printw("L/l: %d\n", l);
    printw("M/m: %d\n", m);
    printw("N/n: %d\n", n);
    printw("O/o: %d\n", o);
    printw("P/p: %d\n", p);
    printw("Q/q: %d\n", q);
    printw("R/r: %d\n", r);
    printw("S/s: %d\n", s);
    printw("T/t: %d\n", t);
    printw("U/u: %d\n", u);
    printw("V/v: %d\n", v);
    printw("W/w: %d\n", w);
    printw("X/x: %d\n", x);
    printw("Y/y: %d\n", y);
    printw("Z/z: %d\n", z);
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
  ifstream inFile;
  string *p = (string *)args;
  string file = *p;
  delete p;
  inFile.open(file.c_str());

  if (!inFile.is_open())
  {
    cout << "Unable to open " << file << endl;
    exit(1);
  }

  char vowel;
  while (inFile >> vowel)
  {
    switch ((char)std::tolower(vowel))
    {
    case 'a':
    {
      pthread_mutex_lock(&aMutex);
      a++;
      pthread_mutex_unlock(&aMutex);
      break;
    }
    case 'b':
    {
      pthread_mutex_lock(&bMutex);
      b++;
      pthread_mutex_unlock(&bMutex);
      break;
    }
    case 'c':
    {
      pthread_mutex_lock(&cMutex);
      c++;
      pthread_mutex_unlock(&cMutex);
      break;
    }
    case 'd':
    {
      pthread_mutex_lock(&dMutex);
      d++;
      pthread_mutex_unlock(&dMutex);
      break;
    }
    case 'e':
    {
      pthread_mutex_lock(&eMutex);
      e++;
      pthread_mutex_unlock(&eMutex);
      break;
    }
    case 'f':
    {
      pthread_mutex_lock(&fMutex);
      f++;
      pthread_mutex_unlock(&fMutex);
      break;
    }
    case 'g':
    {
      pthread_mutex_lock(&gMutex);
      g++;
      pthread_mutex_unlock(&gMutex);
      break;
    }
    case 'h':
    {
      pthread_mutex_lock(&hMutex);
      h++;
      pthread_mutex_unlock(&hMutex);
      break;
    }
    case 'i':
    {
      pthread_mutex_lock(&iMutex);
      i++;
      pthread_mutex_unlock(&iMutex);
      break;
    }
    case 'j':
    {
      pthread_mutex_lock(&jMutex);
      j++;
      pthread_mutex_unlock(&jMutex);
      break;
    }
    case 'k':
    {
      pthread_mutex_lock(&kMutex);
      k++;
      pthread_mutex_unlock(&kMutex);
      break;
    }
    case 'l':
    {
      pthread_mutex_lock(&lMutex);
      l++;
      pthread_mutex_unlock(&lMutex);
      break;
    }
    case 'm':
    {
      pthread_mutex_lock(&mMutex);
      m++;
      pthread_mutex_unlock(&mMutex);
      break;
    }
    case 'n':
    {
      pthread_mutex_lock(&nMutex);
      n++;
      pthread_mutex_unlock(&nMutex);
      break;
    }
    case 'o':
    {
      pthread_mutex_lock(&oMutex);
      o++;
      pthread_mutex_unlock(&oMutex);
      break;
    }
    case 'p':
    {
      pthread_mutex_lock(&pMutex);
      p++;
      pthread_mutex_unlock(&pMutex);
      break;
    }
    case 'q':
    {
      pthread_mutex_lock(&qMutex);
      q++;
      pthread_mutex_unlock(&qMutex);
      break;
    }
    case 'r':
    {
      pthread_mutex_lock(&rMutex);
      r++;
      pthread_mutex_unlock(&rMutex);
      break;
    }
    case 's':
    {
      pthread_mutex_lock(&sMutex);
      s++;
      pthread_mutex_unlock(&sMutex);
      break;
    }
    case 't':
    {
      pthread_mutex_lock(&tMutex);
      t++;
      pthread_mutex_unlock(&tMutex);
      break;
    }
    case 'u':
    {
      pthread_mutex_lock(&uMutex);
      u++;
      pthread_mutex_unlock(&uMutex);
      break;
    }
    case 'v':
    {
      pthread_mutex_lock(&vMutex);
      v++;
      pthread_mutex_unlock(&vMutex);
      break;
    }
    case 'w':
    {
      pthread_mutex_lock(&wMutex);
      w++;
      pthread_mutex_unlock(&wMutex);
      break;
    }
    case 'x':
    {
      pthread_mutex_lock(&xMutex);
      x++;
      pthread_mutex_unlock(&xMutex);
      break;
    }
    case 'y':
    {
      pthread_mutex_lock(&yMutex);
      y++;
      pthread_mutex_unlock(&yMutex);
      break;
    }
    case 'z':
    {
      pthread_mutex_lock(&zMutex);
      z++;
      pthread_mutex_unlock(&zMutex);
      break;
    }

    default:
      break;
    }
  }

  inFile.close();
  pthread_exit(NULL);
}

int main()
{
  stopwatch.start();

  NUM_THREADS = getTXTFilesNumber();
  pthread_t *thread = new pthread_t[NUM_THREADS];

  stringstream fileName;
  string *str_p = new string;
  pthread_mutex_init(&aMutex, 0);
  pthread_mutex_init(&bMutex, 0);
  pthread_mutex_init(&cMutex, 0);
  pthread_mutex_init(&dMutex, 0);
  pthread_mutex_init(&eMutex, 0);
  pthread_mutex_init(&fMutex, 0);
  pthread_mutex_init(&gMutex, 0);
  pthread_mutex_init(&hMutex, 0);
  pthread_mutex_init(&iMutex, 0);
  pthread_mutex_init(&jMutex, 0);
  pthread_mutex_init(&kMutex, 0);
  pthread_mutex_init(&lMutex, 0);
  pthread_mutex_init(&mMutex, 0);
  pthread_mutex_init(&nMutex, 0);
  pthread_mutex_init(&oMutex, 0);
  pthread_mutex_init(&pMutex, 0);
  pthread_mutex_init(&qMutex, 0);
  pthread_mutex_init(&rMutex, 0);
  pthread_mutex_init(&sMutex, 0);
  pthread_mutex_init(&tMutex, 0);
  pthread_mutex_init(&uMutex, 0);
  pthread_mutex_init(&vMutex, 0);
  pthread_mutex_init(&wMutex, 0);
  pthread_mutex_init(&xMutex, 0);
  pthread_mutex_init(&yMutex, 0);
  pthread_mutex_init(&zMutex, 0);

  // Initialize ncurses
  initscr();
  curs_set(0);

  // Start monitor
  std::thread monitor(refreshScreen);

  for (int n = 0; n < NUM_THREADS; n++)
  {
    fileName << n + 1 << ".txt";

    str_p = new string(fileName.str());
    if (pthread_create(&thread[n], NULL, vowelCount,
                       (void *)str_p))
    {
      cout << "Error with thread creation" << endl;
      return -1;
    }
    fileName.str("");
    fileName.clear();
  }

  for (int n = 0; n < NUM_THREADS; n++)
  {

    if (pthread_join(thread[n], NULL))
    {
      cout << "Error joining thread" << endl;
      return -1;
    }
  }

  running = false;

  pthread_mutex_destroy(&aMutex);
  pthread_mutex_destroy(&bMutex);
  pthread_mutex_destroy(&cMutex);
  pthread_mutex_destroy(&dMutex);
  pthread_mutex_destroy(&eMutex);
  pthread_mutex_destroy(&fMutex);
  pthread_mutex_destroy(&gMutex);
  pthread_mutex_destroy(&hMutex);
  pthread_mutex_destroy(&iMutex);
  pthread_mutex_destroy(&jMutex);
  pthread_mutex_destroy(&kMutex);
  pthread_mutex_destroy(&lMutex);
  pthread_mutex_destroy(&mMutex);
  pthread_mutex_destroy(&nMutex);
  pthread_mutex_destroy(&oMutex);
  pthread_mutex_destroy(&pMutex);
  pthread_mutex_destroy(&qMutex);
  pthread_mutex_destroy(&rMutex);
  pthread_mutex_destroy(&sMutex);
  pthread_mutex_destroy(&tMutex);
  pthread_mutex_destroy(&uMutex);
  pthread_mutex_destroy(&vMutex);
  pthread_mutex_destroy(&wMutex);
  pthread_mutex_destroy(&xMutex);
  pthread_mutex_destroy(&yMutex);
  pthread_mutex_destroy(&zMutex);

  // Stop monitor
  sleep(1);
  //running = false;
  monitor.join();

  // Close ncurses
  endwin();

  cout << "NUM_THREADS: " << NUM_THREADS << endl;
  cout << "A/a: " << a << endl;
  cout << "B/b: " << b << endl;
  cout << "C/c: " << c << endl;
  cout << "D/d: " << d << endl;
  cout << "E/e: " << e << endl;
  cout << "F/f: " << f << endl;
  cout << "G/g: " << g << endl;
  cout << "H/h: " << h << endl;
  cout << "I/i: " << i << endl;
  cout << "J/j: " << j << endl;
  cout << "K/k: " << k << endl;
  cout << "L/l: " << l << endl;
  cout << "M/m: " << m << endl;
  cout << "N/n: " << n << endl;
  cout << "O/o: " << o << endl;
  cout << "P/p: " << p << endl;
  cout << "Q/q: " << q << endl;
  cout << "R/r: " << r << endl;
  cout << "S/s: " << s << endl;
  cout << "T/t: " << t << endl;
  cout << "U/u: " << u << endl;
  cout << "V/v: " << v << endl;
  cout << "W/w: " << w << endl;
  cout << "X/x: " << x << endl;
  cout << "Y/y: " << y << endl;
  cout << "Z/z: " << z << endl;
  //cout << "Time: " << stopwatch.read() << endl;

  return 0;
}
