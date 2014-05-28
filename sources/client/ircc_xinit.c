
#include	"head_client.h"

int             ircc_xinit(void)
{
  if (initscr() == NULL)
    return (-1);
  noecho();
  cbreak();
  keypad(stdscr, true);
  curs_set(0);
  start_color();
  init_pair(1, COLOR_BLACK, COLOR_WHITE);
  init_pair(2, COLOR_WHITE, COLOR_GREEN);
  init_pair(3, COLOR_WHITE, COLOR_YELLOW);
  init_pair(4, COLOR_BLACK, COLOR_YELLOW);
  init_pair(5, COLOR_RED, COLOR_WHITE);
  init_pair(6, COLOR_GREEN, COLOR_WHITE);
  init_pair(7, COLOR_MAGENTA, COLOR_WHITE);
  wbkgd(stdscr, COLOR_PAIR(1));
  wrefresh(stdscr);
  return (0);
}
