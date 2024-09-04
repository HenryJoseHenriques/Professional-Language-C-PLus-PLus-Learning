#include <iostream>
using namespace std;

struct colorScreen
{ // Struct de Cores do terminal
  string reset = "\x1b[0m";
  string bold = "\x1b[1m";
  string italic = "\x1b[3m";
  string underline = "\x1b[4m";
  string inverse = "\x1b[7m";
  string black = "\x1b[30m";
  string red = "\x1b[31m";
  string green = "\x1b[32m";
  string yellow = "\x1b[33m";
  string blue = "\x1b[34m";
  string magenta = "\x1b[35m";
  string cyan = "\x1b[36m";
  string white = "\x1b[37m";
  string gray = "\x1b[90m";
  string bright_red = "\x1b[91m";
  string bright_green = "\x1b[92m";
  string bright_yellow = "\x1b[93m";
  string bright_blue = "\x1b[94m";
  string bright_magenta = "\x1b[95m";
  string bright_cyan = "\x1b[96m";
  string bright_white = "\x1b[97m";
  string bg_black = "\x1b[40m";
  string bg_red = "\x1b[41m";
  string bg_green = "\x1b[42m";
  string bg_yellow = "\x1b[43m";
  string bg_blue = "\x1b[44m";
  string bg_magenta = "\x1b[45m";
  string bg_cyan = "\x1b[46m";
  string bg_white = "\x1b[47m";
  string bg_gray = "\x1b[100m";
  string bg_bright_red = "\x1b[101m";
  string bg_bright_green = "\x1b[102m";
  string bg_bright_yellow = "\x1b[103m";
  string bg_bright_blue = "\x1b[104m";
  string bg_bright_magenta = "\x1b[105m";
  string bg_bright_cyan = "\x1b[106m";
  string bg_bright_white = "\x1b[107m";
};

void clearScreen()
{
  system("cls"); // Comando para limpar a tela no Windows
}

void pauseScreen()
{
  system("pause"); // Pausa a tela no Windows
}