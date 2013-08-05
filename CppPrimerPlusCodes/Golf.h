//  golf.h  ----    this file is for pe9-1

#ifndef __GOLF_H__
#define __GOLF_H__

const int LEN = 40; // there is another const global var LEN in Chapter7.h

struct golf {
    char fullname[LEN];
    int handicap;
};

//  set golf g to provided name, handicap
void setgolf(golf & g, const char * name, int hc);

//  functions solicits name and handicap from user
//  and sets g to the values entered.
//  return 1 if name is entered, 0 if name is empty string
int setgolf(golf & g);

void handicap(golf & g, int hc);
void showgolf(const golf & g);

#endif/*__GOLF_H__*/